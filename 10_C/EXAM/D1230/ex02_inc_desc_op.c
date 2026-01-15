/* ********************************************************
* File name : ex02_inc_desc_op.c
* Description : 단항 연산자 -> 증감 연산자
*               ++ 연산자 : 현재 값을 1 증가 
*               -- 연산자 : 현재 값을 1 감소
*               ★ 변수/피연산자 값을 변경하는 연산자
* History : 2025.12.30 HyeonWoo
* Note
* **********************************************************/
#include <stdio.h>

int main(void) {

    int i = 5;
    i++;
    printf("i=%d\n", i);

    i = 5;
    ++i;
    printf("i=%d", i);

    return 0;
}