/* ********************************************************
* File name   : ex03_local_global.c
* Description : 전역변수와 지역변수
* Author      : HyeonWoo
* History     : 2026.01.06 HyeonWoo
* **********************************************************/
// 1. 전처리기 - 헤더파일 포함
#include <stdio.h>	

// 2. 매크로 상수 정의 

// 3. 구조체 정의 (필요 시)

// 4. 전역 변수/상수 선언 (Global Variable / constant)
int g_max = 1000;
const int G_MIN = 10;

// 5. 함수 선언

// 6. 메인 함수
int main(void)
{
	// [지역변수 선언]
	int value = 1000;
	int g_max = 9;

	// 블록 설정
	{
		int x = 10, y = 20;
		int value = 2000;
		
		// 블록 변수 출력
		printf("[블록] x = %d, y = %d, value = %d, g_max = %d\n", x, y, value, g_max);
	}

	// [입력] 

	// [처리]

	// [출력]
	
	// 메인 변수 출력: 지역 변수, 전역 변수, 전역 상수
	printf("[메인] value = %d, g_max = %d, G_MIN = %d\n", value, g_max, G_MIN);

	return 0;
}
// 7. 함수 구현

