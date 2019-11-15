#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<ctype.h>
#define G printf("GRESKA!!!")

struct element;
typedef struct element *position;
typedef struct element {
	int x;
	position next;

}_el;

int Push_Stog(position);
int Random_Number();
int Print_Stog(position);
int Pop(position);
int Push_Red(position);
int Print_Red(position);
int Menu();

int main(void)
{
	int provjera = 1;

	srand((unsigned)time(NULL));

	while (provjera != 0)
	{
		provjera = Menu();
	}

	return 0;
}

int Menu()
{
	_el stog, red;
	stog.next = NULL;
	red.next = NULL;
	char *c = NULL;
	int kraj = 0;

	c = (char *)malloc(sizeof(char));
	if (c == NULL)
		G;

	while (!kraj)
	{
		printf("\nIZBORNIK :\n");
		printf("A - Push stog\nB - Pop stog\nC - Push red\nD - Pop red\nE - Kraj\n");
		scanf("%s", c);
		*c = toupper(*c);

		switch (*c)
		{
		case 'A':
		{
			if (Push_Stog(&stog) != 0)
				G;
			printf("Stog sad izgleda ovako : \n");
			if (Print_Stog(&stog) != 0)
				G;
		}
		break;
		case 'B':
		{
			if (Pop(&stog) != 0)
				G;
			printf("Stog sad izgleda ovako : \n");
			if (Print_Stog(&stog) != 0)
				G;
		}
		break;
		case 'C':
		{
			if (Push_Red(&red) != 0)
				G;
			printf("Red sad izgleda ovako : \n");
			if (Print_Red(&red) != 0)
				G;
		}
		break;
		case 'D':
		{
			if (Pop(&red) != 0)
				G;
			printf("Red sad izgleda ovako : \n");
			if (Print_Red(&red) != 0)
				G;
		}
		break;
		case 'E':
		{
			kraj = 1;
		}
		break;
		default:
			printf("Niste unjeli niti jedno od ponudenih odabira !!!\n");
		}
	}

	return 0;
}
int Pop(position p)
{
	position prev = NULL;

	if (p->next == NULL)
	{
		printf("Nema nista u redu!!!\n");
		return 0;
	}
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	if (p->next == NULL)
	{
		free(p);
		prev->next = NULL;
	}

	return 0;
}
int Print_Red(position p)
{
	while (p->next != NULL)
	{
		printf("%d ", p->next->x);

		p = p->next;
	}

	return 0;
}
int Push_Red(position red)
{
	position novaglava = NULL;

	novaglava = (position)malloc(sizeof(_el));
	if (novaglava == NULL)
		G;

	novaglava->next = NULL;
	novaglava->x = Random_Number();

	novaglava->next = red->next;
	red->next = novaglava;

	return 0;
}
int Print_Stog(position p)
{
	if (p->next == NULL)
		return 0;

	Print_Stog(p->next);

	printf("%d\n", p->next->x);

	return 0;
}
int Push_Stog(position stog)
{
	position novaglava = NULL;

	novaglava = (position)malloc(sizeof(_el));
	if (novaglava == NULL)
		G;

	novaglava->next = NULL;
	novaglava->x = Random_Number();

	while (stog->next != NULL)
		stog = stog->next;

	novaglava->next = stog->next;
	stog->next = novaglava;

	return 0;
}
int Random_Number()
{
	return rand() % (100 - 10) + 10;
}