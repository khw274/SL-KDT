#include <stdio.h>
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);

    // 5명의 이름, 각 이름은 최대 10글자(널문자 포함)
    char names[5][10];
    char temp[1024]; // 넉넉한 방패 (모든 입력을 일단 여기서 받음)

    for (int i = 0; i < 5; i++)
    {
        while (1) // Retry Loop
        {
            printf("%d번째 이름 입력 (최대 9글자): ", i + 1);

            if (fgets(temp, sizeof(temp), stdin) == NULL) return 0;

            temp[strcspn(temp, "\n")] = 0; // 엔터 제거

            // 1. 빈 문자열 체크
            if (strlen(temp) == 0) {
                printf("[오류] 이름을 입력해주세요.\n");
                continue;
            }

            // 2. 길이 체크 (배열 크기보다 큰 입력 방지)
            // names[i]의 크기는 sizeof(names[i]) = 10
            // 널 문자 공간 1개를 빼야 하므로 9글자까지만 허용
            if (strlen(temp) >= sizeof(names[i])) {
                printf("[오류] 이름이 너무 깁니다. (최대 9자)\n");
                continue;
            }

            // 3. 검증 통과 -> 2차원 배열로 복사
            // strcpy는 널 문자까지 포함해서 안전하게 복사해줌
            strcpy(names[i], temp);
            break;
        }
    }

    printf("\n--- 입력된 이름들 ---\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d]: %s\n", i, names[i]);
    }

    return 0;
}
