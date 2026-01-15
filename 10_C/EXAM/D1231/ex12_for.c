/* ********************************************************
* Filename    : ex12_for.c
* Description :
*               반복문 - for
*				반복 횟수가 명확한 반복문
*
* Author      : HyeonWoo
* History     : 2025.12.31 BY HyeonWoo
* **********************************************************/
#include <stdio.h>

int main(void) {

	// (1) 1~10 숫자 출력
	int			 no = 0;
	const int TOTAL = 10;	// 심볼 상수 : 값 변경 불가

	// for(반복 초기화 : 반복 제어 조건식):카운팅 증감 
	for (int n = 1; n <= TOTAL; n++)
	{
		// ->  1 <= 10 --> 2
		// ->  2 <= 10 --> 3
		// -> 11 <= 10 --> 거짓 : 반복 종료
		printf("%d - Happy New Year!\n", n);
	}

	return 0;
}
