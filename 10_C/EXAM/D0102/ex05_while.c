/* ********************************************************
* File name	  : ex05_while.c
* Description : 반복문 - do_while
*				반복코드 수행 후에 조건 검사 진행
*				반드시 코드 수행이 1회 진행됨
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <stdlib.h>		// C언어 표준 라이브러리 -> rand(), srand()
#include <time.h>		// C언어 시간관련 라이브러리 -> time()

int main(void) {

	// -----------------------------------------------------
	// [ UP/DOWN 게임 만들기 ]
	// 프로그램 지정 숫자 준비
	// 사용자가 입력한 숫자
	// 입력 숫자와 지정 숫자 비교해서 정보 제공 : up/down
	// 입력 숫자와 지정 숫자 동일하면 종료
	// -----------------------------------------------------

	const int TARGET = 63;
	int user = 0;

	printf("[ Up-Down Game ]\n");
	do {
		printf("0-100 범위의 정수 1개 입력 : ");
		scanf("%d", &user);

		(user > TARGET) ? printf("Down Number!\n") : (user < TARGET) ? printf("Up Number!\n") : 0;

	} while (TARGET != user);

	printf("BingGO! 지정 숫자 [%d]을 맞췄습니다!\nGame End", TARGET);

	return 0;
}