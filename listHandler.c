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

//1. 출력
//메모리에 linkedList 형태로 저장된 데이터를 화면에 출력함
void printMembers(){
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	member_t * currentMember;

	if (members.head == NULL || members.tail == NULL){
		printf("출력할 데이터가 없습니다.");
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
	printf("아무 키나 누르면 초기화면으로 이동합니다.");
	getch();//사용자가 아무 키나 누를 때까지 기다림
}


//2. 등록
//신규 회원의 정보가 담긴 노드를 linkedList의 맨 뒤에 add한다.
void registerMember(node_t * node){
	//노드를 linkedList 맨 뒤에 add함
	addNode(&members, node);
}

//3. 검색
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
		//주소는 like 검색
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

//4. 수정
//4-1. 이름 수정
void editMemberName(node_t * currentNode, char * newName){
	strcpy(currentNode->member->memName, newName);
}
//4-2. 주소 수정
void editMemberAddress(node_t * currentNode, char * newAddress){
	strcpy(currentNode->member->memName, newAddress);
}
//4-3. 전화번호 수정
void editMemberMobileNumber(node_t * currentNode, char * newMobileNumber){
	strcpy(currentNode->member->memName, newMobileNumber);
}

//5. 삭제
//삭제 성공 여부를 리턴해 줄 필요가 있는가??
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



