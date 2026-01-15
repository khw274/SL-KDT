/* ***********`********************************************************
* File name    : 예제_7장_김현우.c
* Description  : 7장. 포인터와 다차원 배열 ~
* Author       : HyeonWoo
* History      : 2026.01.08 HyeonWoo
* ********************************************************************/
#include <stdio.h>

////예제 7-17) -------------------------------------------------------
//int main(void) {
//    char c = 10;
//    int  i = 20;
//
//    char* pc = &c;
//    int* pi = &i;
//    void* vp1, * vp2;
//
//    vp1 = pc;  //  vp1 = (void*)pc;                                  
//    vp2 = pi;  //  vp2 = (void*)pi;                                  
//
//    printf("vp1=%p\n", vp1);
//    printf("vp2=%p\n", vp2);
//    printf("*(int*)vp2=%d\n", *(int*)vp2);
//    printf("((char*)vp1)++=%p\n", ((char*)vp1)++);
//    printf("(char*)vp1+1=%p\n", (char*)vp1 + 1);
//    printf("(char*)vp1 - (char*)vp2=%d\n", (char*)vp1 - (char*)vp2);
//    printf("vp1=%p\n", vp1);
//    printf("vp2=%p\n", vp2);
//
//    return 0;
//}

////예제 7-18) -------------------------------------------------------
//int main(void)
//{
//	int score[4][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	int(*ptr)[3] = score;	// 2차원 배열 포인터, int* ptr[3] -> 포인터 배열 
//	
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("score[%d][%d] = %2d, ptr[%d][%d] = %2d, &ptr[%d][%d] = %p\n", i, j, score[i][j], i, j, ptr[i][j], i, j, *score);
//		}
//	}
//} 

// 예제 7-19) -------------------------------------------------------
//int main(void)
//{
//	int arr[1][1] = { 100 };
//
//	printf("arr       = %p\n", arr);
//	printf("arr[0]    = %p\n", arr[0]);
//	printf("*arr      = %p\n", *arr);
//	printf("arr[0][0] = %d\n", arr[0][0]);
//	printf("*(int*)arr= %d\n", *(int*)arr);  // arr = &arr[0]  -> arr = &arr[0] -> 포인터 타입으로 형변환 ->   
//	printf("**arr     = %d\n", **arr);		 // *arr = &arr[0] -> 이걸 역참조하면 arr[0]의 값
//	 
//	return 0;
//}

// 예제 7-20) -------------------------------------------------------
//int main(void) {
//	int (*ptr)[4] = (int(*)[4])0x100;
//	int i, j;
//
//	printf("sizeof(ptr) =%d\n", sizeof(ptr));
//	printf("sizeof(*ptr)=%d\n", sizeof(*ptr));
//	printf("sizeof(ptr[0])=%d\n", sizeof(ptr[0]));
//	printf("sizeof(ptr[0][0])=%d\n", sizeof(ptr[0][0]));
//
//	for (i = 0; i < 3; i++) {
//		printf("ptr+%d=%p, sizeof(*(ptr+%d))=%0#x\n",
//			i, ptr + i, i, sizeof(*(ptr + i)));
//		for (j = 0; j < 4; j++)
//			printf("\tptr[%d]+%d=%p\n", i, j, ptr[i] + j);
//	}
//	return 0;
//}

// 예제 7-21) -------------------------------------------------------
//int main(void) {
//	int (*ptr)[4] = (int(*)[4])0x100;	//0x100 주소를 int 4개짜리 배열 포인터로 캐스팅
//	int i, j;
//
//	printf("sizeof(ptr)      =%zu\n", sizeof(ptr));
//	printf("sizeof(*ptr)     =%zu\n", sizeof(*ptr));
//	printf("sizeof(ptr[0])   =%zu\n", sizeof(ptr[0]));
//	printf("sizeof(ptr[0][0])=%zu\n", sizeof(ptr[0][0]));
//
//	for (i = 0; i < 3; i++) {
//		printf("ptr+%d=%p, sizeof(*(ptr+%d))=%0#x\n",
//			i, ptr + i, i, sizeof(*(ptr + i)));
//		for (j = 0; j < 4; j++)
//			printf("\tptr[%d]+%d=%p\n", i, j, ptr[i] + j);
//	}
//	return 0;
//}

// 예제 7-22) -------------------------------------------------------
//int main(void)
//{
//	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int* p1 = (int*)arr;
//	int sum = 0;
//	int len = sizeof(arr) / sizeof(arr[0][0]);
//
//	while (len--)
//	{
//		printf("p1 = %p, *p1 = %d\n", p1, *p1);
//		sum += *p1++;
//	}
//
//	printf("sum : %d", sum);
//	return 0;
//}

// 예제 7-23) -------------------------------------------------------
//int main(void) {
//	int arr2[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
//	int arr[sizeof(arr2) / sizeof(arr2[0][0])]; // arr2와 같은 크기의 1차원 배열  
//
//	const int LEN = sizeof(arr2) / sizeof(arr2[0][0]);
//	int len = LEN;
//	int i;
//
//	int* ptr = arr;
//	int* ptr2 = (int*)arr2;
//
//	while (len--)
//		*ptr++ = *ptr2++;  // 배열 arr2의 내용을 하나씩 배열 arr로 복사        
//
//	for (i = 0; i < LEN; i++)
//		printf("arr[%d]=%d \t arr2[%d][%d]=%d\n",
//			i, arr[i], i / 4, i % 4, arr2[i / 4][i % 4]);  // p.???을 참고            
//	return 0;
//}

// 예제 7-24) -------------------------------------------------------
//int main(void) {
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
//	int* p1 = arr;
//	int (*p2)[2] = (int(*)[2])arr;
//	int (*p3)[3] = (int(*)[3])arr;
//	int i;
///. 
//	for (i = 0; i < 12; i++) {
//		//printf("&p1[%d]=%p, *(p1+%d)=%d\n",i, p1+i, i, *(p1+i)); 
//		printf("p1+%d=%p, *(p1+%d)=%d\n", i, p1 + i, i, *(p1 + i));
//	}
//	printf("\n");
//
//	for (i = 0; i < 6; i++) {
//		printf("p2+%d=%p *(p2+%d)=%p **(p2+%d)=%d\n",
//			i, p2 + i, i, *(p2 + i), i, **(p2 + i));
//	}
//	printf("\n");
//
//	for (i = 0; i < 4; i++) {
//		printf("p3+%d=%p *(p3+%d)=%p **(p3+%d)=%d\n",
//			i, p3 + i, i, *(p3 + i), i, **(p3 + i));
//	}
//
//	return 0;
//}

// 예제 7-25) -------------------------------------------------------
//int main(void) {
//	//	int arr[2][3][4];                                                               
//	// int (*ptr)[3][4] = arr;                                                           
//
//	int (*ptr)[3][4] = (int(*)[3][4])0x100;
//	int i, j, k;
//
//	for (i = 0; i < 2; i++) {
//		printf("ptr+%d=%p, &ptr[%d]=%p\n", i, ptr + i, i, &ptr[i]);
//
//		for (j = 0; j < 3; j++) {
//			printf("\t ptr[%d]+%d=%p, &ptr[%d][%d]=%p\n",
//				i, j, ptr[i] + j, i, j, &ptr[i][j]);
//			for (k = 0; k < 3; k++) {
//				printf("\t\t ptr[%d][%d]+%d=%p, &ptr[%d][%d][%d]=%p\n",
//					i, j, k, ptr[i][j] + k, i, j, k, &ptr[i][j][k]);
//			}
//		}
//	}
//
//	return 0;
//}

// 예제 7-26) -------------------------------------------------------
//int main(void)
//{
//	char str[] = "abcde";
//	char* p = str;
//
//	printf("str = %s\n", str);
//	printf("p   = %s\n", p);
//	
//	//printf("%zu", sizeof(str));
//
//	for (int i = 0; i < sizeof(str); i++) {
//		printf("p[%d] = %c", i, p[i]);
//	}
//
//	return 0;
//}

// 예제 7-27) -------------------------------------------------------
//int main(void)
//{
//	char ch_arr[] = "abc";
//	char* ps = "abc";		 // = const char* ps = 'abc"
//
//	printf("ch_arr = %s, ps = %s\n\n", ch_arr, ps);
//
//	for (int i = 0; i < strlen(ch_arr); i++)
//	{
//		printf("ch_arr[%d] = %c, ps[%d] = %c\n", i, ch_arr[i], i, ps[i]);
//	}
//
//	strcpy(ch_arr, "ABC");
//	//strcpy(ps, "ABC");	// 문자열 상수의 내용을 변경할 순 없음 -> ERROR
//	//ch_arr = "ABC";       // 상수를 변경할 수 없음 -> ERROR
//	ps = "ABC";				// 문자열 상수의 주소를 PS에 저장 -> 가능
//	ch_arr[1] = 'Z';			// 문자 배열의 ch_arr의 두번째 요소를 변경 가능
//
//	return 0;
//}

// 예제 7-28) -------------------------------------------------------
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

// 예제 7-29) -------------------------------------------------------
//#include <stdio.h>                                                       
//#include <string.h>                                                      
//
//int main(void) {
//    char* str1 = "abc";
//    char* str2 = "abc";
//    char  chArr1[] = "abc";
//    char  chArr2[] = "abc";
//
//    printf("str1  =\"%s\"\n", str1);
//    printf("str2  =\"%s\"\n", str2);
//    printf("chArr1=\"%s\"\n", chArr1);
//    printf("chArr2=\"%s\"\n\n", chArr2);
//
//    printf("str1  =%p\n", str1);
//    printf("str2  =%p\n", str2);
//    printf("chArr1=%p\n", chArr1);
//    printf("chArr2=%p\n\n", chArr2);
//
//    printf("str1==str2 ? %d\n", str1 == str2);
//    printf("chArr1==chArr2 ? %d\n", chArr1 == chArr2);
//    printf("str1==chArr1 ? %d\n", str1 == chArr1);
//    printf("strcmp(str1, str2)=%d\n", strcmp(str1, str2));
//    printf("strcmp(strArr1, strArr2)=%d\n", strcmp(chArr1, chArr2));
//    printf("strcmp(str1, strArr1)=%d\n", strcmp(str1, chArr1));
//    printf("strcmp(str1, \"ABC\")=%d\n\n", strcmp(str1, "ABC"));
//
//    if (chArr1 == chArr2)
//        printf("chArr1과 chArr2는 주소가 같습니다.\n");
//    else
//        printf("chArr1과 chArr2는 주소가 다릅니다.\n");
//
//    if (strcmp(chArr1, chArr2) == 0)
//        printf("chArr1과 chArr2는 내용이 같습니다.\n");
//    else
//        printf("chArr1과 chArr2는 내용이 다릅니다.\n");
//
//    return 0;
//

// 예제 7-30) -----------------------------------------------------
//int main(void)
//{
//	char* p_arr[] = { "abcd", "123", "ABC" };	// 각각 포인터 -> 8bytes씩 총 3개 24bytes
//	char* tmp;
//	const int LEN = sizeof(p_arr) / sizeof(p_arr[0]);
//
//	for (int i = 0; i < LEN; i++)
//	{
//		for (int j = 0; j < strlen(p_arr[0]); j++)
//		{
//			printf("p_arr[%d][%d] = %c\n", i, j, p_arr[i][j]);
//		}
//	}
//
//	tmp = p_arr[0];
//	p_arr[0] = p_arr[1];
//	p_arr[1] = tmp;
//
//	p_arr[2] = "ZZZ";
//
//	for (int i = 0; i < LEN; i++)
//	{
//		printf("\np_arr[i] = %s", p_arr[i]);
//	}
//}

// 예제 7-31) -----------------------------------------------------
//#include <string.h>                                                    
//
//int main(void) {
//	char* strArr[] = { "ABC", "abc", "123", "2", "aa", "AAA", "111", "CCC", "AAB" };
//
//	const int LEN = sizeof(strArr) / sizeof(strArr[0]);
//	int i, j;
//	char* tmp;
//
//	printf("[");
//	for (i = 0; i < LEN; i++) {
//		printf("%s,", strArr[i]);
//	}
//	printf("]\n");
//
//	for (i = 0; i < LEN - 1; i++) {
//		for (j = 0; j < LEN - i - 1; j++) {
//			if (strcmp(strArr[j], strArr[j + 1]) < 0) {
//				tmp = strArr[j];
//				strArr[j] = strArr[j + 1];
//				strArr[j + 1] = tmp;
//			}
//		}
//	}
//
//	printf("[");
//	for (i = 0; i < LEN; i++) {
//		printf("%s,", strArr[i]);
//	}
//	printf("]\n");
//
//	return 0;
//}

// 예제 7-32) -----------------------------------------------------
//int main(void)
//{
//	char* str_arr[] = { "abc", "123", "ABC" };
//	char** p = str_arr;
//
//	const int LEN = sizeof(str_arr) / sizeof(str_arr[0]);
//
//	for (int i = 0; i < LEN; i++)
//	{
//		for (int j = 0; j < str_arr[i][j]; j++)
//		{
//			printf("str_arr[%d][%d] = %c, p[%d][%d] = %c\n", i, j, str_arr[i][j], i, j, p[i][j]);
//		}
//	}
//
//	return 0;
//}

// 예제 7-33) -----------------------------------------------------
int main(void)
{
	char* str_arr[] = { "abc", "123", "ABC", "111", NULL };
	char** p = str_arr;

	while (*p)
	{
		printf("*p=%s, %p\n", *p, *p);
		p++;
	}

	p = str_arr;
	
	while (*p)
	{
		
	}
}
