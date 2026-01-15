/* ********************************************************
* File name	  : ex03_while.c
* Description : while 반복문
*				반복 횟수가 정해진 경우 & 정해지지 않은 경우
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int sum = 0, i = 0;

	while ((sum += ++i) <= 100)
		printf("%d-%d\n", i, sum);
	
	return 0;


}