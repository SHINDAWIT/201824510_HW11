#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50
typedef struct phoneNumberList {
	char name[10];
	char phoneNumber[20];
} List;
List list[MAX_SIZE]={
	{"나태희", "010-5228-7889"},
	{"유현빈", "010-5211-1472"},
	{"나원빈", "010-1235-8765"},
	{"문건영", "010-8282-8282"}
};
int listSize=4;

void removePerson(void) {
	printf("삭제할 이름: ");
	char name[10];
	scanf("%s", name);
	int i;
	for(i=0; i<listSize; ++i) {
		if(strcmp(list[i].name, name) == 0) {
			break;
		}
	}
	int removeIndex=i;
	for(i=removeIndex; i<listSize-1; ++i) {
		strcpy(list[i].name, list[i+1].name);
		strcpy(list[i].phoneNumber, list[i+1].phoneNumber);
	}
	printf("%s 정보 삭제 완료!\n", name);
	--listSize;
}

int findPhoneNumberOfPerson(void) {
	printf("검색할 이름: ");
	char name[10];
	scanf("%s", name);
	int i;
	for(i=0; i<listSize; ++i) {
		if(strcmp(list[i].name, name) == 0) {
			printf("%s\t%s\n", list[i].name, list[i].phoneNumber);
			return 1;
		}
	}
	return 0;
}

void printPhoneNumberList(void) {
	printf(" <<전화번호목록>>\n");
	int i;
	for(i=0; i<listSize; ++i) {
		printf("%s\t%s\n", list[i].name, list[i].phoneNumber);
	}
}

void registerPhoneNumber(void)  {
	printf("등록할 이름 : ");
	scanf("%s", list[listSize].name);
	printf("전화번호 : ");
	scanf("%s", list[listSize].phoneNumber);
	printf("%s 정보 등록 완료!\n", list[listSize].name);
	++listSize;
}

int is_checkPassword(char* rightPassword) {
	int is_continue=1;
	int wrongPasswordCount=0;
	enum exitCondition {
		samePassword=1,
		wrongPassword=2
	};
	int whatIsTheExit;
	printf("비밀번호: ");
	while(is_continue) {
		char password[20];
		scanf("%s", password);
		int is_samePassword=strcmp(rightPassword, password)==0;
		if(is_samePassword) {
			whatIsTheExit=samePassword;
			is_continue=0;
		}
		else {
			++wrongPasswordCount;
		}
		if(!is_samePassword && wrongPasswordCount<3) {
			printf("비밀번호(%d회실패): ", wrongPasswordCount);
		}
		if(wrongPasswordCount==3){
			printf("비밀번호(%d회실패): 등록할 수 없음!\n", wrongPasswordCount);
			whatIsTheExit=wrongPassword;
			is_continue=0;
		}
	}
	
	switch(whatIsTheExit) {
		case samePassword: {
			return 1;
			break;
		}
		case wrongPassword: {
			return 0;
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}

int main() {
	char rightPassword[]="qwer1234";
	
	int is_continue=1;
	while(is_continue) {
		printf("전화번호 관리\n\n");
		printf("1. 등록[Tab] 2. 전체검색[Tab] 3. 특정인검색[Tab] 4. 제거[Tab] 5. 종료\n\n");
		printf("메뉴 선택: ");
	
		int menu;
		scanf("%d", &menu);
		switch(menu) {
			case 1: {
				printPhoneNumberList();
				printf("\n");
				if(is_checkPassword(rightPassword)==1) {
					registerPhoneNumber();
				}
				else {
					printf("프로그램을 종료합니다.\n");
					is_continue=0;
				}
				break;
			}
			case 2: {
				printPhoneNumberList();
				break;
			}
			case 3: {
				findPhoneNumberOfPerson();
				break;
			}
			case 4: {
				removePerson();
				break;
			}
			case 5: {
				printf("프로그램을 종료합니다.\n");
				is_continue=0;
				break;
			}
			default: {
				break;
			}
		}
		printf("\n");
	}
	
}
