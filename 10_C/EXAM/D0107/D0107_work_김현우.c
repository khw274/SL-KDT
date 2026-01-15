/* *******************************************************************
* File name    : D0107_work_김현우.c
* Description  : 7장. 포인터 과제
* Author       : HyeonWoo
* History      : 2026.01.07 HyeonWoo
* ********************************************************************/
// -------------------------------------------------------------------
// 1. 전처리기 - 헤더파일 포함 
// -------------------------------------------------------------------
#include <stdio.h>

// -------------------------------------------------------------------
// 2. 매크로 상수 정의 
// -------------------------------------------------------------------

// -------------------------------------------------------------------
// 3. 구조체 정의 (필요 시) 
// -------------------------------------------------------------------

// -------------------------------------------------------------------
// 4. 전역 변수/상수 선언 (Global Variable / constant)
// -------------------------------------------------------------------

// -------------------------------------------------------------------
// 5. 함수 선언 
// -------------------------------------------------------------------

// -------------------------------------------------------------------
// 6. 메인 함수 
// -------------------------------------------------------------------
int main(void)
{

	

	return 0;
}
// -------------------------------------------------------------------
// 7. 함수 구현 
// -------------------------------------------------------------------

// 예제 7-1) 
#include <stdio.h>                                                  

//int main(void) {
//	int  i = 5;
//	int* p = &i;
//
//	printf("i =%d\n", i);   // 변수 i에 저장된 값을 출력                
//	printf("&i=%p\n", &i);   // 변수 i의 주소를 출력                    
//	printf("p =%p\n", p);   // 포인터 p에 저장된 값(주소)을 출력          
//	printf("&p=%p\n", &p);   // 포인터 p의 주소를 출력                   
//
//	return 0;
//}

// 예제 7-2) 
//#include <stdio.h>                                 
//
//int main(void) {
//	int  i = 200;
//	int* ptr = &i;
//
//	*ptr = *ptr + 1;  // i = i + 1;°ú °°Àº ÀÇ¹ÌÀÌ´Ù.  
//
//	printf("i    =%d\n", i);
//	printf("*ptr =%d\n", *ptr);
//	printf("&i   =%p\n", &i);
//	printf("ptr  =%p\n", ptr);
//
//	return 0;
//}

// 예제 7-3) 
//#include <stdio.h>                                
//
//int main(void) {
//	int  i = 200;
//	int* ptr = &i;
//
//	printf("  i   =%d\n", i);
//	printf(" &i   =%p\n", &i);
//	printf("*&i   =%d\n", *&i);
//	puts("");
//	printf("  ptr =%p\n", ptr);
//	printf(" *ptr =%d\n", *ptr);
//	printf("&*ptr =%p\n", &*ptr);
//
//	return 0;
//}

// 예제 7-4) 
//#include <stdio.h>                                               
//
//int main(void) {
//    char   ch;
//    int    i;
//    float  f;
//    double d;
//
//    char* pch = &ch;
//    int* pi = &i;
//    float* pf = &f;
//    double* pd = &d;
//
//    printf("sizeof(pch) =%d\n", sizeof(pch));
//    printf("sizeof(pi)  =%d\n", sizeof(pi));
//    printf("sizeof(pf)  =%d\n", sizeof(pf));
//    printf("sizeof(pd)  =%d\n", sizeof(pd));
//    puts("");
//    printf("sizeof(*pch)=%d\n", sizeof(*pch));
//    printf("sizeof(*pi) =%d\n", sizeof(*pi));
//    printf("sizeof(*pf) =%d\n", sizeof(*pf));
//    printf("sizeof(*pd) =%d\n", sizeof(*pd));
//
//    return 0;
//}

// 예제 7-5) 

//#include <stdio.h>                                                           
//
//int main(void) {
//    int    i = 0x1B2B3B4B;
//    int* pi = &i;
//    char* pc = (char*)pi;  // 포인터의 타입을 char*로 형변환하여 포인터 pc에 저장      
//    short* ps = (short*)pi;
//
//    printf("&i=%p\n", &i);
//    printf("pi=%p\n", pi);
//    printf("pc=%p\n", pc);
//    printf("ps=%p\n", ps);
//
//    printf("*pi=%X\n", *pi);  // 포인터 pi가 가리키는 값(i)을 16진수(%X)로 출력      
//    printf("*pc=%X\n", *pc);
//    printf("*ps=%X\n", *ps);
//    printf("*(int*)pc=%X\n", *(int*)pc);
//    return 0;
//}

// 예제 7-6) 

//#include <stdio.h>                                     
//
//int main(void) {
//    float f = 12.625f;
//    float* pf = &f;
//    unsigned* pu = (unsigned*)pf;
//
//    printf("f=%f\n", f);
//    printf("pf=%p\n", pf);
//    printf("pu=%p\n", pu);
//    printf("*pf=%f\n", *pf);
//    printf("*pu=%X\n", *pu);
//
//    return 0;
//}

// 예제 7-7) 

//#include <stdio.h>
//
//int main(void) {
//	int   i = 0x1B2B3B4B;
//	int* pi = &i;
//	unsigned addr = (unsigned)pi;
//
//	printf("i        =%X\n", i);
//
//	printf("&i       =%p\n", &i);
//	printf("pi       =%p\n", pi);
//	printf("*pi      =%X\n", *pi);
//
//	printf("addr  =%08X, *(char*)addr    =%X\n", addr, *(char*)addr);
//	printf("addr+1=%08X, *(char*)(addr+1)=%X\n", addr + 1, *(char*)(addr + 1));
//	printf("addr+2=%08X, *(char*)(addr+2)=%X\n", addr + 2, *(char*)(addr + 2));
//	printf("addr+3=%08X, *(char*)(addr+3)=%X\n", addr + 3, *(char*)(addr + 3));
//
//	return 0;
//}

// 예제 7-8) 
//#include <stdio.h>                                                        
//
//int main(void) {
//	int    i = 100;
//
//	int* pi = &i;           // 변수 i를 가리키는 포인터                      
//	int** ppi = &pi;          // 포인터 pi를 가리키는 포인터(포인터의 포인터)       
//	int* pi2 = (int*)&pi;    // pi의 값을 pi2에 저장한다.                    
//
//	printf(" i  =%d\n", i);
//	printf("&i  =%p\n", &i);
//	printf("pi  =%p\n", pi);
//	printf("&pi =%p\n", &pi);
//	printf("ppi =%p\n", ppi);
//	printf("*ppi=%p\n", *ppi);
//	printf("**ppi=%d\n", **ppi);
//	printf("pi2 =%p\n", pi2);
//	printf("*pi2=%p\n", *pi2);
//	printf("**(int**)pi2=%d\n", **(int**)pi2);
//	printf("sizeof(pi)=%d\n", sizeof(pi));
//	printf("sizeof(ppi)=%d\n", sizeof(ppi));
//
//	return 0;
//}

// 예제 7-9) 
//#include <stdio.h>                                                             
//
//int main(void) {
//	const int MAX = 999;
//	int i = 100, i2 = 200;
//
//	int* ptr = (int*)&MAX; // 형변환 생략불가                                     
//	const int* ptr2 = &i;  // const int *ptr2=(const int*)&i; 형변환 생략가능       
//
//	const int* const PTR = &MAX;	// 포인터 상수 PTR선언                        
//	int* const PTR2 = &i;	  // 포인터 상수 PTR2선언                     
//
//	printf("MAX=%d\n", MAX);
//	printf("i=%d\n", i);
//	printf("*ptr =%d\n", *ptr);
//	printf("*ptr2=%d\n", *ptr2);
//
//	//	*ptr  = 200;  // 에러. *ptr은 상수 MAX라서 변경불가                              
//	//	*ptr2 = 100;  // 에러. ptr2의 타입이 'const int'라서 변경불가                     
//	ptr = &i;   // ptr은 상수가 아니라 변경가능                                    
//	ptr2 = &i2;  // ptr2는 상수가 아니라 변경가능                                   
//	//	PTR   = &i;   // 에러. PTR은 상수라서 변경불가                                   
//	//	PTR2  = &i2;  // 에러. PTR2는 상수라서 변경불가                                  
//	*ptr = 300;  // 이제 *ptr은  변수 i이므로 변경가능                               
//	//	*PTR  = 300;  // 에러. *PTR이 상수(MAX)라서 변경불가                             
//	*PTR2 = 111;  // OK. *PTR2가 변수 i라서 변경가능                                
//
//	printf("i=%d\n", i);
//	printf("*ptr =%d\n", *ptr);
//	printf("i=%d\n", i);
//	printf("*PTR=%d\n", *PTR);
//	printf("*PTR2=%d\n", *PTR2);
//	return 0;
//}

// 예제 7-10) 
//#include <stdio.h>                                           
//
//int main(void) {
//    int arr[4] = { 0,1,2,3 };
//    int* ptr = &arr[0];
//
//    printf("*ptr  =%d, ptr    =%p\n", *ptr, ptr);
//    printf("arr[0]=%d, &arr[0]=%p\n", arr[0], &arr[0]);
//    printf("arr[1]=%d, &arr[1]=%p\n", arr[1], &arr[1]);
//    printf("arr[2]=%d, &arr[2]=%p\n", arr[2], &arr[2]);
//    printf("arr[3]=%d, &arr[3]=%p\n", arr[3], &arr[3]);
//
//    return 0;
//}

// 예제 7-11) 
//#include <stdio.h>                                                          
//
//int main(void) {
//	char* pc = (char*)0x100;
//	short* ps = (short*)0x100;
//	int* pi = (int*)0x100;
//
//	printf("sizeof(char)  =%d\n", sizeof(char));
//	printf("sizeof(short) =%d\n", sizeof(short));
//	printf("sizeof(int)   =%d\n", sizeof(int));
//	printf("pc++=0x%x\tps++=0x%x\tpi++=0x%x\n", pc++, ps++, pi++);
//	printf("pc++=0x%x\tps++=0x%x\tpi++=0x%x\n", pc++, ps++, pi++);
//	printf("pc++=0x%x\tps++=0x%x\tpi++=0x%x\n", pc++, ps++, pi++);
//	printf("pc++=0x%x\tps++=0x%x\tpi++=0x%x\n", pc++, ps++, pi++);
//	printf("pc++=0x%x\tps++=0x%x\tpi++=0x%x\n", pc++, ps++, pi++);
//	return 0;
//}

// 예제 7-12) 

//#include <stdio.h>                                                   
//
//int main(void) {
//	int arr[] = { 0, 1, 2, 3, 4 };
//	int* ptr = &arr[0];
//	const int LEN = sizeof(arr) / sizeof(arr[0]);
//	int i;
//
//	// 포인터의 값을 1씩 증가시면서 출력.                                      
//	for (i = 0; i < LEN; i++)
//		printf("ptr++=%p, &arr[%d]=%p\n", ptr++, i, &arr[i]);
//	puts("");  // 줄바꿈                                              
//
//	ptr = &arr[0]; // 포인터 ptr의 값이 바뀌었으므로 다시 초기화               
//
//	// 포인터로 배열의 모든 요소를 출력                                        
//	for (i = 0; i < LEN; i++)
//		printf("*ptr++=%d, arr[%d]=%d\n", *ptr++, i, arr[i]);
//
//	return 0;
//}

// 예제 7-13) 
//#include <stdio.h>                                               
//#include <stdint.h>                                              
//
//int main(void) {
//	int arr[4];
//	int* ptr = (int*)0x110;
//	intptr_t diff;
//
//	printf("ptr-3 =%p\n", ptr - 3);
//	printf("ptr-2 =%p\n", ptr - 2);
//	printf("ptr-1 =%p\n", ptr - 1);
//	printf("ptr+0 =%p\n", ptr);
//	printf("ptr+1 =%p\n", ptr + 1);
//	printf("ptr+2 =%p\n", ptr + 2);
//	printf("ptr+3 =%p\n", ptr + 3);
//	printf("(char*)ptr+3=%p\n", (char*)ptr + 3);
//	printf("(unsigned)ptr+3=%x\n", (unsigned)ptr + 3);
//
//	diff = &arr[0] - &arr[2];
//	printf("&arr[0] - &arr[2]= %d\n", diff);
//
//
//	diff = (char*)&arr[0] - (char*)&arr[2];
//	printf("(char*)&arr[0] - (char*)&arr[2]= %d\n", diff);
//
//	return 0;
//}

// 예제 7-14) 
//#include <stdio.h>                                                      
//
//int main(void) {
//	int arr[4] = { 0,1,2,3 };
//	int* ptr = &arr[0];
//	int* ptr2;
//	int sum = 0;
//
//	ptr2 = ptr;  // ptr의 값을 ptr2로 복사. 이제 ptr2도 배열 arr을 가리키게 된다. 
//
//	printf("ptr =%p\n", ptr);
//	printf("ptr2=%p\n", ptr2);
//
//	if (ptr == ptr2) {
//		printf("ptr과 ptr2가 같은 대상을 가리킵니다.\n");
//	}
//	else {
//		printf("ptr과 ptr2가 다른 대상을 가리킵니다.\n");
//	}
//
//	while (ptr <= &arr[3])   // 배열 arr의 모든 요소를 출력한다.               
//		printf("*ptr++=%d\n", *ptr++);
//
//	while (ptr2 <= &arr[3])  // 배열 arr의 모든 요소를 더한다.                
//		sum += *ptr2++;
//
//	printf("sum=%d\n", sum);
//
//	return 0;
//}

// 예제 7-15) 
//#include <stdio.h>                                                     
//
//int main(void) {
//	int arr[4] = { 0,1,2,3 };
//	int* ptr = &arr[0];
//
//	printf("arr  =%p \t ptr  =%p\n", arr, ptr);
//	printf("arr+1=%p \t ptr+1=%p\n", arr + 1, ptr + 1);
//	printf("arr+2=%p \t ptr+2=%p\n", arr + 2, ptr + 2);
//	printf("arr+3=%p \t ptr+3=%p\n", arr + 3, ptr + 3);
//
//	printf("*arr    =%d \t *ptr    =%d\n", *arr, *ptr);
//	printf("*(arr+1)=%d \t *(ptr+1)=%d\n", *(arr + 1), *(ptr + 1));
//	printf("*(arr+2)=%d \t *(ptr+2)=%d\n", *(arr + 2), *(ptr + 2));
//	printf("*(arr+3)=%d \t *(ptr+3)=%d\n", *(arr + 3), *(ptr + 3));
//
//	printf("arr[0]=%d \t ptr[0]=%d\n", arr[0], ptr[0]);
//	printf("arr[1]=%d \t ptr[1]=%d\n", arr[1], ptr[1]);
//	printf("arr[2]=%d \t ptr[2]=%d\n", arr[2], ptr[2]);
//	printf("arr[3]=%d \t ptr[3]=%d\n", arr[3], ptr[3]);
//
//	return 0;
//}

// 예제 7-16) 
//#include <stdio.h>                                         
//
//int main(void) {
//	int arr[4] = { 0,1,2,3 };
//	int* ptr = arr;
//
//	printf("arr=%p\n", arr);
//	printf("ptr=%p\n", ptr);
//	printf("arr==ptr? %d\n", arr == ptr);
//	printf("arr!=ptr? %d\n", arr != ptr);
//
//	printf("arr+1 < ptr? %d\n", arr + 1 < ptr);
//	printf("sizeof(arr)=%d\n", sizeof(arr));
//	printf("sizeof(arr+1)=%d\n", sizeof(arr + 1));
//	printf("sizeof(ptr)=%d\n", sizeof(ptr));
//	printf("sizeof(arr-ptr)=%d\n", sizeof(arr - ptr));
//
//	return 0;
//}

// 예제 7-17) 
//#include <stdio.h>                                                    
//
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

