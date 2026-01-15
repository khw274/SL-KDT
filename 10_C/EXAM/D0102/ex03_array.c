/* ********************************************************
* File name   : ex03_array.c
* Description : 배열 생성
* Author      : HyeonWoo
* History     : 2025.01.02 HyeonWoo
* **********************************************************/
// ----------------------------------------------------------
// 변수와 배열 차이 이해
// -> 30명의 점수를 저장 및 출력
// ----------------------------------------------------------

#include <stdio.h>

int main(void) 
{
	int intScore[31];
	float floatScore[31];
	char charScore[31];
	
	for (int i = 0; i <= 30; i++) {
		intScore[i] = i;
	}

	for (int i = 0; i <= 30; i++) {
		printf("score[%d] = %d\n", i, intScore[i]);
	}

	return 0;
}