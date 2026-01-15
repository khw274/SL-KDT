/* ********************************************************
* File name   : ex02_2d_array.c
* Description : 2차원 배열
* Author      : HyeonWoo
* History     : 2025.01.05 HyeonWoo
* **********************************************************/

# include <stdio.h>

int main(void) {

	int arr1[2][3] = { {11, 22, 33}, {44, 55, 66} };
	int arr2[2][3] = { 11, 22, 33, 44, 55, 66 };

	int arr3[2][3] = { {11, 22}, {44} };
	int arr4[2][3] = { 11, 22, 44 };

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 3; c++) {
			printf("arr[%2d][%2d] : %2d  ", r, c, arr1[r][c]);
		}
		printf("\n");
	}
	printf("\n");


	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 3; c++) {
			printf("arr[%2d][%2d] : %2d  ", r, c, arr2[r][c]);
		}
		printf("\n");
	}
	printf("\n");

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 3; c++) {
			printf("arr[%2d][%2d] : %2d  ", r, c, arr3[r][c]);
		}
		printf("\n");
	}
	printf("\n");

	for (int r = 0; r < 2; r++) {
		for (int c = 0; c < 3; c++) {
			printf("arr[%2d][%2d] : %2d  ", r, c, arr4[r][c]);
		}
		printf("\n");
	}

	return 0;
}