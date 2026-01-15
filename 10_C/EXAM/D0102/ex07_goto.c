/* ********************************************************
* File name	  : ex07_goto.c
* Description : 분기문 - goto 이해
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <stdlib.h>		// C언어 표준 라이브러리 -> rand(), srand()
#include <time.h>		// C언어 시간관련 라이브러리 -> time()

int main(void) {

	printf("시작\n");

	goto JUMP;
	printf("이 문장은 실행되지 않습니다.\n");
	
JUMP:
	printf("JUMP 라벨로 이동했습니다.\n");

	return 0;
}