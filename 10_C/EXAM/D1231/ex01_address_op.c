/* ********************************************************
* File name : ex01_address_op.c
* Description : 메모리 주소 관련 연산자들
*				& : 변수의 주소값 읽어오는 주소 연산자
*				* : 주소를 참조하는 연산자
* History : 2025.12.31 HyeonWoo
* Note
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int x  = 10;	// 데이터 10 저장
	int* p = &x;	// 변수 x의 주소 저장
	int* a = &x;

	// 변수와 데이터 출력
	printf("x가 저장하고 있는 데이터                = %d\n", x);
	printf("x의 주소                                = %p\n\n", &x);

	printf("p가 저장하고 있는 주소                  = %p\n", p);	// 변수
	printf("*p : 저장하고 있는 주소의 데이터 읽기   = %d\n", *p);
	printf("p의 주소                                = %p\n", &p);

	return 0;
}