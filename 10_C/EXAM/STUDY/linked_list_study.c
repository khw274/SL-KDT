#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void append();		// 리스트의 맨 뒤에 추가
void insert();		// 리스트의 맨 앞에 추가
void insert_pos();	// 리스트의 특정 위치에 추가
void display();		// 리스트 출력

struct node 
{
	int value;
	struct node* next;
};
struct node* head = NULL;

int main()
{
	int choice;

	while (1)
	{
		printf("=========== MENU ===========\n");
		printf("1. Append\n");
		printf("2. Insert\n");
		printf("3. Insert at position\n");
		printf("4. Display\n");
		printf("0. Exit\n");
		printf("============================\n");
		printf("Enter your choice : ");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			append();
			break;

		case 2:
			insert();
			break;

		case 3:
			insert_pos();
			break;

		case 4:
			display();
			break;

		case 0:
			exit(0);
		}
	}
}

void append()	
{
	struct node *temp, *ptr;

	temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL) 
	{
		printf("Out of Memory\n");
		exit(0);
	}

	printf("\nEnter data : ");
	scanf("%d", &temp->value);
	temp->next = NULL;			// 새로운 값 추가하면 next를 NULL로 초기화

	if (head == NULL)			// head가 NULL이면, 추가할 노드 temp가 head가 됨
	{
		head = temp;
	}

	else
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}


