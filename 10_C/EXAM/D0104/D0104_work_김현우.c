/* ********************************************************
* File name	  : D0104_work_김현우.c
* Description : 예제, 퀴즈 풀기
* Author      : HyeonWoo
* History	  : 2025.01.04 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	// 예제 5-6 ---------------------------------------------
	
	//int score[] = { 100, 88, 100, 100, 90 };                           
	//const int LEN = sizeof(score) / sizeof(score[0]);

	//int   i, sum = 0;	// 총점을 저장하기 위한 변수                      
	//float average = 0.0f;	// 평균을 저장하기 위한 변수                      

	//for (i = 0; i < LEN; i++) {
	//	sum += score[i]; // 배열의 각 요소를 변수 sum에 더한다.            
	//	printf("score[%d]=%d\tsum=%d\n", i, score[i], sum);
	//}

	//average = sum / (float)LEN; // 계산결과를 소수점수로 얻기 위해 float로 형변환  

	//printf("총점 : %d\n", sum);
	//printf("평균 : %4.1f\n", average);
	
	// 퀴즈 5-3 ---------------------------------------------
	
	/*int arr[] = { 10,20,30,40,50,60,70 };
	const int LEN = sizeof(arr) / sizeof(arr[0]);
	int i, oddSum = 0, evenSum = 0;
	for (i = 0; i < LEN; i++) {
		if (i % 2 != 0) {
			oddSum += arr[i];
		}
		else {
			evenSum += arr[i];
		}
	}
	printf("홀수번째 요소의 합 :%d\n", oddSum); 
	printf("짝수번째 요소의 합 :%d\n", evenSum);*/

	// 예제 5-7 ---------------------------------------------
	
	//int score[] = { 79, 88, 91, 33, 100, 55, 95 };

	//int max = score[0]; // 배열의 첫 번째 값으로 최대값을 초기화 한다.                         
	//int min = score[0]; // 배열의 첫 번째 값으로 최소값을 초기화 한다.                         

	//const int LEN = sizeof(score) / sizeof(score[0]);
	//int i;

	//// 배열의 두 번째 요소부터 읽기 위해서 변수 i의 값을 1로 초기화 했다.                           
	//for (i = 1; i < LEN; i++) {
	//	if (score[i] > max)
	//		max = score[i];
	//	else if (score[i] < min)
	//		min = score[i];
	//}

	//printf("최대값 : %d\n", max);
	//printf("최소값 : %d\n", min);
	
	// 예제 5-8 ---------------------------------------------
	
	//int numArr[10];
	//const int LEN = sizeof(numArr) / sizeof(numArr[0]);
	//int i, n, tmp;

	//srand((unsigned)time(NULL));

	//for (i = 0; i < LEN; i++) {
	//	numArr[i] = i;  // 배열을 0~9의 숫자로 초기화한다.               
	//	printf("%d", numArr[i]);
	//}
	//printf("\n");

	//for (i = 0; i < LEN * 2; i++) {
	//	n = rand() % 10;	// 0~9중의 한 값을 임의로 얻는다.       

	//	tmp = numArr[0];
	//	numArr[0] = numArr[n];
	//	numArr[n] = tmp;
	//}

	//for (i = 0; i < LEN; i++) {
	//	printf("%d", numArr[i]);
	//}
	//printf("\n");

	// 예제 5-9 ---------------------------------------------
	
	//int ball[45];   // 45개의 정수값을 저장하기 위한 배열 선언.             
	//const int LEN = sizeof(ball) / sizeof(ball[0]);
	//int i, n, tmp;

	//srand((unsigned)time(NULL));

	//// 배열의 각 요소에 1~45의 값을 저장한다.                              
	//for (i = 0; i < LEN; i++)
	//	ball[i] = i + 1;    // ball[0]에 1이 저장된다.                  

	//// 배열에 저장된 값을 섞는다.                                        
	//for (i = 0; i < LEN; i++) {
	//	n = rand() % 45;  // 배열 범위(0~44)의 임의의 값을 얻는다.        

	//	tmp = ball[i];
	//	ball[i] = ball[n];
	//	ball[n] = tmp;
	//}
	//// 배열 ball의 앞에서 부터 6개의 요소를 출력한다.                        
	//for (i = 0; i < 6; i++)
	//	printf("ball[%d]=%d\n", i, ball[i]);

	// 퀴즈 5-4 ---------------------------------------------
	
	//int ball[9]; // 9개의 정수값을 저장하기 위한 배열 선언
	//const int LEN = sizeof(ball) / sizeof(ball[0]);
	//int i, n, tmp;
	// 
	//srand((unsigned)time(NULL));
	// 
	//for (i = 0; i < LEN; i++)
	//	ball[i] = i + 1; // 배열에 1~9를 저장한다.
	//					 // 배열에 저장된 값을 섞는다.
	// 
	//for (i = 0; i < LEN; i++) {
	//	n = rand() % LEN; // (0~8) 배열 인덱스 범위 의 임의의 값을 얻는다
	
	//	tmp = ball[i];
	//	ball[i] = ball[n];
	//	ball[n] = tmp;
	//}
	//// 배열ball의 앞에서 부터 3개의 요소를 출력한다.
	//for (i = 0; i < 3; i++)
	//	printf("%d", ball[i]);
	//printf("\n");
	// 
	//return 0;

	// 예제 5-10 ---------------------------------------------
	//int code[] = { -4, -1, 3, 6, 11 };  // 불연속적인 값들로 구성된 배열      
	//int arr[LEN];
	//int i, tmp;
	//const int CODE_LEN = sizeof(code) / sizeof(code[0]);
	//
	//srand((unsigned)time(NULL));
	//
	//for (i = 0; i < LEN; i++) {
	//	tmp = rand() % CODE_LEN;
	//	arr[i] = code[tmp];
	//}
	//
	//for (i = 0; i < LEN; i++)
	//	printf("arr[%d]=%d\n", i, arr[i]);
	
	// 예제 5-11 ---------------------------------------------
	
	//int numArr[10];
	//const int LEN = sizeof(numArr) / sizeof(numArr[0]);
	//int i, j, k, tmp;
	//
	//int chk; // 자리바꿈이 발생했는지 확인하는 변수                                        
	//
	//srand((unsigned)time(NULL));
	//
	//for (i = 0; i < LEN; i++) {
	//	numArr[i] = rand() % 10;
	//	printf("%d", numArr[i]);
	//}
	//printf("\n");
	//
	//for (i = 0; i < LEN - 1; i++) {
	//	chk = 0; // 매 반복마다 chk를 0으로 초기화 한다.                             
	//
	//
	//	for (j = 0; j < LEN - 1 - i; j++) {
	//		if (numArr[j] > numArr[j + 1]) { // 옆의 값이 작으면 서로 바꾼다.       
	//			tmp = numArr[j];
	//			numArr[j] = numArr[j + 1];
	//			numArr[j + 1] = tmp;
	//
	//			chk = 1; // 자리바꿈이 발생했으니 chk를 1로 바꾼다.           
	//		}
	//	} // end for j                                                       
	//
	//	if (chk == 0) break;	// 자리바꿈이 없으면 반복문을 벗어난다.                
	//
	//	for (k = 0; k < LEN; k++)
	//		printf("%d", numArr[k]); // 정렬된 결과를 출력한다.                
	//	printf("\n");
	//} // end of for i    

	// 퀴즈 5-5 ---------------------------------------------
	 
	// int iArr[] = { 3, 7, 2, 4, 1, 5, 6 };
	
	//const int LEN = sizeof(iArr) / sizeof(iArr[0]);
	//int i, j, tmp;
	
	//int chk; // 자리바꿈이 발생했는지 확인하는 변수
	
	//for (i = 0; i < LEN - 1; i++) {
	//	chk = 0; // chk 0 . 매 반복마다 를 으로 초기화 한다
	//	for (j = 0; j < LEN - 1 - i; j++) {
	//		if (iArr[j] < iArr[j + 1]) { // . 옆의 값이 크면 서로 바꾼다
	//			tmp = iArr[j];
	//			iArr[j] = iArr[j + 1];
	//			iArr[j + 1] = tmp;
	//			chk = 1; // chk 1 . 자리바꿈이 발생했으니 를 로 바꾼다
	//		}
	//	} // end for j
	
	//	if (chk == 0) break; // . 자리바꿈이 없으면 반복문을 벗어난다
	//} // end of for i
	
	//for (i = 0; i < LEN; i++)
	//	printf("%d", iArr[i]); // . 정렬된 결과를 출력한다
	//printf("\n");
	
	// 예제 5-12 ---------------------------------------------
	
	//int number[10];
	//int counter[10] = { 0 };  // 배열의 모든 요소를 0으로 초기화                     
	//const int LEN = sizeof(number) / sizeof(number[0]);
	//int i;
	//
	//srand((unsigned)time(NULL));
	//
	//for (i = 0; i < LEN; i++) {
	//	number[i] = rand() % 10; // number[i]에 0~9범위의 임의의 수를 저장    
	//	printf("%d", number[i]);
	//}
	//printf("\n");
	//
	//for (i = 0; i < LEN; i++) {
	//	counter[number[i]]++;
	//}
	//
	//for (i = 0; i < LEN; i++) {
	//	printf("%d 의 개수 :%d\n", i, counter[i]);
	//}
}