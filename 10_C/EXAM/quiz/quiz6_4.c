/* *******************************************************************
* Quiz 6-4) 함수 printGugudan이 다음과 같이 정의되어 있을 때, 매개변수 dan의 값이 2와 9사이가 아닌 경우, 
			아무런 작업도 하지 않고 함수를 종료하도록 변경하시오.
* ********************************************************************/
// 전처리기 - 헤더파일 포함
#include <stdio.h>

// 함수 선언
int print_gugudan(int dan);

// 메인 함수
int main(void)
{
	print_gugudan(1);
}


// 함수 구현
int print_gugudan(int dan)
{
	if (dan < 2 || dan > 9)
	{
		printf("(dan의 범위 : 2 <= dan <= 9) 유효하지 않은 값입니다");
		return 0;

	}
	else {
		for (int i = 1; i <= 9; i++)
		{
			printf("%d * %d = %2d\n", dan, i, dan * i);
		}
	}
}