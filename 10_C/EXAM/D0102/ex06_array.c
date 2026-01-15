/* ********************************************************
* File name   : ex06_array.c
* Description : 배열 요소의 수
* Author      : HyeonWoo
* History     : 2025.01.02 HyeonWoo
* **********************************************************/
// ----------------------------------------------------------
// 배열의 요소 개수 계산
// ----------------------------------------------------------

#include <stdio.h>

int main(void)
{
	int		score[5] = { 90, 80, 50, 80, 100 };	// 하나당 4byte -> 즉 20byte
	short	  nums[] = { 11, 22, 33, 44, 55, 66, 77, 88, 3, 99, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 }; // 하나당 2byte -> 즉 40byte

	// 배열의 요소 개수 및 배열 전체 사용 메모리 크기를 출력
	int cnt1 = 0, totalBytes1 = 0;
	int cnt2 = 0, totalBytes2 = 0;

	cnt1 = sizeof(score) / sizeof(score[0]); // 총 20byte / 4byte = 5byte
	totalBytes1 = cnt1 * sizeof(score[0]);

	cnt2 = sizeof(nums) / sizeof(nums[0]);	 // 총 40byte / 4byte = 5byte
	totalBytes2 = cnt2 * sizeof(nums[0]);

	printf("score 배열의 요소 : %02d개, 총 사용 메모리 : %dbytes, %llubytes\n", cnt1, totalBytes1, sizeof(score));
	printf(" nums 배열의 요소 : %d개, 총 사용 메모리 : %dbytes, %llubytes", cnt2, totalBytes2, sizeof(nums));
	return 0;
}