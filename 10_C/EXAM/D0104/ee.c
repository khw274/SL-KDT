//** C EXAM - BASIC 답안 * *
//
//**단답형 * *
//
//1. `char`, `short`, `int`, `long`
//2. 아스키 코드(ASCII) 정수값
//3. `signed`는 음수~양수 표현, `unsigned`는 0~양수(약 2배 범위) 표현
//4. 0이면 거짓, 0이 아니면 참
//5. `& & `, `| | `
//6. `i+ + `는 사용 후 증가(후위), `+ + i`는 증가 후 사용(전위)으로 연산 결과가 다름
//7. 폴스루(Fall - through)
//8. 40 바이트(4 bytes × 10)
//9. 부호 비트(Sign bit) - 0: 양수, 1 : 음수
//10. 비트를 반전시키고(1의 보수) 1을 더한 값(음수 표현 방식)
//11. 비트 AND 연산(`&`)
//    12. 세그멘테이션 폴트(Segmentation Fault), 메모리 침범, 쓰레기값 참조
//    13. `for`는 반복 횟수가 명확할 때, `while`은 조건이 중심일 때 사용
//    14. 쓰레기값(Garbage Value)이 들어있어 예측 불가능한 동작 유발
//    15. `&`: 주소 연산자, `*`: 간접 참조(포인터) 연산자
//
//    * **
//
//    **코드형 * *
//
//    **1. 삼항 연산자 최대 / 최소 * *
//    ```c
//    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
//int min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
//printf("큰 값: %d, 작은 값: %d\n", max, min);
//```
//
//* *2. 문자열 16진수 출력 * *
//```c
//char str[100];
//scanf("%s", str);
//for (int i = 0; str[i] != '\0'; i++) {
//    printf("%X ", str[i]);
//}
//```
//
//** 3. 약수 출력 * *
//```c
//int n;
//scanf("%d", &n);
//for (int i = 1; i <= n; i++) {
//    if (n % i == 0) printf("%d ", i);
//}
//```
//
//** 4. 팩토리얼 계산 * *
//```c
//int n, fact = 1;
//scanf("%d", &n);
//for (int i = 1; i <= n; i++) fact *= i;
//printf("%d\n", fact);
//```
//
//** 5. 양수 입력 합계 / 개수 * *
//```c
//int num, sum = 0, count = 0;
//while (1) {
//    scanf("%d", &num);
//    if (num <= 0) break;
//    sum += num;
//    count++;
//}
//printf("합계: %d, 개수: %d\n", sum, count);
//```
//
//** 6. 연속 값 카운트 * *
//```c
//int count = 1;
//for (int i = 0; i < n - 1; i++) {
//    if (arr[i] == arr[i + 1]) count++;
//    else {
//        printf("%d ", count);
//        count = 1;
//    }
//}
//printf("%d\n", count); // 마지막 그룹 출력
//```
//
//** 7. 특정 값 인덱스 찾기 * *
//```c
//int idx = -1;
//for (int i = 0; i < 10; i++) {
//    if (arr[i] == x) {
//        idx = i;
//        break;
//    }
//}
//printf("%d\n", idx);
//```
//
//** 8. k번째 비트 토글 * *
//```c
//// k는 0부터 시작한다고 가정
//int result = x ^ (1 << k);
//printf("%d\n", result);
//```
//
//** 9. 봉우리 개수 * *
//```c
//int peaks = 0;
//for (int i = 1; i < n - 1; i++) {
//    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) peaks++;
//}
//printf("%d\n", peaks);
//```
//
//** 10. 1~100 소수 출력 * *
//```c
//for (int i = 2; i <= 100; i++) {
//    int is_prime = 1;
//    for (int j = 2; j * j <= i; j++) {
//        if (i % j == 0) {
//            is_prime = 0;
//            break;
//        }
//    }
//    if (is_prime) printf("%d ", i);
//}
//```
//
//[1](https://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/24664416/76498598-4ef7-4ccd-a0ef-3158cf4a657f/meosinreoning.pdf)
//[2] (https ://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/24664416/11e17631-eb9a-4c66-9677-22ec7bb2fa2e/TEST-_ML_CV.py)
//    [3] (https ://ppl-ai-file-upload.s3.amazonaws.com/web/direct-files/attachments/24664416/18d87177-6772-4119-9e8d-79defac91186/exam0105_basic_C.c)