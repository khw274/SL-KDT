/* ********************************************************
* File name   : ex01_memory.c
* Description : 데이터와 메모리
*				낮은 주소 (TEXT/CODE 영역) ---- 높은 주소(STACK영역)
* Author      : HyeonWoo
* History     : 2026.01.06 HyeonWoo
* **********************************************************/
// 전처리기 - 헤더 및 매크로 상수 ---------------------------
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000				// 메모리 안 씀

// 전역 변수 ------------------------------------------------
const int const_val = 30;		// 상수

int un_initial;					// 초기화되지 않은 전역변수
int initial = 30;				// 초기화된 전역변수
static int static_val = 70;		// 초기화된 정적변수

// 함수 프로토타입 선언 --------------------------------------
int function();

// 메인 함수
int main(void) 
{

	// 1. 변수 선언
	int local_val1 = 30;
	int local_val2;

	// 동적 할당 
	char* arr = malloc(sizeof(char) * 10);

	// 2. 입력
	printf("숫자 입력 : ");
	if(scanf("%d", &local_val2) != 1) return 0;

	// 3. 처리

	// 4. 출력
	printf("상수          Memory Address : \t   0x%p \n",    &const_val);
	printf("비초기화 변수 Memory Address : \t   0x%p \n",    &un_initial);
	printf("초기화 변수   Memory Address : \t   0x%p \n",    &initial);
	printf("정적 변수     Memory Address : \t   0x%p \n",    &static_val);
	printf("함수          Memory Address : \t   0x%p \n",    function);
	printf("지역 변수 1   Memory Address : \t   0x%p \n",    &local_val1);
	printf("지역 변수 2   Memory Address : \t   0x%p \n",    &local_val2);
	printf("동적할당변수  Memory Address : \t   0x%p \n\n",  arr);
		
	// 동적 할당 해제
	if (arr != NULL) free(arr);

	return 0;
}

// 사용자 정의 함수 ------------------------------------------
int function()
{
	return 20;
}
