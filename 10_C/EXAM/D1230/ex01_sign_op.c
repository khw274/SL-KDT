/* ********************************************************
* File name : ex01_sign_op.c
* Description : 단항 연산자 -> 부호 연산자
*               - 부호 연산자 : 현재 부호를 반대로 변환
*               + 부호 연산자 : 변환 없음
*               ★ 컴파일러의 자동형변환 적용
*                  타입별 기본타입으로 형변환 적용
* History : 2025.12.30 HyeonWoo
* Note
* **********************************************************/
#include <stdio.h>

int main(void){

    int i, j;
    short s;

    i = -10;
    i += i;
    printf("i=%d\n", i);

    j = -10;
    j -= j;

    printf("j=%d\n", j);

    s = 10;
    printf(" s=%d, sizeof(s) =%d\n",  s, sizeof(s));
    printf("+s=%d, sizeof(+s)=%d\n", s, sizeof(+s));

    return 0;
}