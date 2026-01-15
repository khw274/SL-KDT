/* ********************************************************
* Filename    : ex13_for.c
* Description :
*               반복문 - for
*				반복 횟수가 명확한 반복문
*
* Author      : HyeonWoo
* History     : 2025.12.31 BY HyeonWoo
* **********************************************************/
#include <stdio.h>

// 매크로 상수 -> 전처리기/컴파일러
//				  파일 내에 LIMIT 글자를 전부 30으로 치환

#define LIMIT 30

int main(void) {

	// (1) 2의 배수만 출력하기
	//	   값 범위 : 1 ~ 30
	//	   30 => 상수, 변경 불가

	// for 반복문
	for (int n = 2; n <= LIMIT; n += 2)
	{
		printf("%d ", n);
	}

	// (2) 2의 배수 합계 계산하기
	int total = 0;

	for (int n = 2; n <= LIMIT; n += 2)
	{
		total += n;
		printf("%d %d\n", n, total);
	}

	return 0;
}
