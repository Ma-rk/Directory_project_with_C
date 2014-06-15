#define _CRT_SECURE_NO_WARNINGS
#include "myTypes.h"

extern memberList members;
extern memberList searchResult; 

extern addNode(memberList * list, node_t * newNode);

//2. ���
//�ű� ȸ���� ������ �Է¹޴� �Լ����� ȣ���Ͽ� ���ϰ��� ����ü�� ��´�.
//�ϼ��� member ����ü�� node ����ü�� �־� list�� ��´�.
void callRegisterMember(){
	int action;
	member_t * newMember;

	SetColor(11, 0);
	printf("�ű� ȸ���� ������ �Է��ϼ���.\n");
	SetColor(2, 0);
	//�ű� ���̵� �����ؿ�
	printf(". �ű� ���̵�: ");
	int newID = generateNewID();
	if (newID < 0){
		printf("\n\n�ű� ���̵� ������ �����߽��ϴ�.\n\n");
		return;
	}
	printf("%d\n", newID);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];

	//�ű�ȸ�� �̸��� Ű����� �Է¹���
	printf(". �ű�ȸ�� �̸�: ");
	action = getMemberName(newName);
	if (action == 0) return;

	//�ű�ȸ�� �ּҸ� Ű����� �Է¹���
	printf(". �ű�ȸ�� �ּ�: ");
	action = getMemberAddress(newAddress);
	if (action == 0) return;

	//�ű�ȸ�� ������ Ű����� �Է¹���
	printf(". �ű�ȸ�� ��ȭ��ȣ: ");
	action = getMemberMobile(newMobileNumber);
	if (action == 0) return;


	//�Է¹��� ������ ����ü�� ����
	newMember = (member_t *)malloc(sizeof(member_t));
	newMember->memID = newID;
	strcpy(newMember->memName, newName);
	strcpy(newMember->memAddress, newAddress);
	strcpy(newMember->memMobileNumber, newMobileNumber);

	//����ü�� ��忡 ����
	node_t * node = (node_t *)malloc(sizeof(node_t));
	node->member = newMember;

	//��带 linkedList �� �ڿ� add��
	registerMember(node);

	SetColor(11, 0);
	printf("\n");
	printf("�ű� ȸ�������� �ԷµǾ����ϴ�.\n");
	printf("�Է��Ͻ� ������ �����Ϸ��� ���α׷� ���� ���� ������ �ֽʽÿ�.\n");
	SetColor(3, 0);
	printf("�ƹ� Ű�� ������ �ʱ�ȭ������ �̵��մϴ�.\n");
	getch();

}

//3. �˻�
//�˻��� ���� ���� �Լ�.
//�˻��� �ʿ��� Ű���带 ����ڷκ��� �Է¹޴´�.
//����ڰ� ���ϴ� �׸��� �˻��ϴ� �Լ��� �б��Ѵ�.
void callSearchMember(){
	char input[5];
	int searchChoice;
	char searchKeywordString[50];
	int searchKeywordNumber;
	int searchResultCount = 1;

	while (1){
		system("cls");

		gotoxy(10, 4);
		SetColor(16, 15);
		printf("< �˻� >");
		SetColor(10, 0);
		gotoxy(10, 8); printf("1. ID �˻�");
		gotoxy(10, 9); printf("2. �̸� �˻�");
		gotoxy(10, 10); printf("3. �ּ� �˻�");
		gotoxy(10, 11); printf("4. ��ȭ��ȣ �˻�");
		gotoxy(10, 12); printf("5. ������");
		SetColor(8, 0);
		gotoxy(10, 14); printf("�������� �˻��Ͻðڽ��ϱ�? ");
		

		fgets(input, 5, stdin);
		searchChoice = atoi(input);

		if (searchChoice > 0 && searchChoice < 5)
			break;
		else if (searchChoice == 5){
			SetColor(3, 0);
			gotoxy(10, 16); printf("����Ϸ��� �ƹ�Ű��");
			return;
		}
		else{
			SetColor(3, 0);
			gotoxy(10, 16); printf("�߸��� �Է��Դϴ�!");
			SetColor(15, 0);
		}
	}

	gotoxy(10, 16); printf("�˻��Ϸ��� ���� �Է��ϼ���: ");
	SetColor(15, 0);

	if (searchChoice == 1){
		scanf("%d", &searchKeywordNumber);
		printf("\n");
	}
	else{
		fflush(stdin);
		gets(searchKeywordString);
		printf("\n");
	}

	//�˻��� ���� ������ ������ �޸𸮻��� ���� �˻������ free ��Ŵ
	freeList(&searchResult);//free �Ϸ��� list�� NULL���� �ƴ����� freeList �Լ� �ȿ��� üũ�ϹǷ� ������ ���� �ʾƵ� �ȴ�.

	if (searchChoice == 1){//ID �˻�
		searchMemberByID(searchKeywordNumber);
	}
	else if (searchChoice == 2){//�̸� �˻�
		searchMemberByName(searchKeywordString);
	}
	else if (searchChoice == 3){//�ּ� �˻�
		searchMemberByAddress(searchKeywordString);
	}
	else if (searchChoice == 4){//��ȭ��ȣ �˻�
		searchMemberByMobileNumber(searchKeywordString);
	}
	

	if (!searchResult.head){
		SetColor(3, 0);
		gotoxy(10, 18); printf("�˻������ �����ϴ�.");
		gotoxy(10, 19); printf("����Ϸ��� �ƹ�Ű��");
		SetColor(15, 0);
	}
}

//4. ����
//������ ���� ���� �Լ�.
//������ ��� ȸ���� ���Ѵ�.
//������ �׸��� ����.
//�� ���� �Է¹޴´�.
//������ �׸��� �����ϴ� �Լ��� �б��Ѵ�.
void callEditMember(){
	int selectedSearchListIndex = 0;
	int selectedModifyItem = 0;

	callSearchMember();//ȸ�� �˻� ����
	if (searchResult.head == NULL){//�˻������ ������ ����
		getch();
		return;
	}

	SetColor(11, 0);
	printf("������ ȸ���� �����ϼ���: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	char newName[NAME_LENGTH];
	char newAddress[ADDRESS_LENGTH];
	char newMobileNumber[MOBILE_LENGTH];

	printf("������ �׸��� �����ϼ���.\n");
	printf("\n");

	SetColor(14, 0);
	printf("(ID�� ������ �� �����ϴ�)\n");
	printf("1. �̸�.\n");
	printf("2. �ּ�.\n");
	printf("3. ��ȭ��ȣ.\n");

	fflush(stdin);
	scanf("%d", &selectedModifyItem);

	node_t * currentNode = searchResult.head;
	while (currentNode){
		if (currentNode->index == selectedSearchListIndex){
			if (selectedModifyItem == 1){
				SetColor(10, 0);
				printf(". �� ȸ�� �̸�: ");
				getMemberName(newName);
				editMemberName(currentNode, newName);//�̸� ����
			}
			else if (selectedModifyItem == 2){
				SetColor(10, 0);
				printf(". �� ȸ�� �ּ�: ");
				getMemberAddress(newAddress);
				editMemberAddress(currentNode, newAddress);//�ּ� ����
			}
			else if (selectedModifyItem == 3){
				SetColor(10, 0);
				printf(". �� ȸ�� ��ȭ��ȣ: ");
				getMemberMobile(newMobileNumber);
				editMemberMobileNumber(currentNode, newMobileNumber);//��ȭ��ȣ ����
			}
			SetColor(3, 0);
			printf("ȸ�������� �����߽��ϴ�. ��������� �����Ϸ��� ������ �ϼ���.\n");
			printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
			getch();
			
			return;
		}
		currentNode = currentNode->next;
	}
	
	SetColor(3, 0);
	printf("ȸ�������� �������� ���߽��ϴ�. ������ ������ �������� �ʽ��ϴ�.\n");
	printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
	getch();
}

//5. ����
//������ ���� ���� �Լ�.
//������ ��� ȸ���� ���Ѵ�.
//������ �׸��� �����ϴ� �Լ��� �����Ѵ�.
void callDeleteMember(){
	int selectedSearchListIndex = 0;
	int selectedDelete = 0;

	callSearchMember();//ȸ�� �˻� ����
	if (searchResult.head == NULL){//�˻������ ������ ����
		getch();
		return;
	}
	printf("������ ȸ���� �����ϼ���: ");
	fflush(stdin);
	scanf("%d", &selectedSearchListIndex);

	node_t * currentNode = searchResult.head;
	while (currentNode){
		if (currentNode->index == selectedSearchListIndex){

			deleteMember(currentNode);//ȸ�� ���� ����
			//���� ���� ���δ� ��� üũ�ϸ� ������??

			SetColor(3, 0);
			printf("ȸ�������� �����߽��ϴ�. ��������� �����Ϸ��� ������ �ϼ���.\n");
			printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
			getch();

			return;
		}
	}
	SetColor(3, 0);
	printf("ȸ�������� �������� ���߽��ϴ�. ������ ������ �������� �ʽ��ϴ�.\n");
	printf("����Ϸ��� �ƹ�Ű�� ��������.\n");
	getch();
}

