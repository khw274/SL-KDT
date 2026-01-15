/* ********************************************************
* Filename    : ex09_switch_case.c
* Description :
*               (1) 달을 입력 받아서 계절 출력하기
*               12, 1, 2 => 겨울
*                3, 4, 5 => 봄
*                6, 7, 8 => 여름 (오타 수정됨)
*               9, 10, 11 => 가을
* Author      : HyeonWoo
* History     : 2025.12.31 BY HyeonWoo
* **********************************************************/
#include <stdio.h>

int main(void) {

	int month = 0;

	// 1. 입력 안내 및 받기
	printf("달을 입력하세요 : ");

	// scanf가 정수를 정상적으로 읽지 못하면(문자 입력 등) 1이 아닌 값을 반환합니다.
	if (scanf("%d", &month) != 1) {
		printf("입력이 올바르지 않습니다.\n");
		return 1; // 비정상 종료 처리
	}

	// 2. 계절 판별 (Switch-Case)
	switch (month) {
	case 12:
	case 1:
	case 2:
		printf("%d월은 겨울입니다.\n", month);
		break; // break를 만나야 switch문을 빠져나갑니다.

	case 3:
	case 4:
	case 5:
		printf("%d월은 봄입니다.\n", month);
		break;

	case 6:
	case 7:
	case 8:
		printf("%d월은 여름입니다.\n", month);
		break;

	case 9:
	case 10:
	case 11:
		printf("%d월은 가을입니다.\n", month);
		break;

	default:
		// 1~12 이외의 숫자가 입력되었을 때
		printf("%d월은 존재하지 않습니다.\n", month);
		break;
	}

	return 0;
}
