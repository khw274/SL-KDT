/* ********************************************************
* File name : ex06_if_else.c
* Description : 단순 조건문
*				(1) 짝수 & 홀수 출력
*				(2) 문자 1개에 대한 대문자 & 소문자
* History : 2025.12.31 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	//(1) 
	int num = 0;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	if (num % 2 == 0) {
		printf("짝수입니다.\n"); 
	}
	else {
		printf("홀수입니다.\n");
	}


	//(2)
	char ch = ' ';

	printf("\n문자 1개를 입력하세요 : ");

	scanf(" %c", &ch); // %c 앞에 공백 한 칸 추가 (남은 엔터 무시하고 입력받음)

	if (ch >= 'A' && ch <= 'Z') {
		printf("%c는 대문자입니다.\n", ch); 
	}

	if (ch >= 'a' && ch <= 'z') {
		printf("%c는 소문자입니다.\n", ch);
	}

	return 0;
}
