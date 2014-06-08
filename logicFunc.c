#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

extern memberList members;
extern memberList searchResult; 

extern addNode(memberList * list, node_t * newNode);



//3. 삭제
void deleteMember(){
	int selectedSearchListIndex = 0;
	int selectedDelete = 0;

	callSearchMember();//회원 검색 실행
	if (searchResult.head == NULL){//검색결과가 없으면 종료
		getch();
		return;
	}
	printf("삭제할 회원을 선택하세요: ");
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

			printf("회원정보를 삭제했습니다. 변경사항을 보존하려면 저장을 하세요.\n");
			printf("계속하려면 아무키나 누르세요.\n");
			getch();

			return;
		}
	}
	printf("회원정보를 삭제하지 못했습니다. 선택한 정보가 존재하지 않습니다.\n");
	printf("계속하려면 아무키나 누르세요.\n");
	getch();
}


//4. 수정
void editMember(){
	int selectedSearchListIndex = 0;
	int selectedModifyItem = 0;

	callSearchMember();//회원 검색 실행
	if (searchResult.head == NULL){//검색결과가 없으면 종료
		getch();
		return;
	}

	printf("수정할 회원을 선택하세요: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];


	printf("변경된 항목을 선택하세요.\n");
	printf("\n");
	printf("(ID는 변경할 수 없습니다)\n");
	printf("1. 이름.\n");
	printf("2. 주소.\n");
	printf("3. 전화번호.\n");


	fflush(stdin);
	scanf("%d", &selectedModifyItem);



	node_t * currentNode = searchResult.head;
	while (currentNode){
		if (currentNode->index == selectedSearchListIndex){
			if (selectedModifyItem == 1){
				printf(". 새 회원 이름: ");
				getMemberName(newName);
				strcpy(currentNode->member->memName, newName);
			}
			else if (selectedModifyItem == 2){
				printf(". 새 회원 주소: ");
				getMemberAddress(newAddress);
				strcpy(currentNode->member->memAddress, newAddress);
			}
			else if (selectedModifyItem == 3){
				printf(". 새 회원 전화번호: ");
				getMemberMobile(newMobileNumber);
				strcpy(currentNode->member->memMobileNumber, newMobileNumber);
			}
			printf("회원정보를 수정했습니다. 변경사항을 보존하려면 저장을 하세요.\n");
			printf("계속하려면 아무키나 누르세요.\n");
			getch();
			
			return;
		}
	}
	
	printf("회원정보를 수정하지 못했습니다. 선택한 정보가 존재하지 않습니다.\n");
	printf("계속하려면 아무키나 누르세요.\n");
	getch();
}




//6. 검색
//검색을 위한 진입 함수.
void callSearchMember(){
	int searchChoice;
	char searchKeywordString[50];
	int searchKeywordNumber;
	int searchResultCount = 1;

	system("cls");

	gotoxy(1, 4);
	SetColor(16, 15);
	printf("<검색>");
	SetColor(15, 0);
	gotoxy(0, 8);
	printf("1. ID 검색\n");
	printf("2. 이름 검색\n");
	printf("3. 주소 검색\n");
	printf("4. 전화번호 검색\n");
	printf("무엇으로 검색하시겠습니까?");
	gotoxy(50, 20);
	SetColor(16, 15);
	SetColor(15, 0);
	gotoxy(51, 8);
	scanf("%d", &searchChoice);

	printf("\n");
	printf("\n");
	printf("검색하려는 값을 입력하세요:");


	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
	}

	//검색을 새로 실행할 때마다 메모리상의 이전 검색결과를 free 시킴
	freeList(&searchResult);//free 하려는 list가 NULL인지 아닌지는 freeList 함수 안에서 체크하므로 여기하 하지 않아도 된다.

	node_t * currentNode = members.head;

	if (searchChoice == 1){//ID 검색
		searchMemberByID(currentNode, searchKeywordNumber);
	}
	else if (searchChoice == 2){//이름 검색
		searchMemberByName(currentNode, searchKeywordString);
	}
	else if (searchChoice == 3){//주소 검색
		searchMemberByAddress(currentNode, searchKeywordString);
	}
	else if (searchChoice == 4){//전화번호 검색
		searchMemberByMobileNumber(currentNode, searchKeywordString);
	}

	if (!searchResult.head){
		printf("검색결과가 없습니다.\n");
	}
}


//void searchMember(int searchChoice, int searchKeywordNumber, char * searchKeywordString){}