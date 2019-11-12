#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifndef SUCSESS
#define SUCSESS 0
#endif

#ifndef ERROR
#define ERROR 1
#endif

struct list;
typedef struct list* position;
typedef struct list {
	int x;
	position next;

}_list;

int OpenFile(position);
int SortedPutin(int, position);
int MakePresjek(position, position, position);
int MakeUnija(position, position, position);
int Check(position,int);
int Print(position);

int main() {

	_list L1, L2, LU ,LP;
	L1.next = NULL;
	L2.next = NULL;
	LU.next = NULL;
	LP.next = NULL;

	printf("Unesite ime datoteke u kojem se nalazi prva lista (sa .txt nastavkom)\n");

	if (OpenFile(&L1) == ERROR)
	{
		perror("error reading list 1\n");
		return ERROR;
	}

	printf("Unesite ime datoteke u kojem se nalazi drugi lista (sa .txt nastavkom)\n");

	if (OpenFile(&L2) == ERROR)
	{
		perror("error reading list 2\n");
		return ERROR;
	}

	if (MakePresjek(L1.next, L2.next, &LP) == ERROR)
	{
		perror("MakePresjek error\n");
		return ERROR;
	}
	
	if (MakeUnija(L1.next, L2.next, &LU) == ERROR)
	{
		perror("MakeUnija error\n");
		return ERROR;
	}

	printf("Prva lista\n");
	if (Print(&L1) == ERROR)
		{
		perror("Printing error");
		return ERROR;
		}

	printf("Druga lista\n");
	if (Print(&L2) == ERROR)
	{
		perror("Printing error");
		return ERROR;
	}

	printf("UNIJA\n");
	if (Print(&LU) == ERROR)
	{
		perror("Printing error");
		return ERROR;
	}

	printf("PRESJEK\n");
	if (Print(&LP) == ERROR)
	{
		perror("Printing error");
		return ERROR;
	}

	system("pause");
	return SUCSESS;
}
int OpenFile(position P)
{
	FILE* f;
	char* filename;
	int x = 0;

	filename = (char*)malloc(30 * sizeof(char));
	scanf("%s", filename);

	f = fopen(filename, "r");

	while (!feof(f))
	{
		fscanf(f, "%d", &x);
		if (SortedPutin(x, P) == ERROR)
		{
			perror("function SortedScan problem\n");
			return ERROR;
		}

	}

	return SUCSESS;

}
int SortedPutin(int x, position P)
{
	position NewNode = NULL;

	NewNode = (position)malloc(sizeof(_list));

	NewNode->x = x;
	NewNode->next = NULL;

	while ((P->next != NULL) && (P->next->x > x))
	{
		P = P->next;
	}

	NewNode->next = P->next;
	P->next = NewNode;

	return SUCSESS;

}
int Check(position P,int trazeni)
{
	while (P->next != NULL && P->next->x != trazeni)
	{
		P = P->next;
	}
	
	if (P->next != NULL && P->next->x == trazeni)
	{
		return ERROR;
	}

	return SUCSESS;

}
int MakePresjek(position prvi, position drugi, position presjek)
{
	position temp = NULL;
	int x2 = 0;
	
	while (prvi != NULL)
	{
		temp = drugi;
		
		while (temp != NULL)
		{
			if (temp->x == prvi->x)
			{
				x2 = temp->x;
				
				if (Check(presjek,x2) == SUCSESS)
					{
						if ((SortedPutin(x2, presjek) == ERROR))
						{
							perror("Error");
							return ERROR;
						}

					}
			}

			temp = temp->next;
		}

		prvi = prvi->next;
	}


	return SUCSESS;


}
int MakeUnija(position prvi, position drugi, position unija)
{
	int x2 = 0;
	
	while (prvi != NULL)
	{
		x2 = prvi->x;

		if (Check(unija, x2) == SUCSESS)
		{
			if (SortedPutin(x2, unija) == ERROR)
			{
				perror("Error");
				return ERROR;
			}
		}

		prvi = prvi->next;
	}
	
	while (drugi != NULL)
	{
		x2 = drugi->x;

		if (Check(unija, x2) == SUCSESS)
		{
			if (SortedPutin(x2, unija) == ERROR)
			{
				perror("Error");
				return ERROR;
			}
		}
		
		drugi = drugi->next;
	
	}

	return SUCSESS;
}
int Print(position P)
{
	while (P->next != NULL)
	{
		printf("\t%d", P->next->x);

		P = P->next;
	}

	printf("\n\n");

	return SUCSESS;

}