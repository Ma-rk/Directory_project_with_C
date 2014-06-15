#define _CRT_SECURE_NO_WARNINGS

#include "myTypes.h"


//��ũ���� ���� ȸ�������� ������ �ڷᱸ��(Linked List).
//�߰�, ����, ���� ����� ���⿡ ����ִ� ������ ����ȴ�.
//����� ���⿡ ����ִ� ������ �����Ѵ�.
//(����� ��ũ�� ����Ʈ�� ���� ������ �����͸� �������...)
memberList members;// = {};

//�˻������ ��� �ڷᱸ��.
//�˻����ǿ� �ش��ϴ� �����͸� ���⿡ ��´�.
//���⿡ ����ִ� �����͸� ��� ����, ������ �����Ѵ�.
memberList searchResult;

int main()
{
	int memberLoadResult = loadMembers();
	if (memberLoadResult != 1){
		puts("data load error");
	}
	int choice;

	while (1){
		system("cls");
		showMenuList();

		choice = getch();
		choice -= '0';

		switch (choice){
		case 1: //���
			system("cls");
			printMembers();
			break;
		case 2: //���
			system("cls");
			callRegisterMember();
			break;
		case 3: //�˻�
			system("cls");
			callSearchMember();
			getch();
			break;
		case 4: //����
			system("cls");
			callEditMember();
			break;
		case 5: //����
			system("cls");
			callDeleteMember();
			break;
		case 6: //����
			system("cls");
			save();
			break;
		case 7: //����
			system("cls");
			return;
		default:
			break;
		}
	}
}

void showMenuList()
{
	fflush(stdin);
	gotoxy(1, 4);
	SetColor(16, 15);
	printf("<ȸ������ ���α׷�>");
	SetColor(15, 0);
	gotoxy(0, 8);
	printf("\t\t\t���Ͻô� ����� ������. < >\n\n\n");
	printf("\t\t\t1. ���\t\t5. ����\n");
	printf("\t\t\t2. ���\t\t6. ����\n");
	printf("\t\t\t3. �˻�\t\t7. ����\n");
	printf("\t\t\t4. ����\n");
	gotoxy(50, 20);
	SetColor(16, 15);
	printf("Made by ���� & �а�\n");
	SetColor(15, 0);
	gotoxy(51, 8);
}


void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


void SetColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}