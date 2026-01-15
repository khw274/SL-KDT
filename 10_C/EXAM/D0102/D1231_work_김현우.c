/* ********************************************************
* File name	  : D1231_work.c
* Description : 예제 풀기
* Author      : HyeonWoo
* History	  : 2025.01.02 HyeonWoo
* **********************************************************/
#include <stdio.h>
#include <string.h>

int main(void) {

	// 예제 4-1 ---------------------------------------------
	
	//int x = 0;

	//printf("x=%d 일때, 참인 것은\n", x);

	//if (x == 0) printf("x==0\n");
	//if (x != 0) printf("x!=0\n");
	//if (x)    printf("x\n");
	//if (!x)   printf("!x\n");

	//x = 1;
	//printf("\nx=%d 일때, 참인 것은\n", x);


	//if (x == 0) printf("x==0\n");
	//if (x != 0) printf("x!=0\n");

	//if (x)    printf("x\n");
	//if (!x)   printf("!x\n");

	//return 0;


	// 예제 4-2 ---------------------------------------------

	//int input;


	//printf("숫자를 하나 입력하세요.>");
	//scanf("%d", &input);

	//if (input == 0) {
	//	printf("입력하신 숫자는 0입니다.\n");
	//}

	//if (input != 0)
	//	printf("입력하신 숫자는 0이 아닙니다.\n");
	//printf("입력하신 숫자는 %d입니다.\n", input);  // if문에 속한 문장이 아님             

	//return 0;

	// 예제 4-3 ---------------------------------------------

	//int input;

	//printf("숫자를 하나 입력하세요.>");
	//scanf("%d", &input);

	//if (input == 0) {
	//	printf("입력하신 숫자는 0입니다.\n");

	//}
	//else { // input!=0인 경우                                
	//	printf("입력하신 숫자는 0이 아닙니다.\n");
	//}

	//return 0;

	// 퀴즈 4-1 ---------------------------------------------

	//if (num % 2 != 0) { // if(num%2) {
	//	printf("홀수\n"); 
	//}
	//else {
	//	printf("짝수\n"); 
	}

	// 예제 4-4 ---------------------------------------------

	//int  score;        // 점수를 저장하기 위한 변수                            
	//char grade = ' ';   // 학점을 저장하기 위한 변수. 공백으로 초기화한다.            


	//printf("점수를 입력하세요.>");
	//scanf("%d", &score);

	//if (score >= 90) {         // score가 90점 보다 같거나 크면 A학점          
	//	grade = 'A';
	//}
	//else if (score >= 80) {   // score가 80점 보다 같거나 크면 B학점          
	//	grade = 'B';
	//}
	//else if (score >= 70) {   // score가 70점 보다 같거나 크면 C학점          
	//	grade = 'C';
	//}
	//else {                   // 나머지는 D학점                            
	//	grade = 'D';
	//}

	//printf("당신의 학점은 %c입니다.\n", grade);

	//return 0;

	// 퀴즈 4-2 ---------------------------------------------

	//int main(void) {
	//	char ch;
	//	printf("하나의 문자를 입력하세요. >"); 
	//		scanf("%c", &ch);
	//	if ('A' <= ch && ch <= 'Z') {
	//		printf("대문자입니다.\n"); 
	//	}
	//	else if ('a' <= ch && ch <= 'z') {
	//		printf("소문자입니다.\n"); 
	//	}
	//	else if ('0' <= ch && ch <= '9') {
	//		printf("숫자입니다.\n"); 
	//	}
	//	else {
	//		printf("숫자나 영문자가 아닙니다.\n"); 
	//	}
	//	return 0;
	//}

	// 예제 4-5 ---------------------------------------------

	//int  score;
	//char grade;
	//char opt = '0';

	//printf("점수를 입력해주세요.>");
	//scanf("%d", &score);
	//printf("당신의 점수는 %d입니다.\n", score);

	//if (score >= 90) {       	// score가 90점 보다 같거나 크면 A학점(grade)               
	//	grade = 'A';
	//	if (score >= 98) {  	// 90점 이상 중에서도 98점 이상은 A+                        
	//		opt = '+';
	//	}
	//	else if (score < 94) {  // 90점 이상 94점 미만은 A-                            
	//		opt = '-';
	//	}
	//}
	//else if (score >= 80) {   	// score가 80점 보다 같거나 크면 B학점(grade)               
	//	grade = 'B';
	//	if (score >= 88) {
	//		opt = '+';
	//	}
	//	else if (score < 84) {
	//		opt = '-';
	//	}
	//}
	//else {	         	// 나머지는 C학점(grade)                                 
	//	grade = 'C';
	//}

	//printf("당신의 학점은 %c%c입니다.\n", grade, opt);

	// 퀴즈 4-3 ---------------------------------------------
	// 
	//int main(void) {
	//	int score;
	//	char grade = 'C'; // 'C' 처음부터 기본값으로 를 저장
	//	char opt = '0';
	//	printf("점수를 입력해주세요 .>"); 
	//		scanf("%d", &score);
	//	printf("당신의 점수는 입니다 %d .\n", score); 
	//		if (score >= 90) { // score 90 A (grade) 가 점 보다 같거나 크면 학점
	//			grade = 'A';
	//			if (score >= 98) { // 90 98 A+ 점 이상 중에서도 점 이상은
	//				opt = '+';
	//			}
	//			else if (score < 94) { // 90 94 A- 점 이상 점 미만은
	//				opt = '-';
	//			}
	//		}
	//		else if (score >= 80) { // score 80 B (grade) 가 점 보다 같거나 크면 학점
	//			grade = 'B';
	//			if (score >= 88) {
	//				opt = '+';
	//			}
	//			else if (score < 84) {
	//				opt = '-';
	//			}
	//		}
	//	// else { // C (grade) 나머지는 학점
	//	// grade = 'C';
	//	// }
	//	printf("당신의 학점은 입니다 %c%c .\n", grade, opt); 
	//		return 0;
	//}
	
	// 예제 4-6 ---------------------------------------------
	
	//int month;

	//printf("현재 월을 입력하세요.>");
	//scanf("%d", &month);  // 입력받은 값을 month에 저장한다.            

	//switch (month) {
	//case 3:
	//case 4:
	//case 5:
	//	printf("현재의 계절은 봄입니다.\n");
	//	break;
	//case 6: case 7: case 8:
	//	printf("현재의 계절은 여름입니다.\n");
	//	break;
	//case 9: case 10: case 11:
	//	printf("현재의 계절은 가을입니다.\n");
	//	break;
	//default:
	//	//		case 12:	case 1: case 2:                      
	//	printf("현재의 계절은 겨울입니다.\n");
	//}

	//return 0;

	// 예제 4-7 ---------------------------------------------
	
	//int user, com;

	//printf("가위(1),바위(2), 보(3) 중 하나를 입력하세요.>");
	//scanf("%d", &user);

	//srand((unsigned)time(NULL)); // 현재시간으로 난수의 씨앗값을 초기화               
	//com = rand() % 3 + 1;        // 1,2,3중 하나가 com에 저장됨                  

	//printf("당신은 %d입니다.\n", user);
	//printf("컴은  %d입니다.\n", com);

	//switch (user - com) {
	//case 2: case -1:
	//	printf("당신이 졌습니다.\n");
	//	break;
	//case 1: case -2:
	//	printf("당신이 이겼습니다.\n");
	//	break;
	//case 0:
	//	printf("비겼습니다.\n");
	//	//			break;		// 마지막 문장이므로 break문을 사용할 필요가 없다. 
	//}

	//return 0;
	
	// 퀴즈 4-4 ---------------------------------------------

	//#include <stdio.h>
	//#include <time.h> // time()을 사용하기 위해 추가
	//#include <stdlib.h> // srand(), rand()를 사용하기 위해 추가
	//int main(void) {
	//	int user, com;
	//	printf("가위 바위 보 중 하나를 입력하세요 (1), (2), (3) .>"); 
	//		scanf("%d", &user);
	//	srand((unsigned)time(NULL)); // 현재시간으로 난수의 씨앗값을 초기화
	//	com = rand() % 3 + 1; // 1,2,3 com 중 하나가 에 저장됨
	//	printf("당신은 입니다 가위 바위 보 %s .\n", user == 1 ? " " : (user == 2 ? " " : " "));
	//		printf("컴은 입니다 가위 바위 보 %s .\n", com == 1 ? " " : (com == 2 ? " " : " ")); 
	//		switch (user - com) {
	//		case 2: case -1:
	//			printf("당신이 졌습니다 .\n"); 
	//				break;
	//		case 1: case -2:
	//			printf("당신이 이겼습니다 .\n"); 
	//				break;
	//		case 0:
	//			printf("비겼습니다 .\n"); 
	//				// break; // break . 마지막 문장이므로 문을 사용할 필요가 없다
	//		}
	//	return 0;
	//}

	// 예제 4-8 ---------------------------------------------
	
	//char gender;
	//char regNo[15]; // 문자열을 저장할 공간은 문자열의 길이 보다 1이 커야 한다.            

	//printf("당신의 주민번호를 입력하세요.(011231-1111222)>");
	//scanf("%s", regNo); // 주민등록번호를 입력받는다.                                

	//gender = regNo[7]; // 입력받은 주민등록번호의 8번째 문자를 gender에 저장             

	//switch (gender) {
	//case '1':
	//case '3':
	//	printf("당신은 남자입니다.\n");
	//	break;
	//case '2':
	//case '4':
	//	printf("당신은 여자입니다.\n");
	//	break;
	//default:
	//	printf("유효하지 않은 주민등록번호입니다.\n");;
	//}

	//return 0;

	// 퀴즈 4-5 ---------------------------------------------

	//int main(void) {
	//	char gender;
	//	char regNo[15]; // 1 . 문자열을 저장할 공간은 문자열의 길이 보다 이 커야 한다
	//	printf(" .(011231-1111222)>"); 
	//		scanf("당신의 주민번호를 입력하세요%s", regNo); // . 주민등록번호를 입력받는다
	//	gender = regNo[7]; // 8 gender 입력받은 주민등록번호의 번째 문자를 에 저장
	//	if (gender == '1' || gender == '3') {
	//		printf("당신은 남자입니다 .\n"); 
	//	}
	//	else if (gender == '2' || gender == '4') {
	//		printf("당신은 여자입니다 .\n"); 
	//	}
	//	else {
	//		printf("유효하지 않은 주민등록번호입니다 .\n");
	//	}
	//	return 0;
	//}

	// 예제 4-9 ---------------------------------------------
	// 
	//int  score;
	//char grade;
	//
	//printf("당신의 점수를 입력하세요.(1~100)>");
	//scanf("%d", &score);
	//
	//switch (score) {
	//case 100: case 99: case 98: case 97: case 96:
	//case 95:  case 94: case 93: case 92: case 91:
	//case 90:
	//	grade = 'A';
	//	break;
	//case 89: case 88: case 87: case 86:
	//case 85: case 84: case 83: case 82: case 81:
	//case 80:
	//	grade = 'B';
	//	break;
	//case 79: case 78: case 77: case 76:
	//case 75: case 74: case 73: case 72: case 71:
	//case 70:
	//	grade = 'C';
	//	break;
	//default:
	//	grade = 'F';
	//} // end of switch                                           
	//
	//printf("당신의 학점은 %c입니다.\n", grade);
	//
	//return 0;

	// 예제 4-10 ---------------------------------------------

	//int  score;
	//char grade = ' ';
	//
	//printf("당신의 점수를 입력하세요.(1~100)>");
	//scanf("%d", &score);
	//
	//switch (score / 10) {
	//case 10:
	//case  9:
	//	grade = 'A';
	//	break;
	//case 8:
	//	grade = 'B';
	//	break;
	//case 7:
	//	grade = 'C';
	//	break;
	//case 6:
	//	grade = 'D';
	//	break;
	//default:
	//	grade = 'F';
	//}
	//
	//printf("당신의 학점은 %c입니다.\n", grade);
	//
	//
	//return 0;
	
	// 퀴즈 4-6 ---------------------------------------------
	//int main(void) {
	//	int score;
	//	char grade = ' ';
	//	printf("당신의 점수를 입력하세요 .(1~100)>"); 
	//		scanf("%d", &score);
	//	switch (score / 5) {
	//	case 20:
	//	case 19:
	//		grade = 'A';
	//		break;
	//	case 18:
	//		grade = 'B';
	//		break;
	//	case 17:
	//		grade = 'C';
	//		break;
	//	case 16:
	//		grade = 'D';
	//		break;
	//	case 15:
	//		grade = 'E';
	//		break;
	//	case 14:
	//		grade = 'F';
	//		break;
	//	case 13:
	//		grade = 'G';
	//		break;
	//	case 12:
	//		grade = 'H';
	//		break;
	//	default:
	//		grade = 'I';
	//	}
	//	printf("당신의 학점은 %c입니다  .\n", grade); 
	//		return 0;
	//}

	// 예제 4-11 ---------------------------------------------

	//char   op;
	//int    x, y;
	//double result;
	//
	//printf("계산할 식을 입력하시오.(입력예 3 + 4)>");
	//scanf("%d %c %d", &x, &op, &y);
	//
	//switch (op) {
	//case '+':
	//	result = x + y;
	//	break;
	//case '-':
	//	result = x - y;
	//	break;
	//case '*':
	//case 'x':
	//	result = x * y;
	//	break;
	//
	//case '/':
	//	if (y != 0)
	//		result = x / (double)y; // double로 형변환해야 바른 결과를 얻는다.       
	//	else
	//		result = 0;
	//	break;
	//default:
	//	op = '?';
	//}
	//
	//if (op != '?') {
	//	if ((int)result == result) {
	//		printf("%d %c %d = %d\n", x, op, y, (int)result);
	//	}
	//	else {
	//		printf("%d %c %d = %f\n", x, op, y, result);
	//	}
	//}
	//else {
	//	printf("입력하신 연산자는 지원하지 않습니다.\n");
	//}
	//
	//return 0;

	// 예제 4-12 ---------------------------------------------

	//char gender;
	//char regNo[15];
	//
	//printf("당신의 주민번호를 입력하세요.(011231-1111222)>");
	//scanf("%s", regNo); // 주민등록번호를 입력받는다.                                         
	//
	//gender = regNo[7];  // 입력받은 주민등록번호의 8번째 문자를 얻는다.                           
	//
	//switch (gender) {
	//case '1':
	//case '3':
	//	switch (gender) {
	//	case '1':
	//		printf("당신은 2000년 이전에 출생한 남자입니다.\n");
	//		break;
	//	case '3':
	//		printf("당신은 2000년 이후에 출생한 남자입니다.\n");
	//	}
	//	break;    // 이 break문을 빼먹지 않도록 주의                             
	//case '2':
	//case '4':
	//	switch (gender) {
	//	case '2':
	//		printf("당신은 2000년 이전에 출생한 여자입니다.\n");
	//		break;
	//	case '4':
	//		printf("당신은 2000년 이후에 출생한 여자입니다.\n");
	//		break;
	//	}
	//	break;
	//default:
	//	printf("유효하지 않은 주민등록번호입니다.\n");
	//}
	//
	//
	//return 0;

	// 예제 4-13 ---------------------------------------------

	//int i;


	//for (i = 1; i <= 5; i++) {
	//	printf("%d\n", i); // i의 값을 출력한다.                                      
	//}

	//for (i = 1; i <= 5; i++) {
	//	printf("%d", i);   // 개행문자'\n'를 빼면 가로로 출력된다.                         
	//}
	//printf("\n");

	//return 0;

	// 퀴즈 4-7 ---------------------------------------------
	
	//int main(void) {
	//	int i = 1;
	//	while (i < 10) {
	//		printf("%d", i);
	//		if (i++ % 3 == 0)
	//			printf("\n");
	//	}
	//	return 0;
	//}

	// 예제 4-14 ---------------------------------------------
	
	//int sum = 0;	// 합계를 저장하기 위한 변수.                                              
	//int i;

	//for (i = 1; i <= 10; i++) {
	//	sum += i;	//	sum = sum + i;                                      
	//	printf("1부터 %2d 까지의 합: %2d\n", i, sum);
	//}

	//return 0;

	// 퀴즈 4-8 ---------------------------------------------

	//	int sum = 1;
	//	int i;
	//	for (i = 1; i <= 10; i++) {
	//		sum *= i; // sum = sum * i;
	//		printf("1부터 %2d까지의 곱: %d\n", i, sum);
	//	}
	
	// 예제 4-15 ---------------------------------------------

	//int i, j;

	//for (i = 1, j = 10; i <= 10; i++, j--) {
	//	printf("%d \t %d\n", i, j);
	//}

	//return 0;

	// 예제 4-16 ---------------------------------------------

	//int i;
	//
	//printf("i \t 2*i \t 2*i-1 \t i*i \t 11-i \t i/3 \t i%%3\n");
	//printf("----------------------------------------------------\n");
	//
	//for (i = 1; i <= 10; i++) {
	//	printf("%d \t %d \t %d \t %d \t %d \t %d \t %d\n",
	//		i, 2 * i, 2 * i - 1, i * i, 11 - i, i / 3, i % 3);
	//}
	//
	//return 0;

	// 퀴즈 4-9 ---------------------------------------------

	//int i;
	//for (i = 1; i < 10; i++) {
	//	printf("%d\t%d\n", (i + 2) % 3 + 1, (i + 2) / 3);
	//}
	//return 0;

	// 예제 4-17 ---------------------------------------------
	
	//int i, j;
	//
	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= 10; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//
	//return 0;

	// 예제 4-18 ---------------------------------------------

	//int num;
	//int i, j;

	//printf("*을 출력할 라인의 수를 입력하세요.>");
	//scanf("%d", &num);

	//for (i = 0; i < num; i++) {
	//	for (j = 0; j <= i; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	//return 0;

	// 퀴즈 4-10 (a) -----------------------------------------

	//int i, j;
	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= i; j++) {
	//		printf("%d", j);
	//	}
	//	printf("\n");
	//}
	//return 0;

	// 퀴즈 4-10 (b) -----------------------------------------

	//int i, j;
	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= i; j++) {
	//		printf("%d", i);
	//	}
	//	printf("\n");
	//}
	//return 0;

	// 예제 4-19 ---------------------------------------------

	//int i, j;

	//for (i = 2; i <= 9; i++) {
	//	for (j = 1; j <= 9; j++) {
	//		printf("%d x %d = %d\n", i, j, i * j);
	//	}
	//}
	//return 0;

	// 예제 4-20 ---------------------------------------------

	//int i, j, k;

	//for (i = 1; i <= 3; i++)
	//for (j = 1; j <= 3; j++)
	//for (k = 1; k <= 3; k++)
	//printf("%d%d%d\n", i, j, k);
	//return 0;

	// 퀴즈 4-11 ---------------------------------------------

	//int i, j;
	//for (i = 1; i <= 9; i++) {
	//	for (j = 2; j <= 5; j++)
	//		printf("%d x %d = %2d\t", j, i, i * j);
	//	printf("\n");
	//}
	//return 0;


	// 예제 4-21 ---------------------------------------------

	//int i, j;

	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= 5; j++)
	//		printf("[%d,%d]", i, j);
	//	printf("\n");
	//}

	//return 0;

	// 예제 4-22 ---------------------------------------------

	//int i, j;

	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= 5; j++) {
	//		if (i == j)
	//			printf("[%d,%d]", i, j);
	//		else
	//			printf("%5c", ' ');

	//	}
	//	printf("\n");
	//}

	// 퀴즈 4-12 (a) -----------------------------------------
	
	//int i, j;
	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= 5; j++) {
	//		if (i + j == 6)
	//			printf("[%d,%d]", i, j);
	//		else
	//			printf("%5c", ' ');
	//	}
	//	printf("\n");
	//}
	//return 0;
	// 
	// 퀴즈 4-12 (b) -----------------------------------------

	//int i, j;
	//for (i = 1; i <= 5; i++) {
	//	for (j = 1; j <= 5; j++) {
	//		if (i >= j)
	//			printf("[%d,%d]", i, j);
	//		else
	//			printf("%5c", ' ');
	//	}
	//	printf("\n");
	//}
	//return 0;
