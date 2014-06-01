#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "myTypes.h"

extern memberList members;

//입력버퍼 비우기
void clearLineFromReadBuffer(void){
	while (getchar() != '\n');
}

//전달받은 노드를 기존의 링크드 리스트 맨 뒤에 추가
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