/* ********************************************************
* File name   : ex03_2d_array.c
* Description : 2차원 배열의 행과 열 개수 계산
* Author      : HyeonWoo
* History     : 2025.01.05 HyeonWoo
* **********************************************************/
// ----------------------------------------------------------
// [실습] 2차원 배열 선언 및 초기화
//		  행과 열 개수 계산
//		  5명 학생의 3과목 점수 저장
// ----------------------------------------------------------
#include <stdio.h>

int main(void) {

	int jumsu[5][3] = { 0 };

	const int ROWS = sizeof(jumsu) / sizeof(jumsu[0]);
	const int COLS = sizeof(jumsu[0]) / sizeof(jumsu[0][0]);

	printf("전체 배열의 크기 : %2d\n", (int)sizeof(jumsu));
	printf("       행의 크기 : %2d\n", (int)sizeof(jumsu[0]));
	printf("     요소의 크기 : %2d\n", (int)sizeof(jumsu[0][0]));

	// 점수 입력받기 - 한번에 세 개 과목 점수 입력 받기
	int c = 0;
	for (int r = 0; r < ROWS; r++)
	{
		printf("\n%d번 학생의 국, 영, 수 점수 입력(예: 90 80 70) : ", r + 1);

		if (scanf("%d %d %d", &jumsu[r][c], &jumsu[r][c + 1], &jumsu[r][c + 2]) != 3) return 0;
	}

	// 학생 별로 합계, 평균 출력
	for (int r = 0; r < ROWS; r++)
	{
		int sum = 0;
		for (int c = 0; c < COLS; c++)
		{
			sum += jumsu[r][c];
		}

		float avg = (float)sum / COLS;

		printf("%2d번 학생의 성적 합계: %3d, 평균: %.2f\n", r + 1, sum, avg);
	}

	return 0;
}
