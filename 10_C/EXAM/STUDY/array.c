/* ********************************************************
* File name	  : array.c
* Description : 다차원 배열 예제, 퀴즈 풀기
* Author      : HyeonWoo
* History	  : 2025.01.05 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void qz_5_1() 
{
	int arr[100];
	const int LEN = sizeof(arr) / sizeof(arr[0]); // 요소
	srand((unsigned)time(NULL));

	for (int i = 0; i < LEN; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < LEN; i++) 
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void qz_5_2() {

	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 4, 5, 6, 7 };
	int arr3[] = { 8, 9, 10 };

	int arr[ (sizeof(arr1) + sizeof(arr2) + sizeof(arr3)) / sizeof(arr1[0])];

	int i, pos = 0;

	const int LEN1 = sizeof(arr1) / sizeof(arr1[0]);
	const int LEN2 = sizeof(arr2) / sizeof(arr2[0]);
	const int LEN3 = sizeof(arr3) / sizeof(arr3[0]);
	const int LEN  = sizeof(arr) / sizeof(arr[0]);



}
int main(void) {
	ex_5_4();
}