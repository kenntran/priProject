#include <stdio.h>
#include <stdbool.h>

#define MAX 100

//Cai tien Queue 
typedef struct Entity{
	int quantity;
	int price;
}Entity;

typedef struct Queue{
	Entity a[MAX];
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

bool Enqueue(Queue *q, Entity x)
{
	if (isFull(q))
	{
		return false;
	}
	q->a[(q->front + q->size) % MAX] = x;
	q->size++;
	return true;
}

Entity Peek(const Queue *q)
{
	if (isEmpty(q))
	{
		exit(0);
	}
	return q->a[q->front];
}

Entity Dequeue(Queue *q)
{
	if (isEmpty(q))
	{
		exit(0);
	}
	q->size--;
	Entity saved = q->a[q->front];
	q->front = (q->front + 1) % MAX;
	return saved;
}

void main()
{
	Queue q;
	init(&q);
	FILE *f;
	fopen_s(&f, "Data.txt", "rt");
	FILE *X;
	fopen_s(&X, "XuatFile.txt", "wt");
	while (!feof(f))
	{
		Entity entity;
		char ch;
		int quantity, price;
		ch = fgetc(f);
		if (ch == 'N')
		{			
			fscanf_s(f, "%d %d", &entity.quantity, &entity.price);
			Enqueue(&q, entity);
			printf("N %d %d\n", entity.quantity, entity.price);
			/*fscanf_s(f, "%d %d", &quantity, &price);
			printf("%d %d \n", quantity, price);*/
			fprintf_s(X, "N %d %d\n", entity.quantity, entity.price);
		}		
		else 
		{
			
			fscanf_s(f, "%d", &entity.quantity);
			while (!isEmpty(&q))
			{
				Entity t = Peek(&q);
				if (entity.quantity >= t.quantity)
				{
					entity.quantity -= t.quantity;
					Dequeue(&q);
					printf("X %d %d \n", t.quantity, t.price);
					fprintf_s(X, "X %d %d\n", t.quantity, t.price);
				}
				else
				{
					printf("X %d %d\n",  entity.quantity, t.price);
					q.a[q.front].quantity = t.quantity - entity.quantity;
					fprintf_s(X, "X %d %d\n", entity.quantity, t.price);
					break;
				}
			}
			
		}
		fgetc(f);
	}
	fclose(X);
	fclose(f);
}
