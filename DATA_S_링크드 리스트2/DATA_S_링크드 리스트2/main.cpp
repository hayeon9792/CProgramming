#include <stdio.h>
#include <malloc.h>

typedef struct listNode{
	int data;
	struct listNode* prev;
	struct listNode* next;
	listNode(int newdata) : data(newdata), prev(NULL), next(NULL) {};
	listNode() : data(0), prev(NULL), next(NULL) {};
}ListNode;

typedef struct List {
	int size;
	N
};

void add(ListNode* list, int newdata)
{
	//
}


int main()
{
	ListNode* list = (ListNode*)malloc(sizeof(ListNode));
	list->data = -1;
	list->next = NULL;
	list->prev = NULL;

	return 0;
}