#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayList{
	int *a;
	int size;
	int capacity;
}ArrayList;


void init(ArrayList *list, int capacity)
{
	list->capacity = capacity;
	list->size = 0;
	list->a = (int*)malloc(sizeof(int) * capacity);
}

bool isEmpty(const ArrayList *list)
{
	return list->size == 0;
}

void resize(ArrayList *list)
{
	if (list->size == list->capacity)
	{
		list->capacity *= 2;
		list->a = (int*)realloc(list->a, sizeof(int) * list->capacity);
	}
}

void addTail(ArrayList *list, int x)
{
	resize(list);
	list->a[list->size++] = x;
}

void addHead(ArrayList *list, int x)
{
	resize(list);
	for (int i = list->size++; i > 0; i--)
	{
		list->a[i] = list->a[i - 1];
	}
	list->a[0] = x;
}

void Output(const ArrayList *list)
{
	for (int i = 0; i < list->size; ++i)
	{
		printf("%d ", list->a[i]);
	}
}

void main()
{
	int abc;
	ArrayList list;
	init(&list, 3);
	//if (isEmpty(&list)) printf("Array is empty \n");
	FILE *f;
	fopen_s(&f, "Text.txt", "rt");
	while (fscanf_s(f, "%d", &abc) > 0)
	{
		//addTail(&list, abc);
		addHead(&list, abc);
	}
	fclose(f);
	Output(&list);
	printf("\n");






	/*Student *stu = h();
	printf("%d %s \n", stu->ID, stu->name);

	int *p = f();
	printf("%d \n", *p);
	
	int *q = g();
	for (int i = 0; i < 3; i++)
	{
		printf("%d \n", q[i]);
	}
	free(stu);
	free(p);
	free(q);*/

}

//int *f()
//{
//	int *a = (int*)malloc(sizeof(int));
//	*a = 7;
//	return a;
//}
//
//int *g()
//{
//	int *a = (int*)malloc(sizeof(int)*3);
//	for (int i = 0; i < 3; i++)
//	{
//		a[i] = i;
//	}
//	return a;
//}
//
//typedef struct Student
//{
//	int ID;
//	char name[10];
//
//}Student;
//
//Student *h()
//{
//	Student *s = (Student*)malloc(sizeof(Student));
//	s->ID = 1;
//	strcpy_s(s->name, 10, "ABC");
//	return s;
//}