/* ********************************************************
* File name	  : ex02_while.c
* Description : while 반복문
*				반복 횟수가 정해진 경우 & 정해지지 않은 경우
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int num;
	int sum = 0;

	printf("숫자를 입력하세요.(예: 12345)> : ");
	scanf("%d", &num);

	while (num) {
		
		sum += num % 10;
		printf("sum=%3d num=%d\n", sum, num);

		num /= 10;
	}

	printf("각 자리수의 합 : %d\n", sum);
	return 0;


}