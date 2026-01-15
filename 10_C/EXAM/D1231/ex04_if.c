/* ********************************************************
* File name : ex04_if.c
* Description : 조건문
* History : 2025.12.31 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int num = 7;

	// 조건에 따른 출력 : 짝수 여부에 따른 출력
	if (num % 2 == 0) {
		//printf("%d\n", num);
		printf("짝수 입니다.");
	}
	
	else {
		//printf("%d\n", num);
		printf("홀수 입니다.");
	}

	return 0;
}