/* ********************************************************
* File name   : ex02_factorial.c
* Description : 재귀함수
* Author      : HyeonWoo
* History     : 2026.01.06 HyeonWoo
* **********************************************************/
// 전처리기 - 헤더 및 매크로 상수 
#include <stdio.h>

// 함수 선언
long long factorial(int n);

// 메인 함수
int main(void)
{
	// 1. 변수 선언
	int n = 21;
	long long result = 0;

	// 2. 입력
	
	// 3. 처리
	for (int i = 1; i <= n; i++)
	{
		result = factorial(i);

		// 예외 처리
		if (result == -1)
		{
			printf("%d는 유효하지 않은 값입니다. (0 < n <= 21) \n", n);
			break;
		}

		// 4. 출력
		printf("%2d! = %20lld\n", i, result);
	}

	return 0;

	
	
}

// 사용자 정의 함수
long long factorial(int n)
{
	if (n <= 0 || n > 20) return -1; // 오류 범위 지정
	if (n == 1)			  return 1;  // n이 1일 경우 1! = 1

	// 재귀 호출
	return n * factorial(n - 1);
}