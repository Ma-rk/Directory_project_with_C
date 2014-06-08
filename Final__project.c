#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "myTypes.h"

//디스크에서 읽은 회원정보를 저장할 자료구조(Linked List).
//추가, 수정, 삭제 실행시 여기에 들어있는 정보가 변경된다.
//저장시 여기에 들어있는 정보를 저장한다.
//(사실은 링크드 리스트의 헤드랑 테일의 포인터만 들어있음...)
memberList members;// = {};

//검색결과를 담는 자료구조.
//검색조건에 해당하는 데이터를 여기에 담는다.
//여기에 들어있는 데이터를 골라 수정, 삭제를 실행한다.
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
		choice = showMenuList();

		switch (choice){
		case 1:
			system("cls");
			printMembers();
			break;
		case 2:
			system("cls");
			registerMember();
			break;
		case 3:
			system("cls");
			deleteMember();
			break;
		case 4:
			system("cls");
			editMember();
			break;
		case 5:
			system("cls");
			save();
			break;
		case 6:
			system("cls");
			callSearchMember();
			printf("계속하려면 아무키나\n");
			getch();
			break;
		case 7:
			system("cls");
			return;
		}
	}
}

int showMenuList()
{
	fflush(stdin);
	int num;
	gotoxy(1, 4);
	SetColor(16, 15);
	printf("<회원관리 프로그램>");
	SetColor(15, 0);
	gotoxy(0, 8);
	printf("\t\t\t원하시는 기능을 고르세요. < >\n\n\n");
	printf("\t\t\t1. 출력\t\t5. 저장\n");
	printf("\t\t\t2. 등록\t\t6. 검색\n");
	printf("\t\t\t3. 삭제\t\t7. 종료\n");
	printf("\t\t\t4. 수정\n");
	gotoxy(50, 20);
	SetColor(16, 15);
	printf("Made by 도형 & 학결\n");
	SetColor(15, 0);
	gotoxy(51, 8);
	scanf("%d", &num);

	return num;
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