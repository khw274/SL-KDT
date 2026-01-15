/* *******************************************************************
* File name    : linked_list.c
* Description  : 링크드리스트 구현
* Author       : HyeonWoo
* History      : 2026.01.15
* ********************************************************************/
// -------------------------------------------------------------------
// 전처리기 
// -------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


// -------------------------------------------------------------------
// 구조체 
// -------------------------------------------------------------------
// 링크드리스트의 노드 구조 정의
typedef struct Node {
    int data;              // 노드가 저장할 정수형 데이터
    struct Node* next;     // 다음 노드를 가리키는 포인터
} Node;

// 새로운 노드를 생성하는 함수
Node* createNode(int data) {
    // malloc을 사용하여 Node 크기만큼 메모리를 동적 할당
    Node* newNode = (Node*)malloc(sizeof(Node));

    // 메모리 할당 실패 시 NULL을 반환하도록 안전장치 추가
    if (newNode == NULL) {
        printf("메모리 할당 실패!\n");
        return NULL;
    }

    // 새 노드의 데이터 필드에 전달받은 값 저장
    newNode->data = data;

    // 새 노드의 next 포인터를 NULL로 초기화
    newNode->next = NULL;

    // 생성된 노드의 포인터 반환
    return newNode;
}

// 링크드리스트의 맨 앞에 새 노드를 추가하는 함수
Node* insertAtBeginning(Node* head, int data) {
    // 새 노드 생성
    Node* newNode = createNode(data);

    // 생성된 노드가 NULL이면 함수 종료
    if (newNode == NULL) {
        return head;
    }

    // 새 노드의 next를 현재 head로 지정
    newNode->next = head;

    // 새 노드를 새로운 head로 설정
    head = newNode;

    // 업데이트된 head 포인터 반환
    return head;
}

// 링크드리스트의 끝에 새 노드를 추가하는 함수
Node* insertAtEnd(Node* head, int data) {
    // 새 노드 생성
    Node* newNode = createNode(data);

    // 생성된 노드가 NULL이면 함수 종료
    if (newNode == NULL) {
        return head;
    }

    // 만약 리스트가 비어있으면 새 노드가 head가 됨
    if (head == NULL) {
        return newNode;
    }

    // 현재 노드를 가리킬 임시 포인터 생성
    Node* current = head;

    // while 루프: current->next가 NULL이 될 때까지 반복
    while (current->next != NULL) {
        current = current->next;  // 다음 노드로 이동
    }

    // 마지막 노드의 next 포인터를 새 노드로 설정
    current->next = newNode;

    // head 포인터 반환
    return head;
}

// 링크드리스트의 모든 노드를 출력하는 함수
void display(Node* head) {
    // 현재 노드를 가리킬 포인터, head부터 시작
    Node* current = head;

    // 만약 리스트가 비어있으면
    if (current == NULL) {
        printf("링크드리스트가 비어있습니다.\n");
        return;
    }

    printf("링크드리스트: ");

    // while 루프: current가 NULL이 될 때까지 반복
    while (current != NULL) {
        // 현재 노드의 데이터 출력
        printf("%d -> ", current->data);

        // 다음 노드로 이동
        current = current->next;
    }

    // 링크드리스트의 끝을 표시
    printf("NULL\n");
}

// 특정 값을 찾아서 해당 노드를 삭제하는 함수
Node* deleteNode(Node* head, int data) {
    // 만약 리스트가 비어있으면 NULL 반환
    if (head == NULL) {
        return NULL;
    }

    // 만약 삭제할 노드가 head라면
    if (head->data == data) {
        // head의 다음 노드 포인터 임시 저장
        Node* temp = head->next;

        // head 노드의 메모리 해제
        free(head);

        // 새로운 head 반환
        return temp;
    }

    // 현재 노드를 가리킬 포인터, head에서 시작
    Node* current = head;

    // while 루프: current->next가 NULL이 될 때까지 반복
    while (current->next != NULL) {
        // 만약 다음 노드의 데이터가 찾는 값과 같으면
        if (current->next->data == data) {
            // 삭제할 노드를 임시 포인터에 저장
            Node* temp = current->next;

            // 현재 노드의 next를 삭제할 노드의 next로 변경
            current->next = temp->next;

            // 삭제할 노드의 메모리 해제
            free(temp);

            // 함수 종료
            return head;
        }

        // 다음 노드로 이동
        current = current->next;
    }

    // 찾는 값이 없으면 그냥 head 반환
    printf("데이터를 찾을 수 없습니다.\n");
    return head;
}

// 링크드리스트의 모든 메모리를 해제하는 함수
void freeList(Node* head) {
    // 현재 노드를 가리킬 포인터
    Node* current = head;

    // while 루프: 리스트의 모든 노드를 순회하며 메모리 해제
    while (current != NULL) {
        // 다음 노드를 임시 저장
        Node* temp = current->next;

        // 현재 노드의 메모리 해제
        free(current);

        // 다음 노드로 이동
        current = temp;
    }
}

// 메뉴를 출력하는 함수
void printMenu() {
    printf("\n========== 메뉴 ==========\n");
    printf("1. 맨 앞에 삽입\n");
    printf("2. 끝에 삽입\n");
    printf("3. 노드 삭제\n");
    printf("4. 링크드리스트 출력\n");
    printf("5. 프로그램 종료\n");
    printf("========================\n");
    printf("선택: ");
}

// main 함수 - scanf를 사용한 사용자 입력 버전
int main() {
    // head는 링크드리스트의 첫 번째 노드를 가리키는 포인터
    // 처음에는 NULL로 초기화 (빈 리스트)
    Node* head = NULL;

    // 사용자의 선택을 저장할 변수
    int choice;

    // 사용자가 입력한 데이터를 저장할 변수
    int data;

    printf("========== 링크드리스트 관리 프로그램 ==========\n\n");

    // do-while 루프: 사용자가 5번(종료)을 선택할 때까지 반복
    do {
        // 메뉴 출력
        printMenu();

        // scanf를 사용하여 사용자로부터 선택 입력받기
        // %d는 정수형을 입력받겠다는 의미
        scanf("%d", &choice);

        // 개행 문자 제거 (scanf 후 버퍼에 남은 개행 제거)
        getchar();

        // switch 문을 사용하여 사용자의 선택에 따라 다른 작업 수행
        switch (choice) {
            // 사용자가 1을 선택한 경우
        case 1:
            // 사용자에게 맨 앞에 삽입할 값 입력받기
            printf("맨 앞에 삽입할 값을 입력하세요: ");

            // scanf를 사용하여 정수형 데이터 입력받기
            scanf("%d", &data);

            // 개행 문자 제거
            getchar();

            // insertAtBeginning 함수를 호출하여 노드 추가
            head = insertAtBeginning(head, data);

            // 삽입 완료 메시지 출력
            printf("%d를 맨 앞에 추가했습니다.\n", data);

            // switch 문 탈출
            break;

            // 사용자가 2를 선택한 경우
        case 2:
            // 사용자에게 끝에 삽입할 값 입력받기
            printf("끝에 삽입할 값을 입력하세요: ");

            // scanf를 사용하여 정수형 데이터 입력받기
            scanf("%d", &data);

            // 개행 문자 제거
            getchar();

            // insertAtEnd 함수를 호출하여 노드 추가
            head = insertAtEnd(head, data);

            // 삽입 완료 메시지 출력
            printf("%d를 끝에 추가했습니다.\n", data);

            // switch 문 탈출
            break;

            // 사용자가 3을 선택한 경우
        case 3:
            // 사용자에게 삭제할 값 입력받기
            printf("삭제할 값을 입력하세요: ");

            // scanf를 사용하여 정수형 데이터 입력받기
            scanf("%d", &data);

            // 개행 문자 제거
            getchar();

            // deleteNode 함수를 호출하여 노드 삭제
            head = deleteNode(head, data);

            // 삭제 완료 메시지 출력
            printf("%d를 삭제했습니다.\n", data);

            // switch 문 탈출
            break;

            // 사용자가 4를 선택한 경우
        case 4:
            // display 함수를 호출하여 전체 링크드리스트 출력
            display(head);

            // switch 문 탈출
            break;

            // 사용자가 5를 선택한 경우
        case 5:
            // 종료 메시지 출력
            printf("\n프로그램을 종료합니다.\n");

            // switch 문 탈출
            break;

            // 사용자가 1~5 외의 값을 입력한 경우
        default:
            // 잘못된 선택 메시지 출력
            printf("잘못된 선택입니다. 다시 입력하세요.\n");

            // switch 문 탈출
            break;
        }

        // do-while 루프의 조건: choice가 5가 아니면 계속 반복
    } while (choice != 5);

    // 링크드리스트의 모든 메모리를 해제
    // 프로그램 종료 전에 반드시 수행해야 메모리 누수가 발생하지 않음
    freeList(head);

    // head를 NULL로 설정
    head = NULL;

    // 프로그램 정상 종료
    return 0;
}
