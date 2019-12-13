#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#define G printf("Greska!!!\n")

struct element;
typedef struct element *position;
typedef struct element {
	int x;
	position next;
}_el;

int Ucitavanje(position);
int Stavljanje_na_Stog(position, int);
int Pop(position);
int Operacija(int, int, char *);
int Print(position);
int Brojac(position);

int main(void)
{
	_el head;
	head.next = NULL;

	if (Ucitavanje(&head) != 0)
		G;

	return 0;
}
int Ucitavanje(position p)
{
	FILE *f = NULL;
	char *filename = NULL;
	char *temp = NULL;
	int prvibr = 0, drugibr = 0, rez = 0;

	filename = (char *)malloc(20 * sizeof(char));
	if (filename == NULL)
		G;

	temp = (char *)malloc(20 * sizeof(char));
	if (temp == NULL)
		G;

	printf("Unesite ime datoteke : \n");
	scanf("%s", filename);

	strcat(filename, ".txt");

	f = fopen(filename, "r");
	if (f == NULL)
		G;

	while (!feof(f))
	{
		fscanf(f, "%s ", temp);

		if (isdigit(*temp))
		{
			if (Stavljanje_na_Stog(p, atoi(temp)) != 0)
				G;

			printf("Ucitajemo novi element na stog :\n");
			if (Print(p) != 0)
				G;
		}
		else
		{
			prvibr = Pop(p);
			drugibr = Pop(p);
			if (drugibr == -1)
			{
				printf("Nedovoljno operanada !!!\n");
				return 0;
			}


			rez = Operacija(prvibr, drugibr, temp);
			if (Stavljanje_na_Stog(p, rez) != 0)
				G;

			printf("Nakon nailaska na operator \"%s\": \n", temp);
			if (Print(p) != 0)
				G;
		}
	}

	if (Brojac(p) != 1)
		printf("Previse operanada !!!\n");
	
	return 0;
}
int Brojac(position p)
{
	int br = 0;

	while (p->next != NULL)
	{
		br++;
		p = p->next;
	}

	return br;
}
int Print(position p)
{
	while (p->next != NULL)
	{
		printf("%d\n", p->next->x);
		p = p->next;
	}

	return 0;
}
int Operacija(int a, int b, char *c)
{
	switch (*c)
	{
		case '+' :
			return b + a;
			break;
		case '*' :
			return b * a;
			break;
		case '-' :
			return b - a;
			break;
		case '/' :
			return b / a;
			break;
	}
}
int Pop(position p)
{
	position temp = NULL;
	int a = 0;

	if (p->next != NULL)
	{
		temp = p->next;
		p->next = p->next->next;
		a = temp->x;
		free(temp);

		return a;
	}
	else
		return -1;
		
}
int Stavljanje_na_Stog(position p, int a)
{
	position novaglava = NULL;

	novaglava = (position)malloc(sizeof(_el));
	if (novaglava == NULL)
		G;

	novaglava->x = a;

	novaglava->next = p->next;
	p->next = novaglava;

	return 0;
}