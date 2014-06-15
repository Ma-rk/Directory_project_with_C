
#include "myTypes.h"

extern memberList members;

int generateNewID(){
	int newID = -1;
	node_t * currentNode = members.head;
	node_t * lastNode = members.tail;
	do{
		if (newID < currentNode->member->memID){
			newID = currentNode->member->memID;
		}
		currentNode = currentNode->next;
	} while (currentNode);
	//} while (currentNode->next != (node_t*)NULL);
	newID++;
	return newID;
}
//ȸ�� �̸��� �Է¹���(�˻�, ���� � �����)
int getMemberName(char * newName){
	int input;
	while (1){
		fflush(stdin);
		fgets(newName, NAME_LENGTH, stdin);
		for (int i = 0; i<NAME_LENGTH; i++){
			if (newName[i] == '\n') newName[i] = '\0';
		}
		int newNameLength = strlen(newName);
		if (newNameLength > 0 && newNameLength < 9){
			return 1;
		}
		else{
			while (1){
				SetColor(3, 0);
				printf("�Է��� �߸��Ǿ����ϴ�.\n �ٽ� �Է��Ϸ��� 1, �������� 0�� �Է��ϼ���: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. �ű�ȸ�� �̸�: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
}

//ȸ�� �ּҸ� �Է¹���(�˻�, ���� � �����)
int getMemberAddress(char * newAddreaa){
	int input;
	while (1){
		fflush(stdin);
		fgets(newAddreaa, ADDRESS_LENGTH, stdin);
		for (int i = 0; i<ADDRESS_LENGTH; i++){
			if (newAddreaa[i] == '\n') newAddreaa[i] = '\0';
		}

		int newAddressLength = strlen(newAddreaa);
		if (newAddressLength > 0 && newAddressLength < 30){
			return 1;
		}
		else{
			while (1){
				SetColor(3, 0);
				printf("�Է��� �߸��Ǿ����ϴ�.\n �ٽ� �Է��Ϸ��� 1, �������� 0�� �Է��ϼ���: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. �ű�ȸ�� �ּ�: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
}

//ȸ�� ��ȭ��ȣ �Է¹���(�˻�, ���� � �����)
//����ڰ� �Է��� ��ȭ��ȣ�� newMobileNumber ������ ������.
//�ùٸ� ��ȭ��ȣ�� �Է��ߴ����� �Ǵ��Ͽ� ����� ��������.
int getMemberMobile(char * newMobileNumber){
	int input;
	int getMemberMobileResult = -1;
	int newMobileNumberLength;

	while (getMemberMobileResult == -1){
		fflush(stdin);
		fgets(newMobileNumber, MOBILE_LENGTH, stdin);
		for (int i = 0; i<MOBILE_LENGTH; i++){
			if (newMobileNumber[i] == '\n') newMobileNumber[i] = '\0';
		}

		newMobileNumberLength = strlen(newMobileNumber) - 1;

		if (newMobileNumberLength != 0){//�Է��� ���� �ϳ��� �ִ���
			if (newMobileNumber[0] == 45 || newMobileNumber[newMobileNumberLength - 1] == 45){
				getMemberMobileResult = -1;//ù���� �Ǵ� ������ ���ڰ� ������(-)�̸� -1
			}
			else{
				for (int i = 0; i < (int)strlen(newMobileNumber) - 1; i++){
					if (newMobileNumber[i] >= 48 && newMobileNumber[i] <= 57) {//�������� �ƴ��� �Ǻ�
						getMemberMobileResult = 1;
					}
					else{
						if (newMobileNumber[i] == 45){//������(-)���� �ƴ��� �Ǻ�
							getMemberMobileResult = 1;
						}
						else{
							getMemberMobileResult = -1;//���ڵ� �����µ� �ƴ� ���ڰ� �ϳ��� ������ -1
							break;
						}
					}
				}
			}
		}
		else{
			while (1){
				SetColor(3, 0);
				printf("�Է��� �߸��Ǿ����ϴ�.\n �ٽ� �Է��Ϸ��� 1, �������� 0�� �Է��ϼ���: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. �ű�ȸ�� ��ȭ��ȣ: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}

		if (getMemberMobileResult == -1){
			while (1){
				SetColor(12, 0);
				printf("��ȭ��ȣ�� ���Ŀ� ���� �ʽ��ϴ�.\n");
				printf("���ڿ� ������(-)�� ����ؼ� �Է��ؾ� �մϴ�.\n");
				printf("��ȭ��ȣ�� �ٽ� �Է��ϼ���.");
				SetColor(3, 0);
				printf("\n �ٽ� �Է��Ϸ��� 1, �������� 0�� �Է��ϼ���: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. �ű�ȸ�� ��ȭ��ȣ: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
	return 1;
}