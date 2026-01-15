/* *********************************************************
* Filename	  : D1229_work_calc_김현우.c
* Description : 간단한 산술연산 계산기
* History	  : 2025.12.29 BY HyeonWoo
* Note		  :
* **********************************************************/
// 라이브러리 로딩 
#include <stdio.h>

int main(void) {

	int a, b;
	
	scanf("%d %d", &a, &b);

	printf("%d + %d = %d\n", a, b, a+b);
	printf("%d - %d = %d\n", a, b, a-b);
	printf("%d / %d = %d\n", a, b, a/b);
	printf("%d * %d = %d\n", a, b, a*b);

}