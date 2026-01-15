/* ********************************************************
* Filename    : ex09_switch_case.c
* Description : switch ~ case 다중조건 처리문
*            if ~ else if ~ else 동일 가능
*            제약조건 => 정수, 상수만 가능함!
* Author      : HyeonWoo
* History     : 2025.12.31 BY HyeonWoo
* **********************************************************/
#include <stdio.h>

int main(void) {

	int  score = 0;
	char grade = 0;

	printf("점수 입력 : ");
	if (scanf("%d", &score) != 1) {
		printf("입력이 올바르지 않습니다.");
		return 0;
	}

	if (score >= 90)
		grade = 'A';
	else if (score >= 80)
		grade = 'B';
	else if (score >= 70)
		grade = 'C';
	else if (score >= 60)
		grade = 'D';
	else
		grade = 'F';

	printf("당신의 학점은 %c입니다\n", grade);

	switch (score / 10) {
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
		break;
	}

	printf("당신의 학점은 %c입니다\n", grade);

	return 0;
}
