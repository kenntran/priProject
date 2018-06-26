#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

typedef struct PriorityQueue {
	int arr[MAX];
	int size;
}PriorityQueue;

void init(PriorityQueue *p)
{
	p->size = 0;
}

bool isEmpty(const PriorityQueue *q)
{
	return q->size == 0;
}

bool isFull(const PriorityQueue *q)
{
	return q->size == MAX;
}

void swap(int arr[], int k, int l)
{
	int temp = arr[k];
	arr[k] = arr[l];
	arr[l] = temp;
}

void heapifyUp(int arr[], int pos)
{
	int p;
	while (pos > 0)
	{
		p = (pos - 1) / 2;
		if (arr[pos] < arr[p])
		{
			break;
		}
		swap(arr, pos, p);
		pos = p;
	}
}

bool Enqueue(PriorityQueue *q, int x)
{
	if (isFull(q))
	{
		return false;
	}
	else
	{
		q->arr[q->size++] = x;
		heapifyUp(q->arr, q->size - 1);
		return true;
	}
}

void heapifyDown(int arr[], int root, int last)
{
	int pos = root * 2 + 1;
	while (pos <= last)
	{
		if (pos < last && arr[pos] < arr[pos + 1])
		{
			pos++;
		}
		if (arr[root] > arr[pos])
		{
			break;
		}
		swap(arr, root, pos);
		root = pos;
		pos = 2 * last + 1;
	}
}

int Dequeue(PriorityQueue *q)
{
	if (isEmpty(q))
	{
		exit(0);
	}
	else
	{
		int x = q->arr[0];
		q->size--;
		swap(q->arr, 0, q->size);
		heapifyDown(q->arr, 0, q->size - 1);
		return x;
	}
}


void main()
{
	PriorityQueue que;
	init(&que);

	Enqueue(&que, 7);
	Enqueue(&que, 2);
	Enqueue(&que, 8);
	Enqueue(&que, 1);
	Enqueue(&que, 6);
	Enqueue(&que, 4);

	while (!isEmpty(&que))
	{
		printf("%d ", Dequeue(&que));
	}
	getch();
}
