/* *******************************************************************
* File name    : quiz_8장_김현우.c
* Description  : 8장 퀴즈 풀기
* Author       : HyeonWoo
* History      : 2026.01.11 HyeonWoo
* ********************************************************************/
#include <stdio.h>

// 퀴즈 8-1) ---------------------------------------------------------
//void swap_str(char* pc1, char* pc2);
//
//int main(void)
//{
//	char* str1 = "ABC";
//	char* str2 = "123";
//
//	printf("str1 = %s, str2 = %s\n", str1, str2);
//
//	swap_str(&str1, &str2);
//
//	printf("str1 = %s, str2 = %s\n", str1, str2);
//
//	return 0;
//}
//
//void swap_str(char* pc1, char* pc2)
//{
//	int* tmp;                                                                                                                                                                                                                                                                  
//	tmp = *pc1;
//	*pc1 = *pc2;
//	*pc2 = tmp;
//}

// 퀴즈 8-2) ---------------------------------------------------------
int gv_arr[100];

int main(void)
{
	int lv_arr[100];
	
	return 0;
}

// gv_arr은 같은 프로그램 내의 모든 소스파일 내에서 접근 가능
// lv_arr은 메인 함수 내에서만 접근 가능

// gv_arr은 전역변수로 자동으로 0으로 초기화되지만, lv_arr은 자동 초기화가 되지 않으므로 쓰레기값이 들어있음.
// lv_arr은 메인함수 종료시 메모리에서 자동 제거되지만 gv_arr은 프로그램이 종료되어 메모리에서 제거될 때 자동 제거된다.
// main함수가 종료되면 프로그램이 종료되는 것이므로 gv_arr이 조금 더 늦게 메모리에서 제거된다.
