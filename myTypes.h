#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

void showMenuList();
void gotoxy(int x, int y);
void printPeople();
void SetColor(int color, int bgcolor);

#define NAME_LENGTH 20
#define ADDRESS_LENGTH 50
#define MOBILE_LENGTH 30

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27


typedef struct member{
	int memID;
	char memName[NAME_LENGTH];
	char memAddress[ADDRESS_LENGTH];
	char memMobileNumber[MOBILE_LENGTH];
} member_t;

typedef struct node{
	int index;
	member_t * member;
	struct node * next;
} node_t;

typedef struct linkedList{
	node_t * head;
	node_t * tail;
} memberList;

/*
main func
*/
//0. ���α׷� ����
//�ϵ��ũ�κ��� �޸𸮷� ��� ����� �����͸� �ε���
int loadMembers();

//1. ȸ������
//�޸��� ��� ����� �����͸� ȭ������ �����
void printMembers();

//2-1. ȸ��������� ����
void callRegisterMember();
//2-2. ȸ����� ����
void registerMember();





//3. ȸ���˻� ��� ����� ���� �޴��� �����ϰ� ��
//getMemberName();getMemberAddress();getMemberMobile(); �Լ��� �̿���
//�˻��� ȸ�� ������ �Է¹ް�, �Է��� �Ϸ�Ǹ� �޸��� �����ͷκ��� �˻��� �����Ѵ�.
void callSearchMember();
void searchMember(int, int, char *);
void searchMemberByID(int);
void searchMemberByName(char *);
void searchMemberByAddress(char *);
void searchMemberByMobileNumber(char *);
void foundNode(node_t * currentNode, int * p_searchResultCount);

//4. �������� ��� ����� ���� �޴��� �����ϰ� ��
//searchMember(); �Լ��� �̿��� ������ ȸ���� �˻��Ͽ� ������ ��
//������ ȸ���� ������ ������ �޸𸮿� �����Ѵ�.
void callEditMember();
void editMemberName(node_t * currentNode, char * newName);
void editMemberAddress(node_t * currentNode, char * newAddress);
void editMemberMobileNumber(node_t * currentNode, char * newMobileNumber);

//5. ȸ������ ��� ����� ���� �޴��� �����ϰ� ��
//searchMember(); �Լ��� �̿��� ������ ȸ���� �˻��Ͽ� ������ ��
//������ ȸ���� ������ �޸𸮿��� �����Ѵ�.
void callDeleteMember();
void deleteMember(node_t * currentNode);

//6. ����.
//�޸��� ������ ��������� ������.
void save();


//����� ������ ��� node�� list�� �� �ڿ� add�Ѵ�.
void addMember(node_t * newNode);


//����� ������ ��� node�� list�� insert�Ѵ�.
void insertNode(list_t, node_t, memberList);

void freeList(memberList *);

/*
sub func
*/

//�ű� ȸ�� ���Խ� �ο����� ���̵� ����(���� �ִ� ��ȣ +1)
int generateNewID();

//ȸ�� �̸��� �Է¹���(�˻�, ���� � �����)
//������ �̸� �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
int getMemberName(char *);

//ȸ�� �ּҸ� �Է¹���(�˻�, ���� � �����)
//������ �ּ� �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
int getMemberAddress(char *);

//ȸ�� ��ȭ��ȣ �Է¹���(�˻�, ���� � �����)
//������ ��ȭ��ȣ �����͸� ����, ���� �Ǵ� ��ҽ� -1 ����
int getMemberMobile(char *);