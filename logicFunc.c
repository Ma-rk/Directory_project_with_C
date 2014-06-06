#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

extern memberList members;
extern clearLineFromReadBuffer();

//��ũ���� ������ �о��
//linkedList ���·� �޸𸮿� ������
int loadMembers(){
	int memID;
	char memName[10];
	char memAddress[30];
	char memMobileNumber[20];

	FILE *fp;
	fp = fopen("data.txt", "rt");

	if (fp == NULL){
		puts("error\n");
		return -1;
	}
	while (!feof(fp)){

		member_t * member = (member_t *)malloc(sizeof(member_t));
		node_t * node = (node_t *)malloc(sizeof(node_t));

		fscanf(fp, "%d%s\t%[^\t]%s\n", &memID, memName, memAddress, memMobileNumber);

		member->memID = memID;
		strcpy(member->memName, memName);
		strcpy(member->memAddress, memAddress);
		strcpy(member->memMobileNumber, memMobileNumber);

		node->member = member;
		addMember(node);
	}
	fclose(fp);
	return 1;
}

//1. ���
//�޸𸮿� linkedList ���·� ����� �����͸� ȭ�鿡 �����
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("����� �����Ͱ� �����ϴ�.");
		return;
	}
	do{
		currentMember = currentNode->member;
		printf("|   %7d   |%8s  |   %s     %s   \n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	printf("�ƹ� Ű�� ������ �ʱ�ȭ������ �̵��մϴ�.");
	getch();//����ڰ� �ƹ� Ű�� ���� ������ ��ٸ�
}


//2. ���
//�ű� ȸ���� ������ �Է¹޴� �Լ����� ȣ���Ͽ� ���ϰ��� ����ü�� ��´�.
//�ű� ȸ���� ������ ��� ��带 linkedList�� �� �ڿ� add�Ѵ�.
void registerMember(){
	printf("�ű� ȸ���� ������ �Է��ϼ���.\n");

	//�ű� ���̵� �����ؿ�
	printf(". �ű� ���̵�: ");
	int newID = generateNewID();
	if (newID < 0){
		printf("\n\n�ű� ���̵� ������ �����߽��ϴ�.\n\n");
		return;
	}
	printf("%d\n", newID);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];

	//�ű�ȸ�� �̸��� Ű����� �Է¹���
	printf(". �ű�ȸ�� �̸�: ");
	getMemberName(newName);

	//�ű�ȸ�� �ּҸ� Ű����� �Է¹���
	printf(". �ű�ȸ�� �ּ�: ");
	getMemberAddress(newAddress);

	//�ű�ȸ�� ������ Ű����� �Է¹���
	printf(". �ű�ȸ�� ��ȭ��ȣ: ");
	int getMemberMobileResult = -1;
	while (getMemberMobileResult == -1){
		getMemberMobileResult = getMemberMobile(newMobileNumber);

		if (getMemberMobileResult == -1){
			printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			printf("���ڿ� ������(-)�� ����ؼ� �Է��ؾ� �մϴ�.\n");
			printf("��ȭ��ȣ�� �ٽ� �Է��ϼ���.: ");
		}
	}

	//�Է¹��� ������ ����ü�� ����
	member_t * newMember = (member_t *)malloc(sizeof(member_t));
	newMember->memID = newID;
	strcpy(newMember->memName, newName);
	strcpy(newMember->memAddress, newAddress);
	strcpy(newMember->memMobileNumber, newMobileNumber);

	//����ü�� ��忡 ����
	node_t * node = (node_t *)malloc(sizeof(node_t));
	node->member = newMember;

	//��带 linkedList �� �ڿ� add��
	addMember(node);

	printf("\n");
	printf("�ű� ȸ�������� �ԷµǾ����ϴ�.\n");
	printf("�Է��Ͻ� ������ �����Ϸ��� ���α׷� ���� ���� ������ �ֽʽÿ�.\n");
	printf("�ƹ� Ű�� ������ �ʱ�ȭ������ �̵��մϴ�.\n");
	getch();
}


int generateNewID(){
	int newID = -1;
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	do{
		if (newID < currentNode->member->memID){
			newID = currentNode->member->memID;
		}
		currentNode = currentNode->next;
	} while (currentNode->next != (node_t*)NULL);
	newID++;
	return newID;
}

//ȸ�� �̸��� �Է¹���(�˻�, ���� � �����)
void getMemberName(char * newName){
	fflush(stdin);
	gets_s(newName, NAME_LENGTH);
}

//ȸ�� �ּҸ� �Է¹���(�˻�, ���� � �����)
void getMemberAddress(char * newAddreaa){
	fflush(stdin);
	gets_s(newAddreaa, ADDRESS_LENGTH);
}

//ȸ�� ��ȭ��ȣ �Է¹���(�˻�, ���� � �����)
//����ڰ� �Է��� ��ȭ��ȣ�� newMobileNumber ������ ������.
//�ùٸ� ��ȭ��ȣ�� �Է��ߴ����� �Ǵ��Ͽ� ����� ��������.
int getMemberMobile(char * newMobileNumber){
	int getMemberMobileResult;

	fflush(stdin);
	fgets(newMobileNumber, MOBILE_LENGTH, stdin);

	int newMobileNumberLength = strlen(newMobileNumber) - 1;
	
	if (newMobileNumber[0] == 45 || newMobileNumber[newMobileNumberLength - 1] == 45){
		getMemberMobileResult = -1;//ù���� �Ǵ� ������ ���ڰ� ������(-)�̸� -1
	}
	else{
		for (int i = 0; i < strlen(newMobileNumber) - 1; i++){
			if (newMobileNumber[i] >= 48 && newMobileNumber[i] <= 57) {//�������� �ƴ��� �Ǻ�
				getMemberMobileResult = 1;
			}
			else{
				if (newMobileNumber[i] == 45){//������(-)���� �ƴ��� �Ǻ�
					getMemberMobileResult = 1;
				}
				else{
					getMemberMobileResult = -1;//���ڵ� �����µ� �ƴ� ���ڰ� �ϳ��� ������ -1
					break;
				}
			}
		}
	}
	return getMemberMobileResult;
}

//4. ����
void editMember(){

}

//5. ����.
void save(){
	FILE * data = fopen("data.txt", "wt");

	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("����� �����Ͱ� �����ϴ�.");
		return;
	}
	do{
		currentMember = currentNode->member;
		fprintf(data, "%d\t%s\t%s\t%s\n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	fclose(data);
	printf("��� �����͸� �ϵ��ũ�� �����߽��ϴ�. �ƹ� Ű�� �����ʽÿ�.\n");
	getch();
}


//6. �˻�
void searchMember(){

}