#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "myTypes.h"


int main()
{
	int choice;

	while (1){
		choice = showList();

		switch (choice){
		case 1:
			system("cls");
			printPeople();
		}

	}


}

int showList()
{
	int num;
	gotoxy(9, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("<회원관리 프로그램>");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(0, 8);
	printf("\t\t\t원하시는 기능을 고르세요. ( )\n\n\n");
	printf("\t\t\t1. 출력\t\t5. 저장\n");
	printf("\t\t\t2. 등록\t\t6. 검색\n");
	printf("\t\t\t3. 삭제\t\t7. 종료\n");
	printf("\t\t\t4. 수정\n");
	gotoxy(50, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("Made by 도형 & 학결\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
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

void printPeople()
{
	int i;
	int sNum;
	char name[10];
	char address[30];
	char phone[20];

	FILE *fp;
	fp = fopen("data.txt", "rt");

	if (fp == NULL){
		puts("error\n");
		return -1;
	}

	do{
		fscanf(fp, "%d\t%s\t%[^\t]%s", &sNum, name, address, phone);
		printf("%d%8s%25s%10s\n", sNum, name, address, phone);
	} while (!feof(fp));
	fclose(fp);
	system("cls");
}