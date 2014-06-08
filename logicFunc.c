#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"
#define LEFT  75
#define UP    72
#define RIGHT 77
#define DOWN  80


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

<<<<<<< HEAD
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
=======
//�޸𸮿� linkedList ���·� ����� �����͸� ȭ�鿡 �����
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;
	int static check = 19;
	int che = 0;
	int ch;
	if (members.head == NULL || members.tail == NULL){
		printf("����� �����Ͱ� �����ϴ�.");
		return;
	}

	do{
		system("cls");
		SetColor(10, 0);
		printf("=======================================================================\n");
		printf("|  Student ID |   Name   |   Phone number   |       Home address       \n");
		printf("=======================================================================\n");
		SetColor(15, 0);
		do{
			che++;
			currentMember = currentNode->member;
			currentNode = currentNode->next;

			printf("|   %7d   |%8s  |   %s  |   %s   \n", currentMember->memID, currentMember->memName,
				currentMember->memMobileNumber, currentMember->memAddress);

		} while (currentNode&&che % 20);
		printf("=======================================================================\n");
		SetColor(12, 15);
		printf("�� : ���� ������  ��: ���� ������  �� : �������� ���ư���              ");
		while (1)
		{
			ch = getch();
			if (ch == DOWN){
				return;
			}
			else if (ch == RIGHT){
				if (!currentNode){
					SetColor(12, 15);
					gotoxy(0, 25);
					printf("ȸ�������� ������ �������Դϴ�.                                        ");
					SetColor(12, 15);
					continue;
				}
				break;
			}
			else if (ch == LEFT){
				currentNode = members.head;
				che = 0;
				break;
			}
			else{
				gotoxy(0, 24);
				SetColor(12, 15);
				printf("�߸� �Է��ϼ̽��ϴ�. ��, ��, �� �߿� �ϳ��� �����ϼ���.\b                 ");
				SetColor(15, 0);
			}
		}
	} while (currentNode);
	
}

//�ű� ȸ���� ������ �Է¹޴� �Լ����� ȣ���Ͽ� ���ϰ��� ����ü�� ��´�.
//�ű� ȸ���� ������ ��� ��带 linkedList�� �� �ڿ� add�Ѵ�.
void registerMember(){
	printf("�ű� ȸ���� ������ �Է��ϼ���.\n");
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

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

<<<<<<< HEAD

	printf("����� �׸��� �����ϼ���.\n");
	printf("\n");
	printf("(ID�� ������ �� �����ϴ�)\n");
	printf("1. �̸�.\n");
	printf("2. �ּ�.\n");
	printf("3. ��ȭ��ȣ.\n");

=======
	//�ű�ȸ�� �̸��� Ű����� �Է¹���
	printf(". �ű�ȸ�� �̸�: ");
	getMemberName(newName);
	printf("%s \n", newName);

	//�ű�ȸ�� �ּҸ� Ű����� �Է¹���
	printf(". �ű�ȸ�� �ּ�: ");
	getMemberAddress(newAddress);
	//printf("%s \n", newAddress);

	//�ű�ȸ�� ������ Ű����� �Է¹���
	printf(". �ű�ȸ�� ��ȭ��ȣ: ");
	int getMemberMobileResult = -1;
	//printf("%s \n", newMobileNumber);
	while (getMemberMobileResult == -1){
		if (getMemberMobile(newMobileNumber) == -1){
			printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
			printf("���ڿ� ������(-)�� ����ؼ� �Է��ؾ� �մϴ�.\n");
			printf("��ȭ��ȣ�� �ٽ� �Է��ϼ���.\n");
			getch();
		}
	}
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

	fflush(stdin);
	scanf("%d", &selectedModifyItem);


<<<<<<< HEAD

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
=======
	//��带 linkedList �� �ڿ� add��
	addMember(node);
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780
}



<<<<<<< HEAD

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
=======
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
int getMemberMobile(char * newMobileNumber){
	char * newLinePosition;
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780


<<<<<<< HEAD
	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
	}

	//�˻��� ���� ������ ������ �޸𸮻��� ���� �˻������ free ��Ŵ
	freeList(&searchResult);//free �Ϸ��� list�� NULL���� �ƴ����� freeList �Լ� �ȿ��� üũ�ϹǷ� ������ ���� �ʾƵ� �ȴ�.
=======
	//if ((newLinePosition = strchr(newMobileNumber, '\n')) != NULL)
	//{
	//	*newLinePosition = '\0';
	//}
	//for (int i = 0; i < strlen(newMobileNumber)-1; i++){
	//	if (!(newMobileNumber[i] <= 48 && newMobileNumber[i] >= 57) || !(newMobileNumber[i] == 45)){
	//		return -1;
	//	}
	//}
	return 1;
}

//6. ����.
void save(){
	FILE * data = fopen("data.txt", "wt");
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

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
<<<<<<< HEAD

	if (!searchResult.head){
		printf("�˻������ �����ϴ�.\n");
	}
}


//void searchMember(int searchChoice, int searchKeywordNumber, char * searchKeywordString){}
=======
	do{
		currentMember = currentNode->member;
		fprintf(data,"%d\t%s\t%s\t%s\n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	fclose(data);
	printf("��� �����͸� �ϵ��ũ�� �����߽��ϴ�. �ƹ� Ű�� �����ʽÿ�.\n");
	getch();
}
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780
