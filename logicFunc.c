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
	fp = fopen("data2.txt", "rt");

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
	printf("%s \n", newName);

	//�ű�ȸ�� �ּҸ� Ű����� �Է¹���
	printf(". �ű�ȸ�� �ּ�: ");
	getMemberAddress(newAddress);
	printf("%s \n", newAddress);

	//�ű�ȸ�� ������ Ű����� �Է¹���
	printf(". �ű�ȸ�� ��ȭ��ȣ: ");
	getMemberMobile(newMobileNumber);
	printf("%s \n", newMobileNumber);

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
	char * newLinePosition;

	//clearLineFromReadBuffer();
	//fgets(newName, NAME_LENGTH, stdin);
	fflush(stdin);
	gets_s(newName, NAME_LENGTH);
	//if ((newLinePosition = strchr(newName, '\n')) != NULL)
	//{
	//	*newLinePosition = '\0';
	//}
}

//ȸ�� �ּҸ� �Է¹���(�˻�, ���� � �����)
void getMemberAddress(char * newAddreaa){
	char * newLinePosition;

	//clearLineFromReadBuffer();
	fflush(stdin);
	gets_s(newAddreaa, ADDRESS_LENGTH);
	/*fgets(newAddreaa, ADDRESS_LENGTH, stdin);
	if ((newLinePosition = strchr(newAddreaa, '\n')) != NULL)
	{
		*newLinePosition = '\0';
	}*/
}

//ȸ�� ��ȭ��ȣ �Է¹���(�˻�, ���� � �����)
void getMemberMobile(char * newMobileNumber){
	char * newLinePosition;

	fflush(stdin);
	fgets(newMobileNumber, MOBILE_LENGTH, stdin);
	if ((newLinePosition = strchr(newMobileNumber, '\n')) != NULL)
	{
		*newLinePosition = '\0';
	}
}

//6. ����.
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
		fprintf(data,"%d\t%s\t%s\t%s\n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	fclose(data);
}
