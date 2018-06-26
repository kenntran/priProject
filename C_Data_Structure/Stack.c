#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAX 100

typedef struct Stack{
	int a[MAX];
	int top;
}Stack;

void init(Stack *s)
{
	s->top = -1;
}

bool isEmpty(const Stack *s)
{
	return s->top == -1;
}

bool isFull(const Stack *s)
{
	return s->top == MAX - 1;
}

bool Push(Stack *s, int x)
{
	if (isFull(s))
	{
		return false;
	}
	s->a[++s->top] = x;
	return true;
}

int Peek(const Stack *s)
{
	if (isEmpty(s))
	{
		//exception - cannot return any value
		exit(0);
	}
	return s->a[s->top];
}

int Pop(Stack *s)
{
	if (isEmpty(s))
	{
		exit(0);
	}
	return s->a[s->top--];
}

void main()
{
	Stack s;
	init(&s);

	for (int i = 0; i < 10; i++)
	{
		Push(&s, i);
	}
	while (!isEmpty(&s)){
		printf("Peek: %d\n", Peek(&s));
		printf("%d\n", Pop(&s));
	}
}
