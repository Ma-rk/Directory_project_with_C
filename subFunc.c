#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

extern memberList members;

//�Է¹��� ����
void clearLineFromReadBuffer(void){
	while (getchar() != '\n');
}

//���޹��� ��带 ������ ��ũ�� ����Ʈ �� �ڿ� �߰�
void addMember(node_t * newNode){
	if (!members.head){
		members.head = newNode;
		members.tail= newNode;
		newNode->next = NULL;
	}
	else{
		node_t * temp = members.tail;
		temp->next = newNode;
		members.tail = newNode;
		newNode->next = NULL;
	}
}