int showList();
void gotoxy(int x, int y);
void printPeople();
void SetColor(int color, int bgcolor);

#define NAME_LENGTH 20
#define ADDRESS_LENGTH 50
#define MOBILE_LENGTH 30

typedef struct member{
	int memID;
	char memName[NAME_LENGTH];
	char memAddress[50];
	char memMobileNumber[50];
} member_t;

typedef struct node{
	member_t * member;
	struct node * next;
} node_t;

typedef struct linkedList{
	node_t * head;
	node_t * tail;
} memberList;

//프로그램 실행시 하드디스크로부터 메모리로 모든 멤버의 데이터를 로드함
int loadMembers();

//1. 회원보기 기능 실행시 메모리의 모든 멤버의 데이터를 화면으로 출력함
void printMembers();

//2. 회원등록 기능 실행시 하위 메뉴로 진입하게 함
//generateNewID();getMemberName();getMemberAddress();getMemberMobile(); 함수를 이용해
//신규 회원이 사용할 정보를 입력받고, 입력이 완료되면 메모리에 저장한다.
void registerMember();

//신규 회원 가입시 부여해줄 아이디 생성(기존 최대 번호 +1)
int generateNewID();

//회원 이름을 입력받음(검색, 가입 등에 사용함)
//성공시 이름 포인터를 리턴, 실패 또는 취소시 -1 리턴
void getMemberName(char *);

//회원 주소를 입력받음(검색, 가입 등에 사용함)
//성공시 주소 포인터를 리턴, 실패 또는 취소시 -1 리턴
void getMemberAddress(char *);

//회원 전화번호 입력받음(검색, 가입 등에 사용함)
//성공시 전화번호 포인터를 리턴, 실패 또는 취소시 -1 리턴
void getMemberMobile(char *);

//3. 회원검색 기능 실행시 하위 메뉴로 진입하게 함
//getMemberName();getMemberAddress();getMemberMobile(); 함수를 이용해
//검색할 회원 정보를 입력받고, 입력이 완료되면 메모리의 데이터로부터 검색을 실행한다.
void searchMember();

//4. 정보수정 기능 실행시 하위 메뉴로 진입하게 함
//searchMember(); 함수를 이용해 수정할 회원을 검색하여 선택한 후
//선택한 회원의 정보를 수정해 메모리에 저장한다.
void editMember();

//5. 회원삭제 기능 실행시 하위 메뉴로 진입하게 함
//searchMember(); 함수를 이용해 수정할 회원을 검색하여 선택한 후
//선택한 회원의 정보를 메모리에서 제거한다.
void deleteMember();

//6. 저장.
//메모리의 정보에 변경사항을 저장함.
void save();


//사용자 정보가 담긴 node를 list의 맨 뒤에 add한다.
void addMember(node_t * newNode);


//사용자 정보가 담긴 node를 list에 insert한다.
void insertNode(list_t, node_t, memberList);

