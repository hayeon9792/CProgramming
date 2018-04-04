#include <stdio.h>
#include <malloc.h>
//n번째 위치에 삽입(첫/마지막 삽입 or 중간 삽입), n번째 위치의 노드 삭제 (첫/마지막 삭제 or 중간 삭제)
typedef int Eltype;
typedef struct tagNode {
	Eltype Data;
	struct tagNode* NextNode;
}Node;

int N;

void InsertNode(Node** Head, Node** Tail, Eltype NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	if ((*Head) == NULL)
	{
		(*Head) = NewNode;
		//(*Head)->Data = NewNode->Data;
		//(*Head)->NextNode = NULL;
		(*Tail) = NewNode;
	}
	else
	{
		(*Tail)->NextNode = NewNode;
		(*Tail) = NewNode;
	}
	N++;
}

void DeleteNode(Node** Head, Node **Tail, int n)
{	
	if (n == 1)
	{
		(*Head) = (*Head)->NextNode;
	}
	else if (n == N)
	{
		Node* delNode = (*Head);
		while (delNode->NextNode != (*Tail))
		{
			delNode->NextNode = NULL;
			(*Tail) = delNode;
		}
	}
	else
	{
		Node* delNode = (*Head);
		while (n > 1)
		{
			delNode = delNode->NextNode;
			n--;
		}
		*(&delNode) = *(&(delNode->NextNode));
	}
	N--;
}

void PntNode(Node* Head)
{
	/*if (start->NextNode == NULL)
	{
		printf("%d\n", start->Data);
		return;
	}*/
	while (Head->NextNode != NULL)
	{
		printf("%d->", Head->Data);
		Head = Head->NextNode;
	}
	if (Head->NextNode == NULL) printf("%d\n", Head->Data);
}

int main(void)
{
	Node* list = NULL; //Head
	Node* tail = NULL; //Tail

	int v;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &v);
		InsertNode(&list, &tail, v);
	}

	PntNode(list);
	DeleteNode(&list, &tail, 1);
	PntNode(list);
	DeleteNode(&list, &tail, 3);
	PntNode(list);
	//DeleteNode(&list, &tail, 4);
	//PntNode(list);

	if (tail != list) free(tail);
	free(list); //값이 1개만 존재하면, list = NewNode, tail = NewNode, 따라서 free(list) = free(tail) !!
	return 0;
}