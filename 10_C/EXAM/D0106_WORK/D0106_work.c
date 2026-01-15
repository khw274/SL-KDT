/* *******************************************************************
* File name    : D0106_work.c
* subFile name : X
* Description  : C언어의 정석 - 6장 함수
* Author       : HyeonWoo
* History      : 2026.01.06 HyeonWoo
* ********************************************************************/
// 예제 6-1) ----------------------------------------------------------
//#include <stdio.h>                                                                 
//
//int multiply(int x, int y) {
//	int result = x * y;
//
//	return result;
//}
//
//int getUserInput(void) {
//	int num;
//
//	printf("input a number(2~9) :");
//	scanf("%d", &num);
//
//	return num;
//}
//
//void printGugudan(int dan) {
//	int i;
//	for (i = 1; i <= 9; i++) {
//		int result = multiply(dan, i);// int multiply(int x, int y)를 호출   
//		printf("%d*%d=%2d\n", dan, i, result);
//	}
//}
//
//void printGugudanAll(void) {
//	int i, j;
//	for (i = 1; i <= 9; i++) {
//		for (j = 2; j <= 9; j++)
//			printf("%d*%d=%2d ", j, i, multiply(j, i));
//		printf("\n");
//	}
//}
//
//int main(void) {
//	int dan = getUserInput();  // int getUserInput(void)를 호출                  
//
//	if (2 <= dan && dan <= 9)
//		printGugudan(dan);  // void printGugudan(int dan)을 호출             
//	else
//		printGugudanAll();  // void printGugudanAll(void)을 호출             
//
//	return 0;
//}
// 예제 6-2) ----------------------------------------------------------
//#include <stdio.h>                                                               
//
//int add(int x, int y) {
//	int result = x + y;
//	printf("add(%d, %d)이 호출되었습니다.\n", x, y);
//	return result;
//}
//
//int mul(int x, int y) {
//	int result = x * y;
//	printf("mul(%d, %d)이 호출되었습니다.\n", x, y);
//	return result;
//}
//
//int main(void) {
//	printf("main() - add(3,5)=%d, mul(3,5)=%d\n", add(3, 5), mul(3, 5));
//
//	return 0;
//}
// 예제 6-3) ----------------------------------------------------------
//#include <stdio.h>                               
//
//int add(int x, int y) {
//	int result = x + y;
//	return result;
//}
//
//int main(void) {
//	printf("%d\n", add(1, add(2, 3)));
//
//	return 0;
//}
// 예제 6-3) ----------------------------------------------------------
#include <stdio.h>                               

int add(int x, int y) {
	int result = x + y;
	return result;
}

int main(void) {
	printf("%d\n", add(1, add(2, 3)));

	return 0;
}
// 예제 6-4) ----------------------------------------------------------
//#include <stdio.h>                                                     
//
//int multiply(int x, int y) { return x * y; }
//int abs(int x) { return x > 0 ? x : -x; }
//int diff(int x, int y) { return abs(x - y); }
//int max(int x, int y) { return x > y ? x : y; }
//int min(int x, int y) { return x < y ? x : y; }
//
//int main(void) {
//	int x = 3;
//	int y = 5;
//
//	printf("multiply(%d, %d)=%d\n", x, y, multiply(x, y));
//	printf("abs(%d)=%d\n", -y, abs(-y));
//	printf("diff(%d, %d)=%d\n", x, y, diff(x, y));
//	printf("max(%d, %d)=%d\n", x, y, max(x, y));
//	printf("min(%d, %d)=%d\n", x, y, min(x, y));
//
//	return 0;
//}
// 예제 6-5) ----------------------------------------------------------
#include <stdio.h>                                                    

int divide(int x, int y) {
	if (y == 0) return 0; // 이 문장을 주석처리하면 비정상 종료된다.         

	return x / y;
}

int main(void) {
	int x = 4, y = 2;

	printf("%d/%d=%d\n", x, y, divide(x, y));

	y = 0;
	printf("%d/%d=%d\n", x, y, divide(x, y));
	return 0;
}
// 예제 6-6) ----------------------------------------------------------
//#include <stdio.h>                                                            
//
//int  multiply(int x, int y);   // 두 수를 곱한 결과를 반환                          
//int  getUserInput(void);       // 사용자의 입력받아서 반환                           
//void printGugudan(int dan);    // 지정된 단(dan)을 출력                           
//void printGugudanAll(void);    // 구구단 전체를 출력                               
//
//int main(void) {
//	int dan = getUserInput();  	// int getUserInput(void)를 호출           
//
//	if (2 <= dan && dan <= 9)
//		printGugudan(dan);      // void printGugudan(int dan)을 호출       
//	else
//		printGugudanAll();      // void printGugudanAll(void)을 호출       
//
//	return 0;
//}
//
//int multiply(int x, int y) { return x * y; }
//int getUserInput(void) {
//	int num;
//	printf("input a number(2~9) :");
//	scanf("%d", &num);
//	return num;
//}
//
//void printGugudan(int dan) {
//	int i;
//	for (i = 1; i <= 9; i++)
//		printf("%d*%d=%2d\n", dan, i, multiply(dan, i));
//}
//
//void printGugudanAll(void) {
//	int i, j;
//	for (i = 1; i <= 9; i++) {
//		for (j = 2; j <= 9; j++)
//			printf("%d*%d=%2d ", j, i, multiply(j, i));
//		printf("\n");
//	}
//}
// 예제 6-7) ----------------------------------------------------------
//int  multiply(int x, int y);
//int  getUserInput(void);
//void printGugudan(int dan);
//void printGugudanAll(void);
//
//int main(void) {
//	int dan = getUserInput();  // int getUserInput(void)¸¦ È£Ãâ               
//
//	if (2 <= dan && dan <= 9) {
//		printGugudan(dan);  // void printGugudan(int dan)À» È£Ãâ          
//	}
//	else {
//		printGugudanAll();  // void printGugudanAll(void)À» È£Ãâ          
//	}
//
//	return 0;
//}
// 예제 6-8) ----------------------------------------------------------
//#include <stdio.h>                                                                                 
//#include "header.h"                                                                                
//
//int main(void) {
//	int dan = getUserInput();  // int getUserInput(void)¸¦ È£Ãâ                                     
//
//	if (2 <= dan && dan <= 9) {
//		printGugudan(dan); 	// void printGugudan(int dan)À» È£Ãâ                            
//	}
//	else {
//		printGugudanAll();  	// void printGugudanAll(void)À» È£Ãâ                            
//	}
//
//	return 0;
//}
// 예제 6-9) ----------------------------------------------------------
//#include <stdio.h>             
//
//void second(void) {
//	printf("second()\n");
//}
//
//void first(void) {
//	second();
//}
//
//int main(void) {
//	first();
//	return 0;
//}
// 예제 6-10) ----------------------------------------------------------

//#include <stdio.h>                                                 
//
//void second(void) {
//	printf("\t\tsecond() - start\n");
//	printf("\t\t\tprintf(\"second()\")\n");
//	printf("\t\tsecond() - end\n");
//}
//
//void first(void) {
//	printf("\tfirst() - start\n");
//	second();
//	printf("\tfirst() - end\n");
//}
//
//int main(void) {
//	printf("main() - start\n");
//	first();
//	printf("main() - end\n");
//
//	return 0;
//}

// 예제 6-11) ----------------------------------------------------------
//#include <stdio.h>                                            
//
//int factorial(int n) {
//	if (n == 1) return 1;  // n의 값이 1이면, 1을 반환한다.           
//
//	return n * factorial(n - 1); // 재귀 호출                     
//}
//
//int main(void) {
//	int result = factorial(5);
//
//	printf("%d!=%d\n", n, result);
//
//	return 0;
//}
// 예제 6-12) ----------------------------------------------------------

//#include <stdio.h>                                                                   
//
//long long factorial(int n) {
//	if (n <= 0 || n > 20) return -1;  // 매개변수의 유효성 검사.                             
//	if (n <= 1)
//		return 1;
//
//	return n * factorial(n - 1);
//}
//
//int main(void) {
//	int i = 0;
//	int n = 21;
//	long long result = 0;
//
//	for (i = 1; i <= n; i++) {
//		result = factorial(i);
//
//		if (result == -1) {
//			printf("유효하지 않은 값입니다.(0<n<=20):%d\n", n);
//			break;
//		}
//		printf("%2d!=%20lld\n", i, result);
//	}
//
//	return 0;
//}

// 예제 6-13) ----------------------------------------------------------

//#include <stdio.h>                                 
//
//long long power(int x, int n) {
//	if (n == 1)
//		return x;
//	return x * power(x, n - 1);
//}
//
//int main(void) {
//
//	int i, x = 2, n = 5;
//	long long result = 0;
//
//	for (i = 1; i <= n; i++)
//		result += power(x, i);
//
//	printf("result=%d\n", result);
//	return 0;
//}

// 예제 6-14) ----------------------------------------------------------
//#include <stdio.h>                                                       
//
//void func1() {
//	int tmp = 100;
//	int i;
//
//	for (i = 0; i < 1; i++) {
//		printf("[1]tmp=%d\n", tmp); // [1]tmp=100. C99이전에서는 에러   
//
//		int tmp = 200; // OK. 블럭이 다르면 이름이 같아도 됨.               
//		printf("[2]tmp=%d\n", tmp); // [2]tmp=200	            
//	}
//	printf("[3]tmp=%d\n", tmp);    	// [3]tmp=100                       
//}
//
//int main(void) {
//	func1();
//	return 0;
//}

// 예제 6-15) ----------------------------------------------------------

//#include <stdio.h>                                                                   
//
//int x; // 전역 변수. 함수 밖에 선언                                                        
//
//void func1(void) {
//	int y;  // 지역 변수. 함수 안에 선언                                                  
//	x = 1;  // OK                                                                   
//	y = 2;  // OK                                                                   
//	//	z = 3;  // 에러                                                                  
//	//	x2 = 4; // 에러. 컴파일러는 변수 x2에 대한 정보가 아직 없음.                                
//
//	printf("func1() x=%d\n", x);
//	printf("func1() y=%d\n", y);
//	//	printf("func1() z=%d\n", z);   // 에러.                                          
//}
//
//int x2; // 전역변수. 함수 밖에 선언                                                        
//
//void func2(void) {
//	int z; // 지역 변수. 함수 안에 선언                                                   
//	x = 10; // OK                                                                  
//	//	y  = 20; // 에러. 유효하지 않은 변수                                                  
//	z = 30; // OK                                                                  
//	x2 = 40; // OK. 변수 x2에 대한 정보를 알고 있음.                                        
//
//	printf("func2() x=%d\n", x);
//	//	printf("func2() y=%d\n", y);   // 에러. 유효하지 않은 변수                            
//	printf("func2() z=%d\n", z);
//	printf("func2() x2=%d\n", x2);
//}
//
//int main(void) {
//	func1();
//	func2();
//	return 0;
//}

// 예제 6-16) ----------------------------------------------------------
//#include <stdio.h>                                        
//
//int x = 100; // 전역 변수. 함수 밖에 선언                       
//
//int main(void) {
//	printf("x=%d\n", x); // x=100                        
//
//	int x = 200; // 지역 변수. 함수 안에 선언                  
//
//	printf("x=%d\n", x); // x=100? 200?  200!!!          
//
//	return 0;
//}
// 예제 6-17) ----------------------------------------------------------
//#include <stdio.h>                               
//
//int gv = 100; // 전역 변수의 정의적 선언. 초기화해야 한다.  
//
//void printGv(void);
//
//int main(void) {
//	printf("main() - gv=%d\n", gv);
//	printGv();
//
//	return 0;
//}
// 예제 6-19) ----------------------------------------------------------

//#include <stdio.h>                                                                    
//
//static int sv;       	// 정적 변수 - 함수 밖에 선언. 유효범위는 소스파일 전체               
//
//void func1() {
//	static 	int sv2 = 1;  // 정적 변수 - 함수 안에 선언. 유효범위는 함수 내부                    
//	int lv = 1;	// 지역 변수                                        
//
//	printf("func1() - sv2=%d, lv=%d\n", sv2++, lv++);
//}
//
//void func2() {
//	sv = 100;
//	printf("func2() - sv =%d\n", sv);
//	//	printf("func2() - sv2=%d\n", sv2); // 에러. 정적 변수 sv2가 유효하지 않음.               
//}
//
//int main(void) {
//	func1();
//	func1();
//	func1();
//	func2();
//
//	return 0;
//}
// 예제 6-20) ----------------------------------------------------------
//#include <stdio.h>                                                             
//
//int gv = 100;   // 정의적 선언. extern을 붙일 수 있는 경우도 있으나 붙이지 않는 것이 원칙      
//
//void   gfunc(void);    // 전역 함수의 선언. extern이 생략됨. sub4.c에 정의되어 있음       
//static void sfunc(void); // 정적 함수의 선언. 소스파일(main4.c)내에서만 사용가능           
//
//extern int main(void) {
//	gfunc(); // sub4.c의 gfunc()를 호출                                  
//	sfunc(); // main4.c의 sfunc()를 호출                                 
//	return 0;
//}
//
//static void sfunc(void) { // 정적 함수의 정의. 소스파일(main4 .c)내에서만 사용가능         
//	printf("sfunc() - main4.c\n");
//}
