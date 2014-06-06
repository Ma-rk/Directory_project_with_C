#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

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

//1. 출력
//메모리에 linkedList 형태로 저장된 데이터를 화면에 출력함
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("출력할 데이터가 없습니다.");
		return;
	}
	do{
		currentMember = currentNode->member;
		printf("|   %7d   |%8s  |   %s     %s   \n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	printf("아무 키나 누르면 초기화면으로 이동합니다.");
	getch();//사용자가 아무 키나 누를 때까지 기다림
}


//2. 등록
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

	//신규회원 주소를 키보드로 입력받음
	printf(". 신규회원 주소: ");
	getMemberAddress(newAddress);

	//신규회원 전번을 키보드로 입력받음
	printf(". 신규회원 전화번호: ");
	int getMemberMobileResult = -1;
	while (getMemberMobileResult == -1){
		getMemberMobileResult = getMemberMobile(newMobileNumber);

		if (getMemberMobileResult == -1){
			printf("전화번호가 형식에 맞지 않습니다.\n");
			printf("숫자와 하이픈(-)만 사용해서 입력해야 합니다.\n");
			printf("전화번호를 다시 입력하세요.: ");
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

	printf("\n");
	printf("신규 회원정보가 입력되었습니다.\n");
	printf("입력하신 정보를 보존하려면 프로그램 종료 전에 저장해 주십시오.\n");
	printf("아무 키나 누르면 초기화면으로 이동합니다.\n");
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

//회원 이름을 입력받음(검색, 가입 등에 사용함)
void getMemberName(char * newName){
	fflush(stdin);
	gets_s(newName, NAME_LENGTH);
}

//회원 주소를 입력받음(검색, 가입 등에 사용함)
void getMemberAddress(char * newAddreaa){
	fflush(stdin);
	gets_s(newAddreaa, ADDRESS_LENGTH);
}

//회원 전화번호 입력받음(검색, 가입 등에 사용함)
//사용자가 입력한 전화번호를 newMobileNumber 변수에 저장함.
//올바른 전화번호를 입력했는지를 판단하여 결과를 리턴해줌.
int getMemberMobile(char * newMobileNumber){
	int getMemberMobileResult;

	fflush(stdin);
	fgets(newMobileNumber, MOBILE_LENGTH, stdin);

	int newMobileNumberLength = strlen(newMobileNumber) - 1;
	
	if (newMobileNumber[0] == 45 || newMobileNumber[newMobileNumberLength - 1] == 45){
		getMemberMobileResult = -1;//첫글자 또는 마지막 글자가 하이픈(-)이면 -1
	}
	else{
		for (int i = 0; i < strlen(newMobileNumber) - 1; i++){
			if (newMobileNumber[i] >= 48 && newMobileNumber[i] <= 57) {//숫자인지 아닌지 판별
				getMemberMobileResult = 1;
			}
			else{
				if (newMobileNumber[i] == 45){//하이픈(-)인지 아닌지 판별
					getMemberMobileResult = 1;
				}
				else{
					getMemberMobileResult = -1;//숫자도 하이픈도 아닌 문자가 하나라도 있으면 -1
					break;
				}
			}
		}
	}
	return getMemberMobileResult;
}

//4. 수정
void editMember(){

}

//5. 저장.
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
		fprintf(data, "%d\t%s\t%s\t%s\n"
			, currentMember->memID, currentMember->memName
			, currentMember->memAddress, currentMember->memMobileNumber);
		currentNode = currentNode->next;
	} while (currentNode);
	fclose(data);
	printf("모든 데이터를 하드디스크에 저장했습니다. 아무 키나 누르십시오.\n");
	getch();
}


//6. 검색
void searchMember(){

}