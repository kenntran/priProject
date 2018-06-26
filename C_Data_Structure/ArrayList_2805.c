#include <stdio.h>
#include <stdbool.h>

#define		MAX		100

typedef struct ArrayList{
	int a[MAX];
	int size;
}ArrayList ;

void init(ArrayList *list)
{
	list->size = 0;
}

bool isEmpty(const ArrayList *list)
{
	return list->size == 0;
}

bool isFull(const ArrayList *list)
{
	return list->size == MAX;
}

bool addTail(ArrayList *list, int x)
{
	if (isFull(list))
	{
		return false;
	}
	list->a[list->size] = x;
	list->size++;
	//list->a[list->size++] = x;
	return true;
}

bool addHead(ArrayList *list, int x)
{
	if (isFull(list))
	{
		return false;
	}
	for (int i = list->size++; i > 0; i--)
	{
		list->a[i] = list->a[i - 1];
	}
	list->a[0] = x;
	return true;
}

bool insert(ArrayList *list, int k, int x)
{
	if (k < 0 || k >= list->size || isFull(list))
	{
		return false;
	}
	for (int i = list->size++; i > k; i--)
	{
		list->a[i] = list->a[i - 1];
	}
	list->a[k] = x;
	return true;
}
void allElememt(const ArrayList *list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d ", list->a[i]);
	}
	printf("\n");
}

bool removeTail(ArrayList *list)
{
	if (isEmpty(list))
	{
		return false;
	}
	list->size--;
	return true;
}

bool removeHead(ArrayList *list)
{
	if (isEmpty(list))
	{
		return false;
	}
	list->size--;
	for (int i = 0; i < list->size; i++)
	{
		list->a[i] = list->a[i + 1];
	}
	return true;
}

bool removeAt(ArrayList *list, int k)
{
	if (isEmpty(list) || k < 0 || k >= list->size)
	{
		return false;
	}
	list->size--;
	for (int i = k; i < list->size; i++)
	{
		list->a[i] = list->a[i + 1];
	}
	return true;
}
void main()
{
	ArrayList l;
	init(&l);
	FILE *f;
	fopen_s(&f,"Data.txt", "rt");
	int x;
	while (fscanf_s(f,"%d", &x) > 0)
	{
		//addTail(&l, x);
		addHead(&l, x);
	}
	fclose(f);
	allElememt(&l);
	printf("size of ArrayList: %d \n", l.size);
	/*insert(&l, 3, 9999);
	allElememt(&l);
	removeTail(&l);
	allElememt(&l);
	addTail(&l, 8888);
	
	allElememt(&l);
	removeHead(&l);
	allElememt(&l);*/
	removeAt(&l,3);
	allElememt(&l);
	printf("size of ArrayList: %d \n", l.size);
	/*if (isEmpty(&l) == true)
	{
		printf("List is empty -- Danh sach trong \n");
	}
	else{
		printf("List is not empty -- Danh sach khong trong \n");
	}*/

	//int a = 88, b = 99;
	//int *const q = &a; // giong array -- khong the thay doi dia chi tro toi
	//a = 77;
	//*q = 55;
	////q = &b; //


	//const int *c; = int const *d; //khong the thay doi gia tri tro toi - *c = 100; //error





	/*List list;
	list.a[0] = 100;
	list.n = 5;
	printf("a[0]: %d n: %d\n", list.a[0], list.n);

	List *p;
	p = &list;
	p->a[0] = 999;
	p->n = 555;
	printf("a[0]: %d n: %d\n", p->a[0], p->n);*/
}