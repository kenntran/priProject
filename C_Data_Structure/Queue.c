#include <stdio.h>
#include <stdbool.h>

#define MAX 100

//Queue with FOR loop

//////typedef struct Queue{
//////	int a[MAX];
//////	int size;
//////}Queue;
//////
//////void init(Queue *q)
//////{
//////	q->size = 0;
//////}
//////
//////bool isEmpty(const Queue *q)
//////{
//////	return q->size == 0;
//////}
//////
//////bool isFull(const Queue *q)
//////{
//////	return q->size == MAX;
//////}
//////
//////bool Enqueue(Queue *q, int x)
//////{
//////	if (isFull(q))
//////	{
//////		return false;
//////	}
//////	q->a[q->size++] = x;
//////	return true;
//////}
//////
//////int Peek(const Queue *q)
//////{
//////	if (isEmpty(q))
//////	{
//////		exit(0);
//////	}
//////	return q->a[0];
//////}
//////
//////int Dequeue(Queue *q)
//////{	
//////	if (isEmpty(q))
//////	{
//////		exit(0);
//////	}
//////	int saved = q->a[0];
//////	q->size--;
//////	for (int i = 0; i < q->size; i++)
//////	{
//////		q->a[i] = q->a[i + 1];
//////	}
//////	return saved;
//////}



//Cai tien Queue 
typedef struct Queue{
	int a[MAX];
	int front;
	int size;
}Queue;

void init(Queue *q)
{
	q->front = 0;
	q->size = 0;
}

bool isEmpty(const Queue *q)
{
	return q->size == 0;
}

bool isFull(const Queue *q)
{
	return q->size == MAX;
}

bool Enqueue(Queue *q, int x)
{
	if (isFull(q))
	{
		return false;
	}
	q->a[(q->front + q->size) % MAX] = x;
	q->size++;
	return true;
}

int Peek(const Queue *q)
{
	if (isEmpty(q))
	{
		exit(0);
	}
	return q->a[q->front];
}

int Dequeue(Queue *q)
{
	if (isEmpty(q))
	{
		exit(0);
	}
	q->size--;
	int saved = q->a[q->front];
	q->front = (q->front + 1) % MAX;
	return saved;
}

void main()
{
	Queue q;
	init(&q);

	for (int i = 0; i < 10; i++)
	{
		Enqueue(&q, i);
	}
	while (!isEmpty(&q))
	{
		printf("Peek: %d\n", Peek(&q));
		printf("Dequeue: %d\n", Dequeue(&q));
	}
}
