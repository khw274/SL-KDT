/* ********************************************************
* File name : ex06.casting.c
* Description : 형변환
*               자동형변환 => 시스템에서 처리
*               명시적형변환 => (타입명)변수명
* History : 2025.12.29 SON
* Note
* **********************************************************/
// 라이브러리 로딩 
#include <stdio.h>		// 입출력 함수들

// 엔트리 포인트 함수 : OS에서 실행 시 호출하는 함수
int main(void)
{

    // 지역변수 선언 및 초기화
    int value = 12, no = 9;

    print("%d / %d = %lf\n", value, no, (double)value / no);

    return 0;
}