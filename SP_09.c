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
}_el;

position Unos_novog_el(position, int);
position NewNode(int);
int Ispis(position);
position Trazi(int, position);
position Brisanje(int, position);
position TraziMax(position);

int main(void)
{
	position stablo = NULL;
	position trazeni_element = NULL;
	int izbor = 0;
	int temp = 0;

	while (izbor != 5)
	{
		printf("\nMENU\n1 - Unosenje novog elementa\n2 - Ispis elemenata\n3 - Brisanje\n4 - Trazi element\n5 - Gasi\n");
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
			if (Ispis(stablo) != 0)
				printf("Greska!!!\n");
			break;
		case 3:
			printf("Unesite element koji zelite izbrisati : ");
			scanf("%d", &temp);
			stablo = Brisanje(temp, stablo);
			break;
		case 4:
			printf("Unesite element koji zelite pronaci : ");
			scanf("%d", &temp);
			trazeni_element = Trazi(temp, stablo);

			if (trazeni_element != NULL)
				printf("Element %d je na adresi %x !!!\n", temp, (unsigned int)trazeni_element);
			else
				printf("Trazeni elemnt ne postoji!!!\n");
			break;
		case 5:
			break;
		default:
			printf("Niste unjeli ni jednu od ponudenih opcija, pokusajte ponovo!\n");
		}
	}

	return 0;
}
position TraziMax(position cvor_za_izbrisati)
{
	if (cvor_za_izbrisati != NULL)
	{
		if (cvor_za_izbrisati->right != NULL)
		{
			cvor_za_izbrisati = cvor_za_izbrisati->right;
			TraziMax(cvor_za_izbrisati);
		}
	}

	return cvor_za_izbrisati;
}
position Brisanje(int el, position stablo)
{
	position temp = NULL;

	if (stablo == NULL)
		return NULL;

	if (el < stablo->x)
	{
		stablo->left = Brisanje(el, stablo->left);
		return stablo;
	}
	if (el > stablo->x)
	{
		stablo->right = Brisanje(el, stablo->right);
		return stablo;
	}
	if (stablo == NULL)
	{
		printf("Nema stabla!!!\n");
		return stablo;
	}

	//provjera broja djece
	if ((stablo->left != NULL) && (stablo->right != NULL))
	{
		temp = TraziMax(stablo->left);
		stablo->x = temp->x;

		stablo->left = Brisanje(stablo->x, stablo->left);

		return stablo;
	}

	temp = stablo;

	if (stablo->left == NULL)
		stablo = stablo->right;
	else
		stablo = stablo->left;

	free(temp);
	

	return stablo;
}
position Trazi(int el, position stablo)
{
	if (stablo == NULL)
		return NULL;

	if (stablo->x > el)
		return Trazi(el, stablo->left);

	if (stablo->x < el)
		return Trazi(el, stablo->right);

	return stablo;
}
int Ispis(position stablo)
{
	if (stablo != NULL)
	{
		Ispis(stablo->left);

		printf("(%d)", stablo->x);

		Ispis(stablo->right);
	}
	return 0;
}
position NewNode(int el)
{
	position Temp = NULL;

	Temp = (position)malloc(sizeof(_el));
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