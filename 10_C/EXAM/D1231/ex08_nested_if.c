/* ********************************************************
* File name : ex08_nested_if.c
* Description : 중첩 조건문
*				조건부 안에 조건문
*				입력 받은 숫자가 홀수/짝수 여부 출력
*				숫자만 입력 가능함!
* History : 2025.12.31 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	char input = 0;
	int number = 0;
	printf("숫자 문자 1개 입력 : ");

	// (1) 숫자 1개 입력이 제대로 된 경우
	if (scanf("%c", &input) == 1) {
		// (2) '0' - '9' 검사
		if (input >= '0' && input <= '9') {

			printf("%c => 형변환 %d\n", input, (int)input);
			number = (int)input - 48;
			printf("%d=> 형변환 후 %d\n", input, number);

			(number % 2) ? printf("홀수") : printf("짝수");
		}
		else {
			printf("숫자 문자가 아닙니다!");
		}
	}
	else {
		printf("정확한 입력이 아닙니다.!");
	}

	return 0;
}
