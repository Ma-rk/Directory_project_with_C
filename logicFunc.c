#define _CRT_SECURE_NO_WARNINGS
#include "myTypes.h"

extern memberList members;
extern memberList searchResult; 

extern addNode(memberList * list, node_t * newNode);

//2. 등록
//신규 회원의 정보를 입력받는 함수들을 호출하여 리턴값을 구조체에 담는다.
//완성된 member 구조체를 node 구초체에 넣어 list에 담는다.
void callRegisterMember(){
	int action;
	member_t * newMember;

	SetColor(11, 0);
	printf("신규 회원의 정보를 입력하세요.\n");
	SetColor(2, 0);
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
	action = getMemberName(newName);
	if (action == 0) return;

	//신규회원 주소를 키보드로 입력받음
	printf(". 신규회원 주소: ");
	action = getMemberAddress(newAddress);
	if (action == 0) return;

	//신규회원 전번을 키보드로 입력받음
	printf(". 신규회원 전화번호: ");
	action = getMemberMobile(newMobileNumber);
	if (action == 0) return;


	//입력받은 값들을 구조체에 넣음
	newMember = (member_t *)malloc(sizeof(member_t));
	newMember->memID = newID;
	strcpy(newMember->memName, newName);
	strcpy(newMember->memAddress, newAddress);
	strcpy(newMember->memMobileNumber, newMobileNumber);

	//구조체를 노드에 넣음
	node_t * node = (node_t *)malloc(sizeof(node_t));
	node->member = newMember;

	//노드를 linkedList 맨 뒤에 add함
	registerMember(node);

	SetColor(11, 0);
	printf("\n");
	printf("신규 회원정보가 입력되었습니다.\n");
	printf("입력하신 정보를 보존하려면 프로그램 종료 전에 저장해 주십시오.\n");
	SetColor(3, 0);
	printf("아무 키나 누르면 초기화면으로 이동합니다.\n");
	getch();

}

//3. 검색
//검색을 위한 진입 함수.
//검색에 필요한 키워드를 사용자로부터 입력받는다.
//사용자가 원하는 항목을 검색하는 함수로 분기한다.
void callSearchMember(){
	char input[5];
	int searchChoice;
	char searchKeywordString[50];
	int searchKeywordNumber;
	int searchResultCount = 1;

	while (1){
		system("cls");

		gotoxy(10, 4);
		SetColor(16, 15);
		printf("< 검색 >");
		SetColor(10, 0);
		gotoxy(10, 8); printf("1. ID 검색");
		gotoxy(10, 9); printf("2. 이름 검색");
		gotoxy(10, 10); printf("3. 주소 검색");
		gotoxy(10, 11); printf("4. 전화번호 검색");
		gotoxy(10, 12); printf("5. 나가기");
		SetColor(8, 0);
		gotoxy(10, 14); printf("무엇으로 검색하시겠습니까? ");
		

		fgets(input, 5, stdin);
		searchChoice = atoi(input);

		if (searchChoice > 0 && searchChoice < 5)
			break;
		else if (searchChoice == 5){
			SetColor(3, 0);
			gotoxy(10, 16); printf("계속하려면 아무키나");
			return;
		}
		else{
			SetColor(3, 0);
			gotoxy(10, 16); printf("잘못된 입력입니다!");
			SetColor(15, 0);
		}
	}

	gotoxy(10, 16); printf("검색하려는 값을 입력하세요: ");
	SetColor(15, 0);

	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
		printf("\n");
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
		printf("\n");
	}

	//검색을 새로 실행할 때마다 메모리상의 이전 검색결과를 free 시킴
	freeList(&searchResult);//free 하려는 list가 NULL인지 아닌지는 freeList 함수 안에서 체크하므로 여기하 하지 않아도 된다.

	if (searchChoice == 1){//ID 검색
		searchMemberByID(searchKeywordNumber);
	}
	else if (searchChoice == 2){//이름 검색
		searchMemberByName(searchKeywordString);
	}
	else if (searchChoice == 3){//주소 검색
		searchMemberByAddress(searchKeywordString);
	}
	else if (searchChoice == 4){//전화번호 검색
		searchMemberByMobileNumber(searchKeywordString);
	}
	

	if (!searchResult.head){
		SetColor(3, 0);
		gotoxy(10, 18); printf("검색결과가 없습니다.");
		gotoxy(10, 19); printf("계속하려면 아무키나");
		SetColor(15, 0);
	}
}

//4. 수정
//수정을 위한 진입 함수.
//수정할 대상 회원을 정한다.
//수정할 항목을 고른다.
//새 값을 입력받는다.
//선택한 항목을 수정하는 함수로 분기한다.
void callEditMember(){
	int selectedSearchListIndex = 0;
	int selectedModifyItem = 0;

	callSearchMember();//회원 검색 실행
	if (searchResult.head == NULL){//검색결과가 없으면 종료
		getch();
		return;
	}

	SetColor(11, 0);
	printf("수정할 회원을 선택하세요: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];

	printf("변경할 항목을 선택하세요.\n");
	printf("\n");

	SetColor(14, 0);
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
				SetColor(10, 0);
				printf(". 새 회원 이름: ");
				getMemberName(newName);
				editMemberName(currentNode, newName);//이름 수정
			}
			else if (selectedModifyItem == 2){
				SetColor(10, 0);
				printf(". 새 회원 주소: ");
				getMemberAddress(newAddress);
				editMemberAddress(currentNode, newAddress);//주소 수정
			}
			else if (selectedModifyItem == 3){
				SetColor(10, 0);
				printf(". 새 회원 전화번호: ");
				getMemberMobile(newMobileNumber);
				editMemberMobileNumber(currentNode, newMobileNumber);//전화번호 수정
			}
			SetColor(3, 0);
			printf("회원정보를 수정했습니다. 변경사항을 보존하려면 저장을 하세요.\n");
			printf("계속하려면 아무키나 누르세요.\n");
			getch();
			
			return;
		}
		currentNode = currentNode->next;
	}
	
	SetColor(3, 0);
	printf("회원정보를 수정하지 못했습니다. 선택한 정보가 존재하지 않습니다.\n");
	printf("계속하려면 아무키나 누르세요.\n");
	getch();
}

//5. 삭제
//삭제를 위한 진입 함수.
//삭제할 대상 회원을 정한다.
//선택한 항목을 삭제하는 함수로 진입한다.
void callDeleteMember(){
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

			deleteMember(currentNode);//회원 삭제 실행
			//삭제 성공 여부는 어떻게 체크하면 좋은가??

			SetColor(3, 0);
			printf("회원정보를 삭제했습니다. 변경사항을 보존하려면 저장을 하세요.\n");
			printf("계속하려면 아무키나 누르세요.\n");
			getch();

			return;
		}
	}
	SetColor(3, 0);
	printf("회원정보를 삭제하지 못했습니다. 선택한 정보가 존재하지 않습니다.\n");
	printf("계속하려면 아무키나 누르세요.\n");
	getch();
}

