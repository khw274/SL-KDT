#include<stdio.h>
#include<stdlib.h>

// 노드 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ===== 노드 생성 및 관리 =====

// 새로운 노드를 생성하는 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

    if (newNode == NULL) {
        printf("메모리 할당 실패!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// ===== 삽입 연산 =====

// 이진 탐색 트리에 데이터를 삽입하는 함수
TreeNode* insert(TreeNode* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    // 중복된 데이터는 삽입하지 않음

    return node;
}

// ===== 탐색 연산 =====

// 트리에서 데이터를 검색하는 함수
TreeNode* search(TreeNode* node, int target) {
    if (node == NULL) {
        return NULL;
    }

    if (target == node->data) {
        return node;
    }

    if (target < node->data) {
        return search(node->left, target);
    }
    else {
        return search(node->right, target);
    }
}

// ===== 순회 연산 =====

// 중위 순회 (오름차순 출력)
void inorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// 전위 순회
void preorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// 후위 순회
void postorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// ===== 트리 정보 조회 =====

// 트리의 높이를 반환하는 함수
int getHeight(TreeNode* node) {
    if (node == NULL) {
        return -1;  // 빈 트리의 높이는 -1
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    // 양쪽 서브트리 중 더 큰 높이에 1을 더함
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// 트리의 노드 개수를 반환하는 함수
int getSize(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + getSize(node->left) + getSize(node->right);
}

// 트리의 노드 개수를 출력하는 함수
void printTreeInfo(TreeNode* root) {
    printf("\n=== 트리 정보 ===\n");
    printf("노드 개수:%d\n", getSize(root));
    printf("트리의 높이:%d\n", getHeight(root));
}

// ===== 메모리 해제 =====

// 트리의 모든 노드를 해제하는 함수
void freeTree(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// ===== 주 함수 =====

int main() {
    TreeNode* root = NULL;

    printf("=== 이진 탐색 트리 생성 ===\n");
    printf("50, 30, 70, 20, 40, 60, 80을 순서대로 삽입합니다.\n\n");

    // 트리에 데이터 삽입
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // 트리 정보 출력
    printTreeInfo(root);

    // 순회 방식으로 트리 출력
    printf("\n=== 순회 결과 ===\n");
    printf("중위 순회 (Inorder):   ");
    inorder(root);
    printf("\n");

    printf("전위 순회 (Preorder):  ");
    preorder(root);
    printf("\n");

    printf("후위 순회 (Postorder): ");
    postorder(root);
    printf("\n");

    // 탐색 연산 테스트
    printf("\n=== 탐색 테스트 ===\n");
    int searchTargets[] = { 40, 100, 20, 25 };
    int targetCount = sizeof(searchTargets) / sizeof(searchTargets[0]);

    for (int i = 0; i < targetCount; i++) {
        TreeNode* result = search(root, searchTargets[i]);
        if (result != NULL) {
            printf("찾음:%d\n", searchTargets[i]);
        }
        else {
            printf("찾지 못함:%d\n", searchTargets[i]);
        }
    }

    // 메모리 해제
    freeTree(root);
    printf("\n=== 메모리 해제 완료 ===\n");

    return 0;
}