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

//���α׷� ����� �ϵ��ũ�κ��� �޸𸮷� ��� ����� �����͸� �ε���
int loadMembers();

//1. ȸ������ ��� ����� �޸��� ��� ����� �����͸� ȭ������ �����
void printMembers();

//2. ȸ����� ��� ����� ���� �޴��� �����ϰ� ��
//generateNewID();getMemberName();getMemberAddress();getMemberMobile(); �Լ��� �̿���
//�ű� ȸ���� ����� ������ �Է¹ް�, �Է��� �Ϸ�Ǹ� �޸𸮿� �����Ѵ�.
void registerMember();

//�ű� ȸ�� ���Խ� �ο����� ���̵� ����(���� �ִ� ��ȣ +1)
int generateNewID();

//ȸ�� �̸��� �Է¹���(�˻�, ���� � �����)
//������ �̸� �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
void getMemberName(char *);

//ȸ�� �ּҸ� �Է¹���(�˻�, ���� � �����)
//������ �ּ� �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
void getMemberAddress(char *);

//ȸ�� ��ȭ��ȣ �Է¹���(�˻�, ���� � �����)
//������ ��ȭ��ȣ �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
void getMemberMobile(char *);

//3. ȸ���˻� ��� ����� ���� �޴��� �����ϰ� ��
//getMemberName();getMemberAddress();getMemberMobile(); �Լ��� �̿���
//�˻��� ȸ�� ������ �Է¹ް�, �Է��� �Ϸ�Ǹ� �޸��� �����ͷκ��� �˻��� �����Ѵ�.
void searchMember();

//4. �������� ��� ����� ���� �޴��� �����ϰ� ��
//searchMember(); �Լ��� �̿��� ������ ȸ���� �˻��Ͽ� ������ ��
//������ ȸ���� ������ ������ �޸𸮿� �����Ѵ�.
void editMember();

//5. ȸ������ ��� ����� ���� �޴��� �����ϰ� ��
//searchMember(); �Լ��� �̿��� ������ ȸ���� �˻��Ͽ� ������ ��
//������ ȸ���� ������ �޸𸮿��� �����Ѵ�.
void deleteMember();

//6. ����.
//�޸��� ������ ��������� ������.
void save();


//����� ������ ��� node�� list�� �� �ڿ� add�Ѵ�.
void addMember(node_t * newNode);


//����� ������ ��� node�� list�� insert�Ѵ�.
void insertNode(list_t, node_t, memberList);

