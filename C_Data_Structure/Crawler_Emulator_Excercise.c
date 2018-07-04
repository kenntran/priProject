/********************************************************************************************************************************
	Crawler_Emulator

	To simulate the simple opertation of google in finding different websites in websites / finding different files in files 
	
	Unfortunely, the question is in Vietnamese, you could use google translate to translate to English.

 	Question: http://www.cse.net.vn/dsa/33171020194.html
********************************************************************************************************************************/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
typedef struct Node
{
	char name[MAX];
	struct Node *next;
}Node;

typedef struct Queue
{
	Node *head;
	Node *tail;
}Queue;

typedef struct Set
{
	Node *head;
	Node *tail;
}Set;


void initQueue(Queue *q)
{
	q->head = q->tail = NULL;
}



bool QueueisEmpty(const Queue *q)
{
	return q->head == NULL;
}



Node *getNodeQueue(char name[])
{
	Node *q = (Node*)malloc(sizeof(Node));
	q->next = NULL;
	strcpy_s(q->name,MAX, name);
	return q;
}

void Enqueue(Queue *q, char name[])
{
	Node *temp = getNodeQueue(name);
	if (QueueisEmpty(q))
	{
		q->head = q->tail = temp;
	}
	else
	{
		q->tail->next = temp;
		q->tail = temp;
	}
}

Node *Dequeue(Queue *q)
{
	Node *saved = q->head;
	if (!QueueisEmpty(q))
	{
		q->head = saved->next;
		if (q->head == NULL)
		{
			q->tail = NULL;
		}
	}
	return saved;
}

void initSet(Set *s)
{
	s->head = s->tail = NULL;
}

Node *getNodeSet(char name[])
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->next = NULL;
	strcpy_s(temp->name,MAX, name);
	return temp;
}

bool SetisEmpty(const Set *s)
{
	return s->head == NULL;
}

bool isExist(const Set *s, char name[])
{
	Node *temp = s->head;
	while (temp != NULL && strcmp(temp->name, name) != 0)
	{
		temp = temp->next;
	}
	return temp != NULL;
}

bool setAddHead(Set *s, char name[])
{
	if (isExist(s,name))
	{
		return false;
	}
	Node *temp = getNodeSet(name);
	if (SetisEmpty(s))
	{
		s->head = s->tail = temp;
	}
	else{
		temp->next = s->head;
		s->head = temp;
	}
	return true;
}

Node *setRemoveTail(Set *s)
{
	Node *saved = s->head;
	if (!SetisEmpty(s))
	{
		s->head = saved->next;
		if (s->head == NULL)
		{
			s->tail = NULL;
		}
	}
	return saved;
}


void outputSet(const Set *s)
{
	Node *temp = s->head;
	while (temp != NULL)
	{
		printf("%s ", temp->name);
		temp = temp->next;
	}
	printf("\n");
}

void clearEndLine(char str[])
{
	int len = strlen(str);
	while (str[--len] == '\n')
	{
		str[len] = '\0';
	}
}

Node *peek(const Queue *q)
{
	return q->head;
}

void main()
{
	char inputName[MAX];
	Queue que;
	Set set;

	initQueue(&que);
	initSet(&set);

	printf("Enter file name: ");
	gets_s(inputName,MAX);
	printf("\n");

	Enqueue(&que, inputName);
	setAddHead(&set, inputName);

	while (!QueueisEmpty(&que))
	{
		char Buff[MAX];
		Node *tempQue = Dequeue(&que);
		FILE *f;
		fopen_s(&f, tempQue->name, "rt");
		if (f != NULL)
		{
			while (!feof(f))
			{
				fgets(Buff, MAX, f);
				clearEndLine(Buff);
				if (!isExist(&set, Buff))
				{
					setAddHead(&set, Buff);
					Enqueue(&que, Buff);
				}
			}
			fclose(f);
		}		
	}
	outputSet(&set);
}
