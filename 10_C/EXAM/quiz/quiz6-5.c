/* *******************************************************************
* Quiz 6-6) 다음의 함수를 재귀 호출 대신 반복문을 사용하도록 변경하시오.
* ********************************************************************/
// 1. 전처리기

// 헤더 파일
 #include <stdio.h>

// 함수 선언
long long power(int x, int n);

// 메인 함수
int main(void)
{
	long long result = power(2, 3);
	printf("%lld", result);
	return 0;
}
// 함수 구현
long long power(int x, int n)
{
	long long result = 1;
	// n이 1보다 클 때까지 반복
	while (n--)
	{
		result *= x;
	}

	return result;
}