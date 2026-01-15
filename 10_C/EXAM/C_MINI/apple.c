/* *******************************************************************
* File name    : apple_game_sub.c
* Description  : 사과 게임 프로그램
* Author       : HyeonWoo
* History      : 2026.01.12 HyeonWoo
* ********************************************************************/
#include "apple.h"

// -------------------------------------------------------------------
// 전역 변수/상수 선언
// -------------------------------------------------------------------
struct apple board[ROWS][COLS];
struct state game_state;

// -------------------------------------------------------------------
// 함수 선언 
// -------------------------------------------------------------------
void init_board();
void print_board();
void deleted(int r1, int c1, int r2, int c2);

int sum_selected(int r1, int c1, int r2, int c2);
int check_removed(int r1, int c1, int r2, int c2);

void apple_game();

// -------------------------------------------------------------------
// 메인 함수 
// -------------------------------------------------------------------
int main(void)
{
	apple_game();

	return 0;
}

// -------------------------------------------------------------------
// 함수 구현 
// -------------------------------------------------------------------
// 함수 이름 : init_board
// 함수 기능 : 표를 랜덤값과 삭제한 사과 플래그를 초기화
//			   게임 점수와 총 삭제한 사과 수를 초기화
// 매개 변수 : X
// 반 환 값  : void
// -------------------------------------------------------------------
void init_board()
{
	srand((unsigned int)time(NULL));

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			board[r][c].origin = rand() % 9 + 1;
			board[r][c].removed = 0;
		}
	}

	game_state.score = 0;
	game_state.total_removed = 0;
}

// -------------------------------------------------------------------
// 함수 이름 : deleted
// 함수 기능 : 선택한 영역의 사과를 삭제하고 플래그 배열에 1로 초기화
// 매개 변수 : int r1, int c1, int r2, int c
// 반 환 값  : void 
// -------------------------------------------------------------------
// 선택한 영역의 사과를 삭제
void deleted(int r1, int c1, int r2, int c2)
{
	int count = 0;

	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			
			if (!board[r][c].removed) {
				board[r][c].removed = 1;
				count++;
			}
		}
	}
	
	game_state.score += (count * 2);
	game_state.total_removed += count;
}

// -------------------------------------------------------------------
// 함수 이름 : print_board
// 함수 기능 : 표를 출력하는 함수, 만약에 삭제 플래그가 1이면 " - "로 아니면 랜덤 숫자를 출력
// 매개 변수 : X
// 반 환 값  : void 
// -------------------------------------------------------------------
void print_board()
{
	system("cls");
	printf("==================== 점수: (%d/%d) | 제거한 사과: (%d/%d) =====================\n",
		game_state.score, GOAL, game_state.total_removed, HIT);

	printf("    ");
	for (int c = 0; c < COLS; c++) {
		printf("%5d ", c);				// 표에 열 출력
	}
	printf("\n");

	// 게임판 출력
	for (int r = 0; r < ROWS; r++) {
		printf("%4d ", r);				// 표에 행 출력

		for (int c = 0; c < COLS; c++) {
			if (board[r][c].removed)
			{
				printf("   -  ");
			}
			else {
				printf(" [%2d] ", board[r][c].origin);
			}
		}
		printf("\n");
	}
}

// -------------------------------------------------------------------
// 함수 이름 : sum_selected
// 함수 기능 : 만약에 삭제 플래그가 1이 아니라면 총합에 랜덤값 추가
// 매개 변수 : int r1, int c1, int r2, int c2
// 반 환 값  : 총합 
// -------------------------------------------------------------------
// 선택한 범위의 요소의 합 계산
int sum_selected(int r1, int c1, int r2, int c2)
{
	int sum = 0;

	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			// 이미 삭제된 요소가 아니라면 합 계산
			if (!board[r][c].removed) {			
				sum += board[r][c].origin;
			}
		}
	}

	return sum;
}

// -------------------------------------------------------------------
// 함수 이름 : check_removed
// 함수 기능 : 삭제 배열에 1이 들어가 있다면 1, 아니면 0을 반환
// 매개 변수 : int r1, int c1, int r2, int c2
// 반 환 값  : (삭제된 값이라면 : 1, 아니면 0) 
// -------------------------------------------------------------------
// 이미 삭제된 사과가 포함되어 있는지 확인
int check_removed(int r1, int c1, int r2, int c2)
{
	for (int r = r1; r <= r2; r++)
	{
		for (int c = c1; c <= c2; c++)
		{
			// 이미 삭제됐다면 1 반환
			if (board[r][c].removed) {
				return 1;
			}
		}
	}

	// 삭제가 안됐다면 0 반환
	return 0;
}

// -------------------------------------------------------------------
// 함수 이름 : apple_game
// 함수 기능 : 최종 실행 함수
//			   목표 점수까지 실행
//			   입력값 예외처리 4종
//			   게임 종료시 점수랑 총 삭제 수 출력
// 매개 변수 : X
// 반 환 값  : void
// -------------------------------------------------------------------
void apple_game()
{
	printf("=========================== 사과 게임 ===========================\n");
	printf("              사과들의 합이 10이 되도록 만드세요!\n");
	Sleep(1000);

	init_board();

	while (game_state.score < GOAL)
	{
		print_board();

		int r1, c1, r2, c2;

		printf("범위를 지정하세요(예: 2 2 4 4 -> 2행 2열부터 4행 4열) : ");
		scanf_s("%d %d %d %d", &r1, &c1, &r2, &c2);

		// 예외 처리 ========================================================
		// 1. 입력 행열이 0~9가 아닐 때
		if (r1 < 0 || r1 >= ROWS || r2 < 0 || r2 >= ROWS ||
			c1 < 0 || c1 >= COLS || c2 < 0 || c2 >= COLS) {
			printf("잘못된 입력입니다! 0~9 사이로 입력하세요\n");
			Sleep(1500);
			continue;
		}

		// 2. 시작 행열이 끝 행열보다 클 때
		if (r1 > r2 || c1 > c2)
		{
			printf("시작 위치가 끝 위치보다 클 수 없습니다.\n");
			Sleep(1500);
			continue;
		}

		// 3. 이미 삭제된 사과가 포함되어 있을 때
		if (check_removed(r1, c1, r2, c2)) {
			printf("이미 삭제된 사과가 포함되어 있습니다!\n");
			Sleep(1500);
			continue;
		}

		// 4. 범위 안 사과들의 합 계산 및 확인
		int sum = sum_selected(r1, c1, r2, c2);

		if (sum == 10)
		{
			printf("선택한 사과의 합이 10입니다!\n");
			deleted(r1, c1, r2, c2);
			Sleep(1500);
			continue;
		}
		else {
			printf("선택한 사과의 합이 %d입니다. 10이 아닙니다.\n", sum);
			printf("다시 입력해주세요.\n");
			Sleep(1500);
			continue;
		}
	}

	// 게임 종료
	print_board();
	printf("\n================= 게임 종료! =================\n");
	printf("최종 점수: %d점\n", game_state.score);
	printf("총 제거한 사과: %d개\n", game_state.total_removed);
}