#include <stdio.h>
#include <string.h>

void fgets_exam() {

    char buffer[100]; // 한 줄을 넉넉하게 담을 임시 저장소
    int age;
    char name[20];

    // 1. fgets로 한 줄 전체를 안전하게 읽어옴 (Enter 키까지 포함됨)
    printf("나이와 이름을 입력하세요 (예: 25 GilDong): ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        // 2. 읽어온 buffer 문자열에서 원하는 형식으로 데이터 추출
        // sscanf는 scanf와 사용법이 같지만, 키보드 대신 '문자열'에서 읽어옴
        if (sscanf(buffer, "%d %s", &age, name) == 2)
        {
            printf("입력 성공! 나이: %d, 이름: %s\n", age, name);
        }
        else
        {
            printf("형식이 잘못되었습니다.\n");
        }
    }
}

void strcspn_exam() {
    char buffer[5] = { 0 };

    printf("문자를 입력하세요 : ");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = 0;
    }

    printf("저장된 값: %s\n", buffer);

    // 배열 내부 상태 확인용 반복문
    printf("배열 내부: ");
    for (int i = 0; i < sizeof(buffer); i++)
    {
        // 널 문자(\0)나 줄바꿈이 어떻게 처리되었는지 확인
        if (buffer[i] == 0) printf("[NULL]");
        else if (buffer[i] == '\n') printf("[LF]");
        else printf("[%c]", buffer[i]);
    }
}

int main(void)
{
    //fgets_exam();
    strcspn_exam();
    return 0;
}
