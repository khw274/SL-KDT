/* ********************************************************
* File name   : D0105_work_김현우.c
* Description : C언어의 정석:   
* Author      : HyeonWoo
* History     : 2025.01.05 HyeonWoo
* **********************************************************/
// 예제 5-30 ------------------------------------------------
//#include <stdio.h>                                                              
//#define SIZE 10                                                                 
//
//int main(void) {
//	char board[SIZE][SIZE] = { 0 };  // 모든 요소를 0으로 초기화                    
//	char shipBoard[SIZE - 1][SIZE - 1] = {
//		//  1  2  3  4  5  6  7  8  9                                         
//		  { 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 1                             
//		  { 1, 1, 1, 1, 0, 0, 1, 0, 0 }, // 2                             
//		  { 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 3                             
//		  { 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 4                             
//		  { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 5                             
//		  { 1, 1, 0, 1, 0, 0, 0, 0, 0 }, // 6                             
//		  { 0, 0, 0, 1, 0, 0, 0, 0, 0 }, // 7                             
//		  { 0, 0, 0, 1, 0, 0, 0, 0, 0 }, // 8                             
//		  { 0, 0, 0, 0, 0, 1, 1, 1, 0 }, // 9                             
//	};
//
//	int i, j;
//	int x, y;
//
//
//	// 0행에 행번호를, 0열에 열번호를 저장한다.                                               
//	for (i = 1; i < SIZE; i++) {
//		board[0][i] = board[i][0] = i + '0';
//	}
//
//	while (1) {
//		printf("좌표를 입력하세요.(종료는 0 0)>");
//		scanf("%d %d", &x, &y);
//
//		if (x == 0 || y == 0) { // x 또는 y의 값이 0이면 반복문을 벗어난다.           
//			break;
//		}
//		else if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
//			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
//			continue;
//		}
//
//		// shipBoard[x-1][y-1]의 값이 1이면, 'O'를 board[x][y]에 저장한다.     
//		board[x][y] = shipBoard[x - 1][y - 1] ? 'O' : 'X';
//
//		// 배열 board의 내용을 화면에 출력한다.                                 
//		for (i = 0; i < SIZE; i++) {
//			for (j = 0; j < SIZE; j++) {
//				printf("%c", board[i][j]);
//			}
//			puts("");
//		}
//		puts("");
//	}
//
//	return 0;
//}

// 예제 5-31 ------------------------------------------------
//#include <stdio.h>                                                       
//#include <time.h>                                                        
//#include <stdlib.h>                                                      
//
//#define SIZE 5                                                           
//
//int main(void) {
//	int bingo[SIZE][SIZE];
//	int i, j, x, y, tmp, num;
//
//	// 배열의 모든 요소를 1부터 SIZE*SIZE까지의 숫자로 초기화                    
//	for (i = 0; i < SIZE * SIZE; i++) {
//		bingo[i / SIZE][i % SIZE] = i + 1;
//	}
//
//	// 배열에 저장된 값을 뒤섞는다.(shuffle)                                 
//	srand(time(NULL));
//
//	for (i = 0; i < SIZE * SIZE * 2; i++) {
//		x = rand() % SIZE;
//		y = rand() % SIZE;
//
//		// 1행 1열의 값(bingo[0][0])과 임의로 선택된 값(bingo[x][y])을 바꾼
//		tmp = bingo[0][0];
//		bingo[0][0] = bingo[x][y];
//		bingo[x][y] = tmp;
//	}
//
//	do {
//		for (i = 0; i < SIZE; i++) {
//			for (j = 0; j < SIZE; j++)
//				printf("%2d ", bingo[i][j]);
//			puts("");
//		}
//		puts("");
//
//		printf("1~%d의 숫자를 입력하세요.(종료:0)>", SIZE * SIZE);
//		scanf("%d", &num);
//
//		for (i = 0; i < SIZE * SIZE; i++) {
//			if (bingo[i / SIZE][i % SIZE] == num) {
//				bingo[i / SIZE][i % SIZE] = 0;
//				break;
//			}
//		}
//	} while (num != 0);
//
//	return 0;
//}
// 예제 5-32 ------------------------------------------------
//#include <stdio.h>                                                                    
//
//int main(void) {
//	int m1[2][3] = {
//		{1, 2, 3},
//		{4, 5, 6}
//	};
//	int m2[3][2] = {
//		{1, 2},
//		{3, 4},
//		{5, 6}
//	};
//
//
//	int m3[sizeof(m1) / sizeof(m1[0])][sizeof(m2[0]) / sizeof(m2[0][0])] = { 0 };
//
//	const int ROW = sizeof(m1) / sizeof(m1[0]);
//	const int COL = sizeof(m2[0]) / sizeof(m2[0][0]);
//	const int M2_ROW = sizeof(m2) / sizeof(m2[0]);
//
//	int i, j, k;
//
//	// 행렬곱 m1×m2의 결과를 m3에 저장                                                  
//	for (i = 0; i < ROW; i++) {
//		for (j = 0; j < COL; j++) {
//			for (k = 0; k < M2_ROW; k++) {
//				m3[i][j] += m1[i][k] * m2[k][j];
//			}
//		}
//	}
//
//	// 행렬 m3를 출력                                                                
//	for (i = 0; i < ROW; i++) {
//		for (j = 0; j < COL; j++)
//			printf("%3d ", m3[i][j]);
//		puts("");
//	}
//
//	return 0;
//}
// 예제 5-33 ------------------------------------------------
//#include <stdio.h>                                                             
//#include <stdlib.h>                                                            
//#include <time.h>                                                              
//#include <string.h>                                                            
//
//#define LEN 11                                                                 
//
//int main(void) {
//	char words[][LEN] = { "television", "computer", "mouse", "phone" };
//	char question[LEN];
//	char answer[50];
//
//	int i, j, n, word_len;
//	char tmp;
//
//	const int WORD_CNT = sizeof(words) / sizeof(words[0]);
//
//	srand((unsigned)time(NULL));
//
//	for (i = 0; i < WORD_CNT; i++) {
//		word_len = strlen(words[i]);
//		strcpy(question, words[i]);  // 단어를 배열 question에 복사         
//
//		for (j = 0; j < word_len; j++) {
//			n = rand() % word_len;
//
//			tmp = question[j];
//			question[j] = question[n];
//			question[n] = tmp;
//		}
//
//		printf("Q%d. %s의 정답을 입력하세요.>", i + 1, question);
//		gets(answer);
//
//		if (strcmp(words[i], answer) == 0)
//			printf("맞았습니다.\n");
//		else
//			printf("틀렸습니다.\n");
//	}
//	return 0;
//}
// 예제 5-34 ------------------------------------------------
//#include <stdio.h>                                                                
//
//int main(void) {
//	char input[11];
//	char morse[][5] = {
//		".-", "-...", "-.-.","-..", "."        // a, b, c, d, e           
//		,"..-.", "--.", "....","..",".---"     // f, g, h, i, j          
//		, "-.-", ".-..", "--", "-.", "---"     // k, l, m, n. o           
//		, ".--.", "--.-",".-.","...","-"       // p, q, r, s, t           
//		, "..-", "...-", ".--", "-..-","-.--"  // u, v, w, x, y          
//		, "--.."                               // z                       
//	};
//	int i;
//
//	printf("모르스부호로 변환할 단어(10자 이하의 영소문자)를 입력하세요.>");
//	scanf("%10s", input);
//
//	for (i = 0; input[i]; i++)
//		printf("%s", morse[input[i] - 'a']);
//	printf("\n");
//
//	return 0;
//}
// 예제 5-35 ------------------------------------------------
//#include <stdio.h>                                                                   
//#define STU 4  // 학생수                                                               
//#define SUB 3  // 과목수                                                               
//
//int main(void) {
//	int score[STU + 1][SUB + 1] = {
//		{ 100, 100, 100 },
//		{  25,  20,  20 },
//		{  35,  30,  30 },
//		{  45,  40,  40 }
//	};
//	int i, j;
//
//	printf("번호 국어 영어 수학 총점  평균\n");
//	printf("===============================\n");
//
//	for (i = 0; i < STU; i++) {
//		printf(" %d   ", i + 1);
//
//		for (j = 0; j < SUB; j++) {
//			score[i][SUB] += score[i][j];
//			score[STU][j] += score[i][j];
//			printf("%3d  ", score[i][j]);
//		}
//		// 학생별 총점과 평균을 출력                                                
//		printf(" %3d  %5.1f\n", score[i][SUB], score[i][SUB] / (float)SUB);
//	}
//	printf("===============================\n");
//	printf("총점 ");
//
//	for (j = 0; j < SUB; j++)
//		printf("%3d  ", score[STU][j]);
//	puts("");
//
//	return 0;
//}
// 예제 5-36 ------------------------------------------------
//#include <stdio.h>                                                                         
//#define STU 4  // 학생수                                                                     
//#define SUB 3  // 과목수                                                                     
//
//int main(void) {
//	int score[][STU + 1][SUB + 1] = {
//		{ // 1반                                                                    
//			{ 100, 100, 100 },  // 1반 1번                                      
//			{  90,  90,  90 },  // 1반 2번                                      
//			{  80,  80,  80 },  // 1반 3번                                      
//			{  70,  70,  70 },  // 1반 4번                                      
//		},
//
//		{ // 2반                                                                    
//			{  95,  95,  90 },  // 2반 1번                                      
//			{  85,  85,  80 },  // 2반 2번                                      
//			{  75,  75,  70 },  // 2반 3번                                      
//			{  65,  65,  60 }   // 2반 4번                                      
//		}
//	};
//
//	const int BAN = sizeof(score) / sizeof(score[0]);
//	int i, j, k;
//
//	for (i = 0; i < BAN; i++) {
//		printf("[%d반]\n", i + 1);
//		printf("번호 국어 영어 수학 총점  평균\n");
//		printf("===============================\n");
//
//		for (j = 0; j < STU; j++) {
//			printf(" %d   ", j + 1);
//
//			for (k = 0; k < SUB; k++) {
//				score[i][j][SUB] += score[i][j][k];
//				score[i][STU][k] += score[i][j][k];
//
//				printf("%3d  ", score[i][j][k]);
//			}
//			// 학생별 총점과 평균을 출력                                              
//			printf("%4d  %5.1f\n",
//				score[i][j][SUB], score[i][j][SUB] / (float)SUB);
//		}
//
//		printf("===============================\n");
//		printf("총점 ");
//
//		for (k = 0; k < SUB; k++) {
//			printf("%3d  ", score[i][STU][k]);
//		}
//
//		printf("\n\n");
//	}
//
//	return 0;
//}
// 예제 5-37 ------------------------------------------------
//#include <stdio.h>                                                            
//#include <string.h>                                                           
//
//int main(void) {
//	char words[][2][10] = {
//		{"chair","의자"},       // words[0][0], words[0][1]            
//		{"computer","컴퓨터"},   // words[1][0], words[1][1]           
//		{"integer","정수"}      // words[2][0], words[2][1]            
//	};
//	char answer[20];
//
//	int i;
//
//	const int WORD_CNT = sizeof(words) / sizeof(words[0]);
//
//	for (i = 0; i < WORD_CNT; i++) {
//		printf("Q%d. %s의 뜻은?", i + 1, words[i][0]);
//		scanf("%s", answer);
//
//		if (strcmp(words[i][1], answer) == 0) {
//			printf("정답입니다.\n\n");
//		}
//		else {
//			printf("틀렸습니다. 정답은 %s입니다.\n\n", words[i][1]);
//		}
//	}
//	printf("\n");
//
//	return 0;
//}
// 퀴즈 5-6 ------------------------------------------------
//#include <stdio.h>
//// #include <string.h> // strlen() . 을 사용하려면 필요
//int main(void) {
//	char word[100]; // = {0}; // . 넉넉하게 크기를 잡는다
//	int i, n;
//	printf("단어를 하나만 입력하세요 .>"); 
//	scanf("%s", word);
//
//	printf("입력한 단어 :%s\n", word); 
//
//	// . 입력한 문자의 수를 센다
//	for (i = 0; word[i] != '\0'; i++); // for(i=0;word[i];i++);와 동일
//	
//	printf("입력한 단어의 문자개수 :%d\n", i); 
//	// printf(" 입력한 단어의 문자개수 :%d\n", strlen(word));
//
//	return 0;
//}
// 퀴즈 5-7 ------------------------------------------------
//#include <stdio.h>
//int main(void) {
//	int arr[3][3] = { {1,2},{3,4},{5,6} };
//	// int arr[3][3] = {{1,2,0},{3,4,0},{5,6,0}}; // 윗 문장과 동일
//	
//	int arr2[3][3] = { 1,2,3,4,5,6 }; // 1행 1열부터 순서대로 채운다
//	int i, j;
//
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			printf("arr[%d][%d]=%d\tarr2[%d][%d]=%d\n", i, j, arr[i][j],
//				i, j, arr2[i][j]);
//	printf("\n");
//	return 0;
//}
// 퀴즈 5-8 ------------------------------------------------
//#include <stdio.h>
//#define ROW 4
//#define COL 3
//int main(void) {
//	int score[ROW][COL] = {
//	{ 100, 100, 100 },
//	{ 20, 20, 20 },
//	{ 30, 30, 30 },
//	{ 40, 40, 40 }
//	};
//	int i, j, sum;
//	// 배열의 모든 요소를 테이블 형태로 출력한다
//	for (i = 0; i < ROW; i++) {
//		sum = 0;
//		for (j = 0; j < COL; j++) {
//			printf("%3d ", score[i][j]);
//			sum += score[i][j]; // 각 요소의 값을 sum에 누적한다
//		}
//		printf("sum=%d\n", sum);
//	}
//	return 0;
//}
// 퀴즈 5-9 ------------------------------------------------
//#include <stdio.h>
//
//int main(void) {
//	int i, j;
//	for (i = 0; i < 3; i++)
//		for (j = 0; j < 3; j++)
//			printf("%d\t%d\t%d\n", i, j, i * 3 + j);
//	return 0;
//}
// 퀴즈 5-10 -----------------------------------------------
//int score[3][8][30][10]; // 3개 학년 * 8개 학급 * 30명 * 10과목
// 퀴즈 5-11 -----------------------------------------------
//#include<stdio.h>
//int main(void) {
//	int score[2][4][3] = {
//	{ // 1반
//	{ 100, 100, 100 }, // 1반 1번  
//	{ 90, 90, 90 }, // 1반 2번  
//	{ 80, 80, 80 }, // 1반 3번  
//	{ 70, 70, 70 }, // 2반 4번  
//	},
//	{ // 2반
//	{ 95, 95, 90 }, // 2반 1번  
//	{ 85, 85, 80 }, // 2반 2번  
//	{ 75, 75, 70 }, // 2반 3번 
//	{ 65, 65, 60 }, // 2반 4번  
//	}
//	};
//	int i, j, k, sum;
//	const int BAN = sizeof(score) / sizeof(score[0]);
//	const int BUN = sizeof(score[0]) / sizeof(score[0][0]);
//	const int SUB = sizeof(score[0][0]) / sizeof(score[0][0][0]);
//	for (i = 0; i < BAN; i++) {
//		printf("[%d반]\n", i + 1); 
//			for (j = 0; j < BUN; j++) {
//				printf("%d-%d번", i + 1, j + 1); 
//					sum = 0;
//				for (k = 0; k < SUB; k++) {
//					printf("%3d ", score[i][j][k]);
//					sum += score[i][j][k];
//				}
//				printf(" sum=%d", sum);
//				puts(""); // printf("\n");
//			}
//
//			puts("");
//	}
//	return 0;
//}

// 퀴즈 5-12 ------------------------------------------------
//#include<stdio.h>
//int main(void) {
//	int score[][3] = {
//	{ 100, 100, 100 },
//	{ 25, 20, 20 },
//	{ 35, 30, 30 },
//	{ 45, 40, 40 }
//	};
//	const int ROW = sizeof(score) / sizeof(score[0]);
//	const int COL = sizeof(score[0]) / sizeof(score[0][0]);
//	int koreanTotal = 0, englishTotal = 0, mathTotal = 0;
//	int totalSum = 0;
//	int sum, i, j;
//	printf("번호 국어 영어 수학 총점 평균 \n"); 
//		printf("===============================\n");
//	for (i = 0; i < ROW; i++) {
//		sum = 0;
//		koreanTotal += score[i][0];
//		englishTotal += score[i][1];
//		mathTotal += score[i][2];
//		printf(" %d ", i + 1);
//		for (j = 0; j < COL; j++) {
//			sum += score[i][j];
//			totalSum += score[i][j];
//			printf("%3d ", score[i][j]);
//		}
//		printf(" %3d %5.1f\n", sum, sum / (float)COL);
//	}
//	printf("===============================\n");
//	printf("총점 %3d %3d %3d %3d %5.1f\n", koreanTotal, englishTotal, 
//		mathTotal, totalSum, totalSum / (float)(ROW * COL));
//	return 0;
//}
// 퀴즈 5-13 ------------------------------------------------
//#include <stdio.h>
//#define STU 4 // 학생수
//#define SUB 3 // 과목수
//int main(void) {
//	int score[][STU + 1][SUB + 1] = {
//	{ // 1반
//	{ 100, 100, 100 }, // 1반 1번
//	{ 90, 90, 90 }, // 1반 2번  
//	{ 80, 80, 80 }, // 1반 3번  
//	{ 70, 70, 70 } // 1반 4번 
//	},
//	{ // 2반
//	{ 95, 95, 90 }, // 2반 1번  
//	{ 85, 85, 80 }, // 2반 2번  
//	{ 75, 75, 70 }, // 2반 3번  
//	{ 65, 65, 60 } // 2반 4번  
//	}
//	};
//	const int BAN = sizeof(score) / sizeof(score[0]);
//	int i, j, k;
//	for (i = 0; i < BAN; i++) {
//		printf("[%d 반]\n", i + 1); 
//			printf("번호 국어 영어 수학 총점 평균 \n"); 
//			printf("===============================\n");
//		for (j = 0; j < STU; j++) {
//			printf(" %d ", j + 1);
//				for (k = 0; k < SUB; k++) {
//					score[i][j][SUB] += score[i][j][k];
//					score[i][STU][k] += score[i][j][k];
//					score[i][STU][SUB] += score[i][j][k];
//					printf("%3d ", score[i][j][k]);
//				}
//			// 학생별 총점과 평균을 출력
//			printf("%4d %5.1f\n",
//				score[i][j][SUB], score[i][j][SUB] / (float)SUB);
//		}
//		printf("===============================\n");
//		printf(" 총점 "); 
//			// score[i][STU][SUB]  도 출력하기 위해 <=로 변경
//			for (k = 0; k <= SUB; k++) {
//				printf("%3d ", score[i][STU][k]);
//			}
//		// 전체 총점(score[i][STU][SUB])을 학생수 * 과목수로 나눠서 전체 평균을 구한다
//		printf("%5.1f ", (float)score[i][STU][SUB] / (STU * SUB));
//		printf("\n\n");
//	}
//	return 0;
//}
// 퀴즈 5-14 ------------------------------------------------
//#include <stdio.h>
//#include <string.h>
//int main(void) {
//	char words[][2][10] = {
//	{ "chair","의자" }, // words[0][0], words[0][1] 
//	{ "computer","컴퓨터" }, // words[1][0], words[1][1] 
//	{ "integer","정수" } // words[2][0], words[2][1] 
//	};
//	char answer[20];
//	int i, rightAnswer = 0;
//	const int WORD_CNT = sizeof(words) / sizeof(words[0]);
//	for (i = 0; i < WORD_CNT; i++) {
//		printf("Q%d. %s ?", i + 1, words[i][0]); 
//			scanf("%s의 뜻은", answer);
//		if (strcmp(words[i][1], answer) == 0) {
//			printf("정답입니다 .\n\n"); 
//				rightAnswer++;
//		}
//		else {
//			printf("틀렸습니다. 정답은 %s입니다.\n\n", words[i][1]);   
//		}
//	}
//	printf("전체 %d문제 중 %d문제 맞추셨습니다 .\n", i, rightAnswer);     
//		return 0;
//}