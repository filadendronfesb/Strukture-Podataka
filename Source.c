#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef success
#define success 0
#endif
#ifndef error
#define error 1
#endif


struct osoba;
typedef struct osoba *pozicija;
typedef struct osoba {
	char *ime;
	char *prez;
	int god;
	pozicija next;
}_osoba;


int citanje(pozicija);
int upisivanje(pozicija, char *, char *, int);
int Printanje(pozicija);
int pocetak(pozicija);
int kraj(pozicija);
int brisanje(pozicija);
int trazenje(pozicija);


int main()
{
	_osoba head;
	int x = 0;
	head.next = NULL;

	if (citanje(&head) == error)
		return error;

	printf("Lista izgleda ovako : \n");
	Printanje(head.next);
	
	printf("\nIzaberite broj onog slucaja koji zelite da se izvrsi : \n");
	printf("1 - Dodavanje na pocetak liste\n2 - Dodavanje na kraj liste\n3 - Brisanje odredenog elementa sa liste\n4 - Trazenje elementa u listi\n");
	scanf("%d", &x);

	switch (x)
	{
		case 1 :

			if ((pocetak(&head) == success))
			{
				printf("\nLista izgleda ovako : \n");
				Printanje(head.next);
			}
			else
				return error;
			break;

		case 2 :
			if ((kraj(&head) == success))
			{
				printf("\nLista izgleda ovako : \n");
				Printanje(head.next);
			}
			else
				return error;
			break;

		case 3 :
			if ((brisanje(&head) == success))
			{
				printf("\nLista izgleda ovako : \n");
				Printanje(head.next);
			}
			else
				return error;
			break;

		case 4 :
			if ((trazenje(&head) == success))
				return success;
			else
				printf("\nUnjeli ste nepostojece prezime!\n");
			break;

		default :
			printf("\nNiste unjeli niti jedan od odabira!\n");
			break;
	}

	return success;
}
int trazenje(pozicija g)
{
	char *surname = NULL;

	surname = (char *)malloc(30 * sizeof(char));
	if (surname == NULL)
		return error;

	printf("Unesite prezime koje trazite: \n");
	scanf("%s", surname);

	while (g->next != NULL && strcmp(g->next->prez, surname) != 0)
	{
		g= g->next;
	}

	printf("%s %s %d", g->next->ime, g->next->prez, g->next->god);

	return success;
}
int brisanje(pozicija g)
{
	char *surname = NULL;

	surname = (char *)malloc(30 * sizeof(char));
	if (surname == NULL)
		return error;

	printf("Unesite prezime osobe koju zelite izbrisati : \n");
	scanf("%s", surname);

	while(g->next != NULL && strcmp(g->next->prez, surname) != 0)
	{
		g = g -> next;
	}
	if (g->next != NULL)
	{
		g->next = g->next->next;
	}
	else
	{
		printf("Unjeli ste nepostojece prezime");
	}

	return success;
}
int kraj(pozicija g)
{
	pozicija newNode = NULL;
	
	char *name = NULL, *surname = NULL;
	int year;

	newNode = (pozicija)malloc(sizeof(_osoba));
	if (newNode == NULL)
		return error;

	newNode->ime = (char *)malloc(sizeof(char) * 30);
	if (newNode->ime == NULL)
		return error;

	newNode->prez = (char *)malloc(30 * sizeof(char));
	if (newNode->prez == NULL)
		return error;

	name = (char *)malloc(30 * sizeof(char));
	if (name == NULL)
		return error;

	surname = (char *)malloc(30 * sizeof(char));
	if (surname == NULL)
		return error;

	newNode->next = NULL;

	printf("Unesite ime : \n");
	scanf("%s", name);
	printf("Unesite prezime : \n");
	scanf("%s", surname);
	printf("Unesite godinu : \n");
	scanf("%d", &year);

	strcpy(newNode->ime, name);
	strcpy(newNode->prez, surname);
	newNode->god = year;

	while (g->next != NULL)
	{
		g = g->next;
	}

	newNode->next = g->next;
	g->next = newNode;

	return success;
}
int pocetak(pozicija g)
{
	pozicija newNode = NULL;

	newNode = (pozicija)malloc(sizeof(_osoba));
	if (newNode == NULL)
		return error;

	newNode->ime = (char *)malloc(sizeof(char) * 30);
	if (newNode->ime == NULL)
		return error;

	newNode->prez = (char *)malloc(30 * sizeof(char));
	if (newNode->prez == NULL)
		return error;

	newNode->next = NULL;

	printf("Unesite ime : \n");
	scanf("%s", newNode -> ime);
	printf("Unesite prezime : \n");
	scanf("%s", newNode -> prez);
	printf("Unesite godinu : \n");
	scanf("%d", &(newNode->god));

	

	newNode->next = g->next;
	g->next = newNode;

	return success;
}
int Printanje(pozicija g)
{
	while (g != NULL)
	{
		printf("%s %s %d\n", g->ime, g->prez, g->god);
		
		g = g->next;
	}

	return success;
}
int upisivanje(pozicija g, char *name, char *surname, int year)
{
	pozicija newNode = NULL;

	newNode = (pozicija)malloc(sizeof(_osoba));
	if (newNode == NULL)
		return error;

	newNode->ime = (char *)malloc(30 * sizeof(char));
	if (newNode->ime == NULL)
		return error;
	
	newNode->prez = (char *)malloc(30 * sizeof(char));
	if (newNode->prez == NULL)
		return error;

	newNode->next = NULL;

	strcpy(newNode->ime, name);
	strcpy(newNode->prez, surname);
	newNode->god = year;

	newNode->next = g->next;
	g->next = newNode;

	return success;
}
int citanje(pozicija g)
{
	FILE *f = NULL;
	char *tempname;
	char *tempsurn;
	int tempgod;

	tempname = (char *)malloc(30 * sizeof(char));
	if (tempname == NULL)
		return error;

	tempsurn = (char *)malloc(30 * sizeof(char));
	if (tempsurn == NULL)
		return error;

	f = fopen("osoba.txt", "r");
	if (f == NULL)
		return error;

	while (!feof(f))
	{
		fscanf(f, "%s %s %d", tempname, tempsurn, &tempgod);

		if (upisivanje(g, tempname, tempsurn, tempgod) == error)
			return error;
	}

	return success;
}