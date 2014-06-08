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
=======
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
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

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

<<<<<<< HEAD

	printf("변경된 항목을 선택하세요.\n");
	printf("\n");
	printf("(ID는 변경할 수 없습니다)\n");
	printf("1. 이름.\n");
	printf("2. 주소.\n");
	printf("3. 전화번호.\n");

=======
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
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

	fflush(stdin);
	scanf("%d", &selectedModifyItem);


<<<<<<< HEAD

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
=======
	//노드를 linkedList 맨 뒤에 add함
	addMember(node);
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780
}



<<<<<<< HEAD

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
=======
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
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780


<<<<<<< HEAD
	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
	}

	//검색을 새로 실행할 때마다 메모리상의 이전 검색결과를 free 시킴
	freeList(&searchResult);//free 하려는 list가 NULL인지 아닌지는 freeList 함수 안에서 체크하므로 여기하 하지 않아도 된다.
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

//6. 저장.
void save(){
	FILE * data = fopen("data.txt", "wt");
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780

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
<<<<<<< HEAD

	if (!searchResult.head){
		printf("검색결과가 없습니다.\n");
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
	printf("모든 데이터를 하드디스크에 저장했습니다. 아무 키나 누르십시오.\n");
	getch();
}
>>>>>>> 5e227f12e662f8dc38c12c052a90521aca666780
