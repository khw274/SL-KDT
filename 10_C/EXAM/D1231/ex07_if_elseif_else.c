/* ********************************************************
* File name : ex07_if_elseif_else.c
* Description : 다중 조건문
*				조건부 연산자 즉, 삼항연산자 비교
*				
* History : 2025.12.31 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	//(1) 
	int num = 0;
	char result = ' ';
	printf("정수를 입력하세요 : ");
	scanf("%d", &num);

	//if (num % 2 == 0) {
	//	printf("짝수입니다.\n"); 
	//}
	//else {
	//	printf("홀수입니다.\n");
	//}

	// -> 조건부 연산자 즉, 삼항연산자로 구현
	printf("%s\n", (num % 2 == 0) ? "짝수입니다." : "홀수입니다.");

	//(2)
	char ch = ' ';

	printf("\n문자 1개를 입력하세요 : ");
	scanf(" %c", &ch); // %c 앞에 공백 한 칸 추가 (남은 엔터 무시하고 입력받음)

	//if (ch >= 'A' && ch <= 'Z') {
	//	printf("%c는 대문자입니다.\n", ch); 
	//}

	//if (ch >= 'a' && ch <= 'z') {
	//	printf("%c는 소문자입니다.\n", ch);
	//}
	printf("%s\n", (ch >= 'A' && ch <= 'Z') ? "대문자입니다." : "소문자입니다.");
	return 0;
}
