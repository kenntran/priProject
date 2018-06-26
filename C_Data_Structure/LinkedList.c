#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
	int x;
	struct Node *next;
}Node;

typedef struct LinkedList{
	Node *head;
	Node *tail;
}LinkedList;

void init(LinkedList *l)
{
	l->head = l->tail = NULL;
}

bool isEmpty(const LinkedList *l)
{
	return l->head == NULL;
}

void addTail(LinkedList *l, Node *p)
{
	if (isEmpty(l))
	{
		l->head = l->tail = p;
	}
	else
	{
		l->tail->next = p;
		l->tail = p;
	}
}

void Tranverse(const LinkedList *l)
{
	Node *p = l->head;
	while (p != NULL)
	{
		printf("%d ", p->x);
		p = p->next;
	}
	printf("\n");
}

Node *GetNode(int x)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->x = x;
	return p;
}

void insertNode(LinkedList *l, int x){
	Node *p = GetNode(x);
	addTail(l, p);
}

void addHead(LinkedList *l, Node *p)
{
	if (isEmpty(l))
	{
		l->head = l->tail = p;
	}
	else{
		p->next = l->head;
		l->head = p;
	}
}

void main()
{
	LinkedList list;
	init(&list);

	/*Node p = { 8, NULL };
	addTail(&list, &p);

	Node q = { 10, NULL };
	addTail(&list, &q);

	Tranverse(&list);*/

	
	for (int i = 0; i < 10; i++)
	{
		/*Node *p = GetNode(i);
		addTail(&list, p);*/
		insertNode(&list, i);
	}

	
	//Infinite loop - passing same address
	/*for (int i = 0; i < 10; i++)
	{
		Node p = {i, NULL};
		addTail(&list, &p);
	}*/
	Tranverse(&list);


}