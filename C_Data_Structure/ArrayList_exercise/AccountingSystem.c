#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef struct Accout{
	int id;
	char name[N];
	int debit;
	int credit;
}Account;

typedef struct ArrayList{
	Account * a;
	int size;
	int capacity;
}ArrayList;

typedef struct T{
	int openning;
	int debits[100];
	int credits[100];
	int ndebit;
	int ncredit;
}T;

void init(ArrayList *list, int capacity)
{
	list->capacity = capacity;
	list->size = 0;
	list->a = (Account*)malloc(sizeof(Account)*capacity); 
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
		list->a = (Account*)realloc(list->a, sizeof(Account)*list->capacity);
	}
}

void Output(ArrayList *list)
{
	for (int i = 0; i < list->size; i++)
	{
		printf("%d %s", list->a[i].id, list->a[i].name);
	}
}

void addTail(ArrayList *list, Account acc)
{
	resize(list);
	list->a[list->size++] = acc;
}

void freeArrayList(ArrayList *list)
{
	free(list->a);
}

void showAccount()
{
	//Reading from text file
	char buff[90];
	ArrayList list;
	init(&list, 9);
	FILE *f;
	fopen_s(&f, "List.txt", "rt");
	while (!feof(f))
	{
		fgets(buff, 90, f);
		char *context = NULL;
		char *w = strtok_s(buff, "#", &context); //tach chuoi theo ky tu "#", giu lai phan duoi trong context
		Account acc;
		acc.id = atoi(w);
		w = strtok_s(NULL, "#", &context);		//tra lai phan context
		strcpy_s(acc.name, N, w);
		addTail(&list, acc);
	}
	fclose(f);
	Output(&list);
	printf("\n\n");
}

void doubleEntry()
{
	//Console output
	printf("\nNhap tai khoan No: ");
	int debit;
	scanf_s("%d", &debit);
	printf("\nNhap tai khoan Co: ");
	int credit;
	scanf_s("%d", &credit);
	printf("\nNhap so tien: ");
	int amount;
	scanf_s("%d", &amount);
	getchar();
	printf("\nGhi chu: ");
	char remark[50];
	gets_s(remark, 50);

	//Output to file
	FILE *f2;
	fopen_s(&f2, "DoubleEntry.txt", "at");
	fprintf(f2, "\n%d#%d#%d#%s ", debit, credit, amount, remark);
	fclose(f2);
	printf("\n\n");
}


int LaySoDau(int id)
{
	while (id >= 10)
	{
		id /= 10;
	}
	return id;
}

char* FindName(int id)
{
	FILE *f;
	fopen_s(&f, "List.txt", "rt");
	char Buff[100];
	while (!feof(f))
	{
		char *context = NULL;
		fgets(Buff, 100, f);
		char* w = strtok_s(Buff, "#", &context);
		if (atoi(w) == id)
		{
			fclose(f);
			return _strdup(context);
		}
	}
	fclose(f);
	return 0;
}
void BeginningBalance()
{
	int id, amount;
	int ts = 0, nv = 0;
	int so_dau;

	FILE *f;
	fopen_s(&f, "BeginningBalance.txt", "rt");
	while (fscanf_s(f, "%d %d", &id, &amount) > 0)
	{
		
		printf("%d %s %d\n", id, FindName(id), amount);
		
		so_dau = LaySoDau(id);
		if (so_dau > 2)
		{
			ts += amount;
		}
		else
		{
			nv += amount;
		}

	}
	fclose(f);
	printf("Tai san: %d\n", ts);
	printf("Nguon von: %d\n", nv);
	printf("\n\n");
}

void initT(T * t)
{
	t->openning = t->ndebit = t->ncredit = 0;
}

int findOpenning(int tid)
{
	int id, amount;
	FILE *f;
	fopen_s(&f, "BeginningBalance.txt", "rt");
	while (fscanf_s(f,"%d %d", &id, &amount) >0)
	{
		if (tid == id)
		{
			fclose(f);
			return amount;
		}
	}
	fclose(f);
	return 0;
}

void printT(T *t)
{
	int sum[2] = { 0, 0 };
	printf("So du dau ky: %d\n", t->openning);
	printf("\tPhat sinh ben co:|\tPhat sinh ben no:\n");
	int i;
	for (i = 0; i < t->ndebit && i< t->ncredit; i++)
	{
		printf("\t%d\t|\t%d\n", t->debits[i], t->credits[i]);
		sum[0] += t->debits[i];
		sum[1] += t->credits[i];
	}
	for (; i < t->ndebit; i++)
	{
		printf("\t%d\t|\t\n", t->debits[i]);
		sum[0] += t->debits[i];
	}
	for (;i< t->ncredit; i++)
	{
		printf("\t\t|\t%d\n", t->credits[i]);
		sum[1] += t->credits[i];
	}
	/*for (int i = 0; i < t->ndebit; i++)
	{
		printf("%d\n", t->debits[i]);
		sum[0] += t->debits[i];
	}
	
	printf("Phat sinh ben no: ");
	for (int i = 0; i < t->ncredit; i++)
	{
		printf("%d\n", t->credits[i]);
		sum[1] += t->credits[i];
	}*/
	printf("\nTong phat sinh co: %d		Tong phat sinh no: %d\n", sum[0], sum[1]);
	printf("So du cuoi ky: %d\n", t->openning + sum[0] - sum[1]);
	printf("\n\n");
}


void schemaT()
{
	int id, beginningBalance;
	
	printf("Nhap tk can tim: ");
	scanf_s("%d", &id);
	
	T t;
	initT(&t);

	t.openning = findOpenning(id);

	FILE *f;
	fopen_s(&f, "DoubleEntry.txt", "rt");
	while (!feof(f))
	{
		char Buff[100];
		char *context = NULL;
		fgets(Buff, 100, f);
		char *w = strtok_s(Buff, "#", &context);
		int v[3];
		v[0] = atoi(w);
		w = strtok_s(NULL, "#", &context);
		v[1] = atoi(w);
		w = strtok_s(NULL, "#", &context);
		v[2] = atoi(w);

		if (v[0] == id)
		{
			t.debits[t.ndebit++] = v[2];
		}
		else if (v[1] == id)
		{
			t.credits[t.ncredit++] = v[2];
		}
	}
	fclose(f);
	printT(&t);

}


void main()
{
	int choice;
	void *menu[] = { "Exit", "Show Account", "Double Entry", "Xem so du dau ky", "Xem so do chu T", "Bang can doi ke toan" };
	void(*f[])() = { showAccount, doubleEntry, BeginningBalance, schemaT};
	printf("%d\n", (sizeof(menu) / sizeof(menu[0])));
	do
	{
		
		for (int i = 0; i < (sizeof(menu) / sizeof(menu[0])); i++)
		{
			printf("%d. %s \n", i, menu[i]);
		}

		scanf_s("%d", &choice);
		if (choice > 0) f[choice - 1]();








		/*printf("0: Exit \n");
		printf("1: Show Account \n");
		printf("2: Double Entry \n");
		printf("3: T Map \n");
		printf("4: Xem So Du \n");
		printf("5: Bang Can Doi Ke Toan \n");*/
		


		/*switch (choice)
		{
		case 1: 
			showAccount(); break;
		case 2: 
			doubleEntry(); break;
		default:
			break;
		}*/
	} while (choice != 0);
}
