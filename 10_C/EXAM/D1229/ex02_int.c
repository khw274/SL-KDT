/* *********************************************************
* Filename : ex02_int.c
* Description : 정수형 타입별 최소/최대값 체크
*				limits.h
* History : 2025.12.29 BY HyeonWoo
* Note :
* **********************************************************/
// 라이브러리 로딩 
#include <stdio.h>		// 입출력 함수들
#include <limits.h>		// 자료형의 최소/최대값

// 엔트리 포인트 함수 : OS에서 실행 시 호출하는 함수
int main(void)
{
	int i = 100;

    printf("short               : %d ~ %d\n",     SHRT_MIN, SHRT_MAX);
    printf("unsigned short      : 0 ~ %u\n\n",    USHRT_MAX);

    printf("int                 : %d ~ %d\n",     INT_MIN, INT_MAX);
    printf("unsigned int        : 0 ~ %u\n\n",    UINT_MAX);

    printf("long                : %ld ~ %ld\n",   LONG_MIN, LONG_MAX);
    printf("unsigned long       : 0 ~ %lu\n\n",   ULONG_MAX);

    printf("long long           : %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long  : 0 ~ %llu\n",    ULLONG_MAX);

	return 0;
}