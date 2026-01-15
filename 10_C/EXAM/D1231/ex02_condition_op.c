/* ********************************************************
* File name : ex02_condition_op.c
* Description : 조건부 연산자 / 삼항 연산자
*				(조건) ? 참일 때 결과 : 거짓일 때 결과 : 
*				참   : 비교/논리 => 1, 0이 아닌 값
*				거짓 : 비교/논리 => 0, 값 0
* History : 2025.12.31 HyeonWoo
* Note
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	int result = 0, n1 = 0, n2 = 0;
	int score = 85;
	char grade = 0;

	// 학점 출력하기 => 90이상  A, 80이상 B, 나머지는 C
	grade = (score >= 90) ? 'A' : ((score > 80) ? 'B' : 'C');
	printf(grade);


	// 2개 정수 입력 받기
	printf("2개 정수 입력(예: 10 20) : ");
	scanf("%d %d", &n1, &n2);

	// 연산결과 출력
	result = (n1 == n2) ? n1 * n2 : n1 / n2;
	printf("n1=%d, n2=%d, result=%d\n", n1, n2, result);

	return 0;
}