#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define G printf("GRESKA!!!")

struct polinom;
typedef struct polinom *position;
typedef struct polinom
{
	int koef;
	int exp;
	position slijed;
}_poli;

int Citanje(position);
int Lista(position, int, int);
int Ispisivanje(position, position);
int Zbrajanje(position, position, position);
int Rezultat(position);
int Mnozenje(position, position, position);
int Pretraga(position, int);


int main(void)
{
	_poli p1;
	_poli p2;
	_poli s;
	_poli m;

	p1.slijed = NULL;
	p2.slijed = NULL;
	s.slijed = NULL;
	m.slijed = NULL;

	if (Citanje(&p1) != 0)
		G;

	if (Citanje(&p2) != 0)
		G;

	if (Ispisivanje(&p1, &p2) != 0)
		G;

	if (Zbrajanje(&p1, &p2, &s) != 0)
		G;

	printf("\n");

	if (Mnozenje(&p1, &p2, &m) != 0)
		G;

	return 0;
}
int Mnozenje(position p1, position p2, position umn)
{
	position pocetak = NULL;
	pocetak = p2;
	int max = 0, i = 0;

	while (p1->slijed != NULL)
	{
		while (p2->slijed != NULL)
		{
			Lista(umn, p1->slijed->koef * p2->slijed->koef, p1->slijed->exp + p2->slijed->exp);
			p2 = p2->slijed;
		}
		p2 = pocetak;
		p1 = p1->slijed;
	}

	printf("\n");

	max = umn->slijed->exp;

	while (umn->slijed != NULL)
	{
		if (i == 0) {
			Pretraga(umn, max - i);
			umn = umn->slijed;
			i++;
		}
	}
	return 0;
}
int Pretraga(position umn, int exp)
{
	position p = NULL;
	int zbroj = 0;

	p = (position)malloc(sizeof(_poli));
	if (p == NULL)
		G;
	p->slijed = NULL;
	
	while(umn->slijed != NULL)
	{ 
		if (umn->slijed->exp == exp)
		{
			zbroj += umn->slijed->koef;
			umn = umn->slijed;
		}
		else
		{
			umn = umn->slijed;
		}
		
	}

	Lista(p, zbroj, exp);
	printf("%dx^%d + ", p->slijed->koef, p->slijed->exp);

	free(p);
	return 0;
}
int Zbrajanje(position p1, position p2, position suma)
{
	while (p1->slijed != NULL || p2->slijed != NULL)
	{
		if (p1->slijed->exp == p2->slijed->exp)
		{
			Lista(suma, p1->slijed->koef + p2->slijed->koef, p1->slijed->exp);
			p1 = p1->slijed;
			p2 = p2->slijed;
		}
		else if (p1->slijed->exp < p2->slijed->exp)
		{
			Lista(suma, p2->slijed->koef, p2->slijed->exp);
			p2 = p2->slijed;
		}
		else if (p1->slijed->exp > p2->slijed->exp)
		{
			Lista(suma, p1->slijed->koef, p1->slijed->exp);
			p1 = p1->slijed;
		}

	}

	if (Rezultat(suma) != 0)
		G;

	return 0;
}
int Rezultat(position rez)
{
	printf("\nRezultat\n");

	while (rez->slijed != NULL)
	{
		printf("%dx^%d", rez->slijed->koef, rez->slijed->exp);
		if (rez->slijed->slijed != NULL)
			printf(" + ");
		rez = rez->slijed;
	}
	
	return 0;
}
int Ispisivanje(position p1, position p2)
{
	printf("1. polinom : \n");
	while (p1->slijed != NULL)
	{
		printf("%dx^%d", p1->slijed->koef, p1->slijed->exp);
		if (p1->slijed->slijed != NULL)
			printf(" + ");
		p1 = p1->slijed;
	}

	printf("\n2. polinom : \n");
	while (p2->slijed != NULL)
	{
		printf("%dx^%d", p2->slijed->koef, p2->slijed->exp);
		if (p2->slijed->slijed != NULL)
			printf(" + ");
		p2 = p2->slijed;
	}
	
	return 0;
}
int Citanje(position p)
{
	FILE * f = NULL;
	int i = 0, j = 0;
	int koef[10] = { 0 }, exp[10] = { 0 };
	int max = 0;
	int temp = 0, temp2 = 0;
	char *filename = NULL;

	filename = (char *)malloc(20 * sizeof(char));
	if (filename == NULL)
		G;

	printf("Unesite ime datoteke sa nastavkom .txt : ");
	scanf("%s", filename);

	f = fopen(filename, "r");
	if (f == NULL)
		G;

	while (!feof(f))
	{

		fscanf(f, "%d %d", &koef[i], &exp[i]);
		i++;

	}

	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (exp[i] < exp[j])
			{
				temp = exp[i];
				exp[i] = exp[j];
				exp[j] = temp;

				temp2 = koef[i];
				koef[i] = koef[j];
				koef[j] = temp2;

			}
		}
	}

	
	for (i = 0; i < 10; i++)
		if (koef[i] == 0 && exp[i] == 0)
			break;
		else
		{
			if (Lista(p, koef[i], exp[i]) != 0)
				G;
		}

	return 0;
}
int Lista(position p, int koef, int exp)
{
	position novaglava = NULL;

	novaglava = (position)malloc(sizeof(_poli));
	if (novaglava == NULL)
		G;

	novaglava->slijed = NULL;
	novaglava->koef = koef;
	novaglava->exp = exp;

	while (p->slijed != NULL)
		p = p->slijed;

	novaglava->slijed = p->slijed;
	p->slijed = novaglava;

	return 0;
}

