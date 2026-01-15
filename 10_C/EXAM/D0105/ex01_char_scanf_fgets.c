/* ********************************************************
* File name   : ex01_char_scanf_fgets.c
* Description : 문자/문자열 입력에 대한 처리
*				-> fget활용
* Author      : HyeonWoo
* History     : 2025.01.05 HyeonWoo
* **********************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);

    char msg[5] = { 0 };
    char temp[1024];

    printf("=== 5개의 문자를 입력하세요 (한 글자씩) ===\n");

    for (int i = 0; i < 5; i++)
    {
        // [Retry Loop] 올바른 입력을 받을 때까지 무한 반복
        while (1)
        {
            printf("%d번째 문자 입력 : ", i + 1);

            if (fgets(temp, sizeof(temp), stdin) == NULL) {
                // EOF(Ctrl+Z/D) 처리 등 비정상 종료 시 탈출
                return 0;
            }

            // 엔터 제거
            temp[strcspn(temp, "\n")] = 0;

            // 유효성 검사 (Validation)
            if (strlen(temp) == 0) {
                printf("[오류] 빈 칸입니다. 다시 입력해주세요.\n");
                continue; // while문의 처음으로 돌아감
            }

            if (strlen(temp) > 1) {
                printf("[오류] 한 글자만 입력해주세요! (입력값: %s)\n", temp);
                continue; // while문의 처음으로 돌아감
            }

            // 여기까지 오면 검증 통과! (Success)
            msg[i] = temp[0];
            break; // while문을 탈출해서 다음 for문(i++)으로 이동
        }
    }

    printf("\n--- 저장된 값 ---\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d]: %c\n", i, msg[i]);
    }

    return 0;
}
