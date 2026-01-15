/* *************************************************************
* Filename     : ex05_const.c
* Description  : 상수
*                한번 저장 후 변경이 불가능한 데이터 저장 타입
*				 매크로 상수 => 전처리기/컴파일러에 의해 치환. 디버깅 X
*				 const 상수 => 메모리 공간 할당 및 디버깅 가능
* History      : 2025.12.29  BY HyeonWoo
* Note
***************************************************************/

// 라이브러리 로딩
#include <stdio.h>      //입출력 함수들

// 매크로 상수
#define WIDTH 20      // 전처리기/컴파일러에 의해 모두 치환

// 엔트리 포인트 함수: OS에서 실행 시 호출하는 함수
int main(void)
{
	// 지역변수 선언 및 초기화
	int result;
	//지역상수 선언 및 초기화
	const int HEIGHT = 30;

	//상수 변경 불가!!
	// HEIGHT = 15;
	// WIDTH = 9; 

	printf("CALC => %d\n", (WIDTH * HEIGHT));

	return 0;

}