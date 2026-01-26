#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int a;
	Node* next;
}Node;


Node* Head = NULL;

Node* input() {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	scanf("%d", &NewNode->a);
	return NewNode;
}

void append()
{
	Node* ptr;
	if (Head == NULL) {
		ptr = input();
		Head = ptr;
	}
	ptr = Head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = input();
}

void print()
{
	Node* ptr;
	ptr = Head;
	while (ptr != NULL) {
		printf("%d", ptr->a);
		ptr = ptr->next;
	}
}

int main() {
	while (1) {
		int choice;
		printf("메뉴선택");
		printf("1. ")
	}


}