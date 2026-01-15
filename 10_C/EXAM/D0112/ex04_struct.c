/* *******************************************************************
* File name    : ex04_struct.c
* Description  : 구조체 포인터
* Author       : HyeonWoo
* History      : 2026.01.12 HyeonWoo
* ********************************************************************/
// -------------------------------------------------------------------
// 1. 전처리기 - 헤더파일 포함 
// -------------------------------------------------------------------
#include <stdio.h>
#include <string.h>

// -------------------------------------------------------------------
// 2. 매크로 상수 정의 
// -------------------------------------------------------------------

// -------------------------------------------------------------------
// 3. 구조체 정의 
// -------------------------------------------------------------------
struct Date {
	int year;
	int month;
	int day;
};

struct Member {
	char id[8];
	char password[8];
	char name[10];
	int age;
	struct Date inputDate;
};

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
	struct Member member1 = { "hyeo123", "abc123", "hyeonwoo", 26, {2026, 01, 12} };
	struct Member member2;

	struct Member* ps = &member2;

	char name[10];
	printf("회원2 이름 : ");
	fgets(name, sizeof(name), stdin);

	// 개행 문자 제거
	// strcspn: name에서 처음 "\n" 문자가 나온 인덱스를 반환 -> "\0"으로 교체
	name[strcspn(name, "\n")] = '\0';    // 
	strcpy(member2.name, name);

	printf("학생2 ID : ");
	scanf("%s", member2.id);  
	printf("학생2 PASSWORD : ");
	scanf("%s", member2.password);  
	printf("학생2 나이 : ");
	scanf("%d", &member2.age);
	printf("학생2 날짜 (년 월 일) : ");
	scanf("%d %d %d", &member2.inputDate.year, &member2.inputDate.month, &member2.inputDate.day); 

	printf("학생1의 ID : %s, PASSWORD : %s, 이름 : %s, 나이 : %d, 날짜 : %d - %d - %d\n",
		member1.id, member1.password,
		member1.name, member1.age,
		member1.inputDate.year, member1.inputDate.month, member1.inputDate.day);  

	printf("학생2의 ID : %s, PASSWORD : %s, 이름 : %s, 나이 : %d, 날짜 : %d - %d - %d\n",
		member2.id, member2.password,
		member2.name, member2.age,
		member2.inputDate.year, member2.inputDate.month, member2.inputDate.day);  

	printf("포인터 학생2의 ID : %s, PASSWORD : %s, 이름 : %s, 나이 : %d, 날짜 : %d - %d - %d\n",
		ps->id, ps->password,
		ps->name, ps->age,
		ps->inputDate.year, ps->inputDate.month, ps->inputDate.day);

	return 0;
}
// -------------------------------------------------------------------
// 7. 함수 구현 
// -------------------------------------------------------------------
