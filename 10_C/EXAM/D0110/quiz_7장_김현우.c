/* *******************************************************************
* File name    : quiz_7Àå_±èÇö¿ì.c
* Description  : 7Àå ÄûÁî Ç®±â
* Author       : HyeonWoo
* History      : 2026.01.10 HyeonWoo
* ********************************************************************/
#include <stdio.h>
	
// ÄûÁî 7-6) ---------------------------------------------------------
// 1. &arr[0][0] : °ªÀÌ 5ÀÎ ¿ø¼ÒÀÇ ÁÖ¼Ò
// 2. *arr[0] : 5
// 3. *(int**)arr : 5

// ÄûÁî 7-7) ---------------------------------------------------------
//int main(void)
//{
//	int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
//	int (*ptr)[3] = arr;
//
//	printf("**ptr      : %d\n", **ptr);
//	printf("ptr+2      : %p\n", ptr + 2);
//	printf("&ptr[1][2] : %p\n", &ptr[1][2]);
//	printf("&ptr[2]    : %p\n", &ptr[2]);
//	printf("ptr[1]+0   : %p", ptr[1] + 0);
//
//	return 0;
//}

// ÄûÁî 7-9) ---------------------------------------------------------
//int main(void)
//{
//	char ch_arr[10];
//	char *ps = "ABC";
//	int i = 0;
//
//	for (i = 0; ps[i]; i++) 
//	{
//		ch_arr[i] = ps[i];
//	}
//	ch_arr[i] = '\0';
//
//	printf("ch_arr = % s\n", ch_arr);
//
//	return 0;
//}

// ÄûÁî 7-10) ---------------------------------------------------------
//int main(void)
//{
//	char* str_arr[] = { "ABC", "abc", "123", "2", "aa", "AAA", "111", "CCC", "AAB" };
//	char* tmp;
//
//	const int LEN = sizeof(str_arr) / sizeof(str_arr[0]);
//
//	printf("[ ");
//	for (int i = 0; i < LEN; i++)
//	{
//		printf("%s,", str_arr[i]);
//	}
//	printf(" ]\n\n");
//
//	for (int i = 0; i < LEN - 1; i++)
//	{
//		for (int j = 0; j < LEN - i - 1; j++)
//		{
//			if (strcmp(str_arr[j], str_arr[j + 1]) > 0)
//			{
//				tmp = str_arr[j];
//				str_arr[j] = str_arr[j + 1];
//				str_arr[j + 1] = tmp;
//			}
//		}
//	}
//
//	printf("[ ");
//	for (int i = 0; i < LEN; i++)
//	{
//		printf("%s,", str_arr[i]);
//	}
//	printf(" ]");
//	
//	return 0;
//}

// ÄûÁî 7-11) ---------------------------------------------------------
