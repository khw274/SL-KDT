/* ********************************************************
* File name	  : ex04_while.c
* Description : while 반복문
*				반복 횟수가 정해진 경우 & 정해지지 않은 경우
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int num, sum = 0, flag = 1;

	printf("합계 계산용 숫자 입력(단, 0 입력 시 종료)\n");

	while (flag)
	{
		printf(">>");
		scanf("%d", &num);

		if (num) 
			sum += num;
		
		else 
			flag = 0;
			printf("합계 : %d", sum);
		
		//(num != 0) ? sum += num : flag = 0;

	}

	return 0;


}