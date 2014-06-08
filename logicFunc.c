#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

extern memberList members;
extern memberList searchResult; 

extern addNode(memberList * list, node_t * newNode);



//3. ����
void deleteMember(){
	int selectedSearchListIndex = 0;
	int selectedDelete = 0;

	callSearchMember();//ȸ�� �˻� ����
	if (searchResult.head == NULL){//�˻������ ������ ����
		getch();
		return;
	}
	printf("������ ȸ���� �����ϼ���: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	node_t * currentNode = searchResult.head;
	while (currentNode){
		if (currentNode->index == selectedSearchListIndex){

			if (members.head->member->memID == currentNode->member->memID){
				members.head = members.head->next;
			}
			else{
				node_t * prevNode = members.head;
				while (prevNode->next){
					if (prevNode->next->member->memID == currentNode->member->memID){
						prevNode->next = prevNode->next->next;
						break;
					}
					prevNode = prevNode->next;
				}
			}
			free(currentNode->member);
			free(currentNode);

			printf("ȸ�������� �����߽��ϴ�. ��������� �����Ϸ��� ������ �ϼ���.\n");
			printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
			getch();

			return;
		}
	}
	printf("ȸ�������� �������� ���߽��ϴ�. ������ ������ �������� �ʽ��ϴ�.\n");
	printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
	getch();
}


//4. ����
void editMember(){
	int selectedSearchListIndex = 0;
	int selectedModifyItem = 0;

	callSearchMember();//ȸ�� �˻� ����
	if (searchResult.head == NULL){//�˻������ ������ ����
		getch();
		return;
	}

	printf("������ ȸ���� �����ϼ���: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];


	printf("����� �׸��� �����ϼ���.\n");
	printf("\n");
	printf("(ID�� ������ �� �����ϴ�)\n");
	printf("1. �̸�.\n");
	printf("2. �ּ�.\n");
	printf("3. ��ȭ��ȣ.\n");


	fflush(stdin);
	scanf("%d", &selectedModifyItem);



	node_t * currentNode = searchResult.head;
	while (currentNode){
		if (currentNode->index == selectedSearchListIndex){
			if (selectedModifyItem == 1){
				printf(". �� ȸ�� �̸�: ");
				getMemberName(newName);
				strcpy(currentNode->member->memName, newName);
			}
			else if (selectedModifyItem == 2){
				printf(". �� ȸ�� �ּ�: ");
				getMemberAddress(newAddress);
				strcpy(currentNode->member->memAddress, newAddress);
			}
			else if (selectedModifyItem == 3){
				printf(". �� ȸ�� ��ȭ��ȣ: ");
				getMemberMobile(newMobileNumber);
				strcpy(currentNode->member->memMobileNumber, newMobileNumber);
			}
			printf("ȸ�������� �����߽��ϴ�. ��������� �����Ϸ��� ������ �ϼ���.\n");
			printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
			getch();
			
			return;
		}
	}
	
	printf("ȸ�������� �������� ���߽��ϴ�. ������ ������ �������� �ʽ��ϴ�.\n");
	printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
	getch();
}




//6. �˻�
//�˻��� ���� ���� �Լ�.
void callSearchMember(){
	int searchChoice;
	char searchKeywordString[50];
	int searchKeywordNumber;
	int searchResultCount = 1;

	system("cls");

	gotoxy(1, 4);
	SetColor(16, 15);
	printf("<�˻�>");
	SetColor(15, 0);
	gotoxy(0, 8);
	printf("1. ID �˻�\n");
	printf("2. �̸� �˻�\n");
	printf("3. �ּ� �˻�\n");
	printf("4. ��ȭ��ȣ �˻�\n");
	printf("�������� �˻��Ͻðڽ��ϱ�?");
	gotoxy(50, 20);
	SetColor(16, 15);
	SetColor(15, 0);
	gotoxy(51, 8);
	scanf("%d", &searchChoice);

	printf("\n");
	printf("\n");
	printf("�˻��Ϸ��� ���� �Է��ϼ���:");


	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
	}

	//�˻��� ���� ������ ������ �޸𸮻��� ���� �˻������ free ��Ŵ
	freeList(&searchResult);//free �Ϸ��� list�� NULL���� �ƴ����� freeList �Լ� �ȿ��� üũ�ϹǷ� ������ ���� �ʾƵ� �ȴ�.

	node_t * currentNode = members.head;

	if (searchChoice == 1){//ID �˻�
		searchMemberByID(currentNode, searchKeywordNumber);
	}
	else if (searchChoice == 2){//�̸� �˻�
		searchMemberByName(currentNode, searchKeywordString);
	}
	else if (searchChoice == 3){//�ּ� �˻�
		searchMemberByAddress(currentNode, searchKeywordString);
	}
	else if (searchChoice == 4){//��ȭ��ȣ �˻�
		searchMemberByMobileNumber(currentNode, searchKeywordString);
	}

	if (!searchResult.head){
		printf("�˻������ �����ϴ�.\n");
	}
}


//void searchMember(int searchChoice, int searchKeywordNumber, char * searchKeywordString){}