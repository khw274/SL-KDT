/* ********************************************************
* File name : ex04_compare_op.c
* Description : 비교연산자
* History : 2025.12.30 HyeonWoo
* Note
* **********************************************************/
#include <stdio.h>

int main(void) {

    int n1 = 10, n2 = 20;
    float f1 = 10.0f, f2 = 20.0f;
    double d1 = 10.0, d2 = (double)f2;

    // [1] 정수 비교 연산 : >, <=, <=, ==, !=
    printf("%d >  %d : %d\n", n1, n2, n1 > n2);
    printf("%d <  %d : %d\n", n1, n2, n1 < n2);
    printf("%d >= %d : %d\n", n1, n2, n1 >= n2);
    printf("%d <= %d : %d\n", n1, n2, n1 <= n2);
    printf("%d == %d : %d\n", n1, n2, n1 == n2);
    printf("%d != %d : %d\n\n", n1, n2, n1 != n2);

    // [2] 실수 비교 연산 : >, <=, <=, ==, !=
    printf("%f >  %f : %d\n", f1, f2, f1 >  f2);
    printf("%f <  %f : %d\n", f1, f2, f1 <  f2);
    printf("%f >= %f : %d\n", f1, f2, f1 >= f2);
    printf("%f <= %f : %d\n", f1, f2, f1 <= f2);
    printf("%f == %f : %d\n", f1, f2, f1 == f2);
    printf("%f != %f : %d\n\n", f1, f2, f1 != f2);
    
    // [3] 실수 비교 연산 : >, <=, <=, ==, !=
    printf("%f >  %lf : %d\n", f1, d1, f1 > d1);
    printf("%f <  %lf : %d\n", f1, d1, f1 < d1);
    printf("%f >= %lf : %d\n", f1, d1, f1 >= d1);
    printf("%f <= %lf : %d\n", f1, d1, f1 <= d1);
    printf("%f == %lf : %d\n", f1, d1, f1 == d1);
    printf("%f != %lf : %d\n", f1, d1, f1 != d1);

    return 0;
}