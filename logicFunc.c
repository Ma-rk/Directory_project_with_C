#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"
#define LEFT  75
#define UP    72
#define RIGHT 77
#define DOWN  80


extern memberList members;
extern clearLineFromReadBuffer();

//디스크에서 파일을 읽어와
//linkedList 형태로 메모리에 저장함
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

//메모리에 linkedList 형태로 저장된 데이터를 화면에 출력함
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;
	int static check = 19;
	int che = 0;
	int ch;
	if (members.head == NULL || members.tail == NULL){
		printf("출력할 데이터가 없습니다.");
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
		printf("← : 이전 페이지  →: 다음 페이지  ↓ : 메인으로 돌아가기              ");
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
					printf("회원정보의 마지막 페이지입니다.                                        ");
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
				printf("잘못 입력하셨습니다. ←, →, ↓ 중에 하나를 선택하세요.\b                 ");
				SetColor(15, 0);
			}
		}
	} while (currentNode);
	
}

//신규 회원의 정보를 입력받는 함수들을 호출하여 리턴값을 구조체에 담는다.
//신규 회원의 정보가 담긴 노드를 linkedList의 맨 뒤에 add한다.
void registerMember(){
	printf("신규 회원의 정보를 입력하세요.\n");

	//신규 아이디 생성해옴
	printf(". 신규 아이디: ");
	int newID = generateNewID();
	if (newID < 0){
		printf("\n\n신규 아이디 생성에 실패했습니다.\n\n");
		return;
	}
	printf("%d\n", newID);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];

	//신규회원 이름을 키보드로 입력받음
	printf(". 신규회원 이름: ");
	getMemberName(newName);
	printf("%s \n", newName);

	//신규회원 주소를 키보드로 입력받음
	printf(". 신규회원 주소: ");
	getMemberAddress(newAddress);
	//printf("%s \n", newAddress);

	//신규회원 전번을 키보드로 입력받음
	printf(". 신규회원 전화번호: ");
	int getMemberMobileResult = -1;
	//printf("%s \n", newMobileNumber);
	while (getMemberMobileResult == -1){
		if (getMemberMobile(newMobileNumber) == -1){
			printf("전화번호가 형식에 맞지 않습니다.\n");
			printf("숫자와 하이픈(-)만 사용해서 입력해야 합니다.\n");
			printf("전화번호를 다시 입력하세요.\n");
			getch();
		}
	}

	//입력받은 값들을 구조체에 넣음
	member_t * newMember = (member_t *)malloc(sizeof(member_t));
	newMember->memID = newID;
	strcpy(newMember->memName, newName);
	strcpy(newMember->memAddress, newAddress);
	strcpy(newMember->memMobileNumber, newMobileNumber);

	//구조체를 노드에 넣음
	node_t * node = (node_t *)malloc(sizeof(node_t));
	node->member = newMember;

	//노드를 linkedList 맨 뒤에 add함
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

//회원 이름을 입력받음(검색, 가입 등에 사용함)
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

//회원 주소를 입력받음(검색, 가입 등에 사용함)
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

//회원 전화번호 입력받음(검색, 가입 등에 사용함)
int getMemberMobile(char * newMobileNumber){
	char * newLinePosition;

	fflush(stdin);
	fgets(newMobileNumber, MOBILE_LENGTH, stdin);

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

//6. 저장.
void save(){
	FILE * data = fopen("data.txt", "wt");

	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("출력할 데이터가 없습니다.");
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
	printf("모든 데이터를 하드디스크에 저장했습니다. 아무 키나 누르십시오.\n");
	getch();
}
