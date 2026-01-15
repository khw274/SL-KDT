/* ********************************************************
* File name   : ex07_array.c
* Description : 
* Author      : HyeonWoo
* History     : 2025.01.02 HyeonWoo
* **********************************************************/
// ----------------------------------------------------------
// 사용자 정의 함수
// ----------------------------------------------------------
// 함수이름: printArray
// 함수기능: 배열의 원소들을 출력해주는 함수
// 매개변수: int arr[], 원소개수 nLen
// 반 환 값: void
// ----------------------------------------------------------
void printArray(int arr[], int nLen)
{
	for (int idx = 0; idx < nLen; idx++) {
		printf("%d번 원소 : %d\n", idx, arr[idx]);
	}
}
// ----------------------------------------------------------
// 함수이름: sum
// 함수기능: 배열의 원소 합계를 계산 후 반환해주는 함수
// 매개변수: int arr[], 원소개수 nLen
// 반 환 값: int
// ----------------------------------------------------------
int sumArray(int arr[], int nLen)
{
	int sum = 0;
	
	for (int idx = 0; idx < nLen; idx++) {
		sum += arr[idx];
	}

	return sum;
}


// ----------------------------------------------------------
// main 함수
// ----------------------------------------------------------
#include <stdio.h>

int main(void)
{
	int score[5] = { 0 };
	int sum = 0, len = 0;
	float avg = 0;
	const int LEN = sizeof(score) / sizeof(score[0]);
	

	for (int idx = 0; idx < LEN; idx++) {
		printf("%d번 원소 입력 : ", idx);
		scanf("%d", &score[idx]);
	}

	printArray(score, LEN);

	sum = sumArray(score, LEN);

	printf("합계 : %d, 평균 : %.2f", sum, (float)sum / LEN);

	return 0;
}