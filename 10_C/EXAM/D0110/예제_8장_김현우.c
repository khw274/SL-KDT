/* ***********`********************************************************
* File name    : 예제_8장_김현우.c
* Description  : 8장. 함수와 포인터
* Author       : HyeonWoo
* History      : 2026.01.11 HyeonWoo
* ********************************************************************/
#include <stdio.h>

////예제 8-1) -------------------------------------------------------
//void swap(int x, int y) {
//	int tmp;
//
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main(void) {
//	int x = 5;
//	int y = 3;
//
//	printf("x=%d, y=%d\n", x, y);
//	swap(x, y);
//	printf("x=%d, y=%d\n", x, y);
//
//	return 0;
//}

////예제 8-2) -------------------------------------------------------
//void swap(int* px, int* py);
//
//int main(void)
//{
//	int a = 10;
//	int b = 20;
//
//	printf("swap 전 a : %d, b : %d\n", a, b);
//	swap(&a, &b);
//	printf("swap 후 a : %d, b : %d", a, b);
//
//	return 0;
//}
//
//void swap(int* px, int* py)
//{
//	int temp = 0;
//	temp = *px;
//	*px = *py;
//	*py = temp;
//}

////예제 8-3) -------------------------------------------------------
//void change_x(char* pc);
//
//int main(void)
//{
//	char* chr = "AAA";
//	
//	printf("변경 전 %s\n", chr);
//	change_x(chr);
//	printf("변경 후 %s", chr);
//
//	return 0;
//}
//
//void change_x(char* pc)
//{
//	pc = "ZZZ";
//}

////예제 8-4) -------------------------------------------------------
//void change_x(char** pc);
//
//int main(void)
//{
//	char* chr = "AAA";  // AAA의 주소를 저장
//	
//	printf("변경 전 %s\n", chr);
//	change_x(&chr);		// 포인터의 주소를 넘겨줌
//	printf("변경 후 %s", chr);
//
//	return 0;
//}
//
//void change_x(char** pc)// "AAA"의 주소가 아닌 chr 포인터의 주소를 저장
//{
//	*pc = "ZZZ";			// ZZZ의 주소를 저장
//}

////예제 8-16) -------------------------------------------------------
#include <stdlib.h>

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5 };
	const int LEN = sizeof(arr) / sizeof(arr[0]);

	int* p = malloc(sizeof(arr));

	if (p == NULL)
	{
		printf("out of memory\n");
		exit(1);
	}

	for (int i = 0; i < LEN; i++)
	{
		p[i] = arr[i] * 10;
		printf("arr[%d] = %d, p[%d] = %d\n", i, arr[i], i, p[i]);
	}

	return 0;
}