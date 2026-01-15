/* ********************************************************
* File name	  : ex01_while.c
* Description : while 반복문
*				반복 횟수가 정해진 경우 & 정해지지 않은 경우
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

// ----------------------------------------------------------
// // [실습] 1~50 범위의 숫자 출력 - while문 활용
// ----------------------------------------------------------
int main(void) {

	int num = 1;
	const int LIMIT = 50;

	while (num <= LIMIT)
	{

		printf("num = %d / %d\n", num, LIMIT);
		for (int i = 0; i < 100000000; i++);

		num += 1;

	}

	return 0;
}