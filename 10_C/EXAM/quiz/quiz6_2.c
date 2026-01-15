/* *******************************************************************
* Quiz 6-2) 두 개의 변수 중에서 큰 값을 구하는 함수(max)는 다음과 같다. 
*			이 함수를 이용해서 3개의 변수 중에서 제일 큰 수를 구하는 함수 max3를 완성하시오.
* ********************************************************************/
// 전처리기 - 헤더파일 포함
#include <stdio.h>

// 함수 선언
int max(int x, int y);
int max3(int x, int y, int z);

// 메인 함수
int main(void)
{
	int a, b, c;

	printf("세 정수를 입력하세요 : ");
	scanf("%d %d %d", &a, &b, &c);

	int max = max3(a, b, c);

	printf("max : %d", max);
}

// 함수 구현
int max(int x, int y)
{
	return x > y ? x : y;
}

int max3(int x, int y, int z)
{
	return x > y ? (x > z ? x : z) : (y > z ? y : z);
}