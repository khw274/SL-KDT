/* ********************************************************
* File name : ex03_assign_op.c
* Description : 대입/할당 연산자
*				lvalue = rvalue;
*				lvalue : 변수. 상수(리터럴상수, 심볼상수) 불가!
*				rvalue : 변수, 상수 모두 가능
*				복합대입연산자 : 대입연산자와 다른 연산자 결합한 것
*				lvalue 다른 연산자 = rvalue
* History : 2025.12.31 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {
	 
	int    num = 7;
	int result = 0;

	// 복합연산자 처리
	num += 10;
	printf("num += 10 : %d\n", num);

	num -= 10;
	printf("num -= 10 : %d\n", num);

	num *= 10;
	printf("num *= 10 : %d\n", num);

	num /= 10;
	printf("num /= 10 : %d\n", num);

	return 0;
}