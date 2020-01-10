#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

struct Element;
typedef struct Element *position;
typedef struct Element
{
	int x;
	position left;
	position right;
}el;

position Unos_novog_el(position, int);
position NewNode(int);
//int Ispis(position);

int main(void)
{
	position stablo = NULL;
	int izbor = 0;
	int temp = 0;

	while (izbor != 5)
	{
		printf("MENU\n1 - Unosenje novog elementa\n2 - Ispis elemenata\n3 - Brisanje\n4 - Pronalazenje nekog elemnta\n");
		printf("Unesite radnju koju zelite obaviti : ");
		scanf("%d", &izbor);

		switch (izbor)
		{
		case 1:
			printf("Unesite vrijednost novog elemnta : ");
			scanf("%d", &temp);

			stablo = Unos_novog_el(stablo, temp);
			break;
		case 2:
			/*if (Ispis(&stablo) != 0)
				printf("Greska!!!\n");*/
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			printf("Niste unjeli ni jednu od ponudenih opcija, pokusajte ponovo!\n");
		}
	}

	return 0;
}
position NewNode(int el)
{
	position Temp = NULL;

	Temp = (position)malloc(sizeof(el));
	if (Temp == NULL)
		printf("Greska!!!\n");

	Temp->left = NULL;
	Temp->right = NULL;
	Temp->x = el;

	return Temp;
}
position Unos_novog_el(position S, int el)
{
	if (S == NULL)
	{
		S = NewNode(el);

		S->x = el;
		S->left = NULL;
		S->right = NULL;

		return S;
	}

	if (el < S->x)
	{
		S->left = Unos_novog_el(S->left, el);
		return S;
	}

	if (el > S->x)
	{
		S->right = Unos_novog_el(S->right, el);
		return S;
	}

	return S;
}