#define _CRT_SECURE_NO_WARNINGS
#include "myTypes.h"

extern memberList members;
extern memberList searchResult;


void freeList(memberList * nodes){
	if (nodes->head){
		node_t * nodeForFree = nodes->head;

		while (nodeForFree){
			node_t * temp = nodeForFree;
			nodeForFree = nodeForFree->next;
			free(temp);
		}
		nodes->head = NULL;
		nodes->tail = NULL;
	}
}


void addNode(memberList * list, node_t * newNode){
	if (list->head == NULL){
		list->head = newNode;
	}
	else{
		node_t * temp = list->tail;
		temp->next = newNode;
	}
	list->tail = newNode;
	newNode->next = NULL;
}

//1. ���
//�޸𸮿� linkedList ���·� ����� �����͸� ȭ�鿡 �����
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("����� �����Ͱ� �����ϴ�.");
		getch();
		return;
	}
	do{
		currentMember = currentNode->member;
		printf("|   %7d   |%8s  |   %s  |  %s   \n"
			, currentMember->memID, currentMember->memName
			, currentMember->memMobileNumber, currentMember->memAddress);
		currentNode = currentNode->next;
	} while (currentNode);
	printf("�ƹ� Ű�� ������ �ʱ�ȭ������ �̵��մϴ�.");
	getch();//����ڰ� �ƹ� Ű�� ���� ������ ��ٸ�
}


//2. ���
//�ű� ȸ���� ������ ��� ��带 linkedList�� �� �ڿ� add�Ѵ�.
void registerMember(node_t * node){
	//��带 linkedList �� �ڿ� add��
	addNode(&members, node);
}

//3. �˻�
void searchMemberByID(int searchKeywordNumber){
	node_t * currentNode = members.head;
	int searchResultCount = 1;
	while (currentNode){
		if (currentNode->member->memID == searchKeywordNumber){
			printf("%d\t%d\t%s\t%s\t%s\n", searchResultCount, currentNode->member->memID, currentNode->member->memName, currentNode->member->memAddress, currentNode->member->memMobileNumber);
			foundNode(currentNode, &searchResultCount);
		}
		currentNode = currentNode->next;
	}
}
void searchMemberByName(char * searchKeywordString){
	node_t * currentNode = members.head;
	int searchResultCount = 1;

	while (currentNode){
		if (strcmp(currentNode->member->memName, searchKeywordString) == 0){
			printf("%d\t%d\t%s\t%s\t%s\n", searchResultCount, currentNode->member->memID, currentNode->member->memName, currentNode->member->memAddress, currentNode->member->memMobileNumber);
			foundNode(currentNode, &searchResultCount);
		}
		currentNode = currentNode->next;
	}
}
void searchMemberByAddress(char * searchKeywordString){
	node_t * currentNode = members.head;
	int searchResultCount = 1;

	while (currentNode){
		//�ּҴ� like �˻�
		if (strstr(currentNode->member->memAddress, searchKeywordString) != NULL){
			printf("%d\t%d\t%s\t%s\t%s\n", searchResultCount, currentNode->member->memID, currentNode->member->memName, currentNode->member->memAddress, currentNode->member->memMobileNumber);
			foundNode(currentNode, &searchResultCount);
		}
		currentNode = currentNode->next;
	}
}
void searchMemberByMobileNumber(char * searchKeywordString){
	node_t * currentNode = members.head;
	int searchResultCount = 1;

	while (currentNode){
		if (!strcmp(currentNode->member->memMobileNumber, searchKeywordString) == 0){
			printf("%d\t%d\t%s\t%s\t%s\n", searchResultCount, currentNode->member->memID, currentNode->member->memName, currentNode->member->memAddress, currentNode->member->memMobileNumber);
			foundNode(currentNode, &searchResultCount);
		}
		currentNode = currentNode->next;
	}
}

void foundNode(node_t * currentNode, int * p_searchResultCount){
	node_t * searchNode = (node_t *)malloc(sizeof(node_t));
	searchNode->member = currentNode->member;
	searchNode->index = (*p_searchResultCount);
	addNode(&searchResult, searchNode);

	(*p_searchResultCount)++;
}

//4. ����
//4-1. �̸� ����
void editMemberName(node_t * currentNode, char * newName){
	strcpy(currentNode->member->memName, newName);
}
//4-2. �ּ� ����
void editMemberAddress(node_t * currentNode, char * newAddress){
	strcpy(currentNode->member->memName, newAddress);
}
//4-3. ��ȭ��ȣ ����
void editMemberMobileNumber(node_t * currentNode, char * newMobileNumber){
	strcpy(currentNode->member->memName, newMobileNumber);
}

//5. ����
//���� ���� ���θ� ������ �� �ʿ䰡 �ִ°�??
void deleteMember(node_t * currentNode){
	if (members.head->member->memID == currentNode->member->memID){
		members.head = members.head->next;
	}
	else{
		node_t * prevNode = members.head;
		while (prevNode->next){
			if (prevNode->next->member->memID == currentNode->member->memID){
				prevNode->next = prevNode->next->next;
				break;
			}
			prevNode = prevNode->next;
		}
	}
	free(currentNode->member);
	free(currentNode);
}



