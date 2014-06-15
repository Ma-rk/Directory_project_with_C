
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
//회원 이름을 입력받음(검색, 가입 등에 사용함)
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
				printf("입력이 잘못되었습니다.\n 다시 입력하려면 1, 나가려면 0을 입력하세요: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. 신규회원 이름: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
}

//회원 주소를 입력받음(검색, 가입 등에 사용함)
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
				printf("입력이 잘못되었습니다.\n 다시 입력하려면 1, 나가려면 0을 입력하세요: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. 신규회원 주소: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
}

//회원 전화번호 입력받음(검색, 가입 등에 사용함)
//사용자가 입력한 전화번호를 newMobileNumber 변수에 저장함.
//올바른 전화번호를 입력했는지를 판단하여 결과를 리턴해줌.
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

		if (newMobileNumberLength != 0){//입력한 값이 하나라도 있는지
			if (newMobileNumber[0] == 45 || newMobileNumber[newMobileNumberLength - 1] == 45){
				getMemberMobileResult = -1;//첫글자 또는 마지막 글자가 하이픈(-)이면 -1
			}
			else{
				for (int i = 0; i < (int)strlen(newMobileNumber) - 1; i++){
					if (newMobileNumber[i] >= 48 && newMobileNumber[i] <= 57) {//숫자인지 아닌지 판별
						getMemberMobileResult = 1;
					}
					else{
						if (newMobileNumber[i] == 45){//하이픈(-)인지 아닌지 판별
							getMemberMobileResult = 1;
						}
						else{
							getMemberMobileResult = -1;//숫자도 하이픈도 아닌 문자가 하나라도 있으면 -1
							break;
						}
					}
				}
			}
		}
		else{
			while (1){
				SetColor(3, 0);
				printf("입력이 잘못되었습니다.\n 다시 입력하려면 1, 나가려면 0을 입력하세요: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. 신규회원 전화번호: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}

		if (getMemberMobileResult == -1){
			while (1){
				SetColor(12, 0);
				printf("전화번호가 형식에 맞지 않습니다.\n");
				printf("숫자와 하이픈(-)만 사용해서 입력해야 합니다.\n");
				printf("전화번호를 다시 입력하세요.");
				SetColor(3, 0);
				printf("\n 다시 입력하려면 1, 나가려면 0을 입력하세요: ");
				input = getch();
				if (input == '1'){
					SetColor(2, 0);
					printf("\n. 신규회원 전화번호: ");
					break;
				}
				else if (input == '0') return 0;
				else continue;
			}
		}
	}
	return 1;
}