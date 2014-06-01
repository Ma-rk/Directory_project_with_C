#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "myTypes.h"


int main()
{
	int choice;
	while (1){

		system("cls");
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
	gotoxy(1, 4);
	SetColor(16, 15);
	printf("<ȸ������ ���α׷�>");
	SetColor(15, 0);
	gotoxy(0, 8);
	printf("\t\t\t���Ͻô� ����� ������. < >\n\n\n");
	printf("\t\t\t1. ���\t\t5. ����\n");
	printf("\t\t\t2. ���\t\t6. �˻�\n");
	printf("\t\t\t3. ����\t\t7. ����\n");
	printf("\t\t\t4. ����\n");
	gotoxy(50, 20);
	SetColor(16, 15);
	printf("Made by ���� & �а�\n");
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

void printPeople()
{
	int i, check, get;
	int sNum;
	int num;
	int ch;
	char name[10];
	char address[30];
	char phone[20];

	FILE *fp;
	fp = fopen("data.txt", "rt");

	if (fp == NULL){
		puts("error\n");
		return -1;
	}

	while (1)
	{
		check = 19;

		SetColor(10, 0);
		printf("=======================================================================\n");
		printf("|  Student ID |   Name   |   Phone number   |       Home address       \n");
		printf("=======================================================================\n");
		SetColor(15, 0);
		fscanf(fp, "%d%s\t%[^\t]\t%s", &sNum, name, address, phone);
		while (check--&&!feof(fp)){

			printf("|   %7d   |%8s  |   %s  |   %s   \n", sNum, name, phone, address);
			fscanf(fp, "%d%s\t%[^\t]%s", &sNum, name, address, phone);

		}
		printf("=======================================================================\n");
		SetColor(9, 15);
		printf("<- : ���� ȸ������ ���� -> : ���� ȸ������ ���� �� : Main�޴��� ���ư���\n");
		SetColor(15, 0);

		while (1)
		{
			ch = getch();
			if (ch == 75){
				fseek(fp, 0L, SEEK_SET);
				system("cls");
				break;
			}
			else if (ch == 77 && !feof(fp)){
				system("cls");
				break;
			}
			else if (ch == 80){
				return;
			}
			else{
				gotoxy(0, 24);
				SetColor(12, 15);
				if (feof(fp))
					printf("ȸ�������� ������ �������Դϴ�.                                         ");
				else
					printf("�߸� �Է��ϼ̽��ϴ�. <- , -> , �� �߿� �ϳ��� �����ϼ���.               ");
				SetColor(15, 0);
			}
		}


		if (feof(fp))
			break;

	}
	fclose(fp);

}

void SetColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}