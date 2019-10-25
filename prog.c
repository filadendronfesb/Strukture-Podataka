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

struct student;
typedef struct student* position;
typedef struct student {
	char* ime;
	char* prez;
	int god;
	position next;
}stud;

int ReadFile(position);
int Insert(position, char*, char*, int);
int PrintWhole(position);
int AddUpfront(position);
int AddBack(position);
int Delete(position);
int Find(position);
int AddUpfrontSomeone(position);
int AddBackSomeone(position);
int Sort(position);
int PutInFile(position);




int main()
{
	stud head;
	head.next = NULL;
	int userchoice = 0;
	//char cwd[190];

	/*if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
	printf("Current dir : %s\n", cwd);
	}
	else
	{
	perror("getcwd() error");
	return ERROR;
	}
	*/

	if (ReadFile(&head) == ERROR)
		return ERROR;

	PrintWhole(head.next);

	fflush(stdin);

	printf("\n");
	printf("\t\tMENI\t\t\n");
	printf("\n");
	printf("Upisite broj ispred naredbe koju hocete realizirati\n");
	printf("1)Dodaj element na pocetak\n2)Ispisi listu\n3)Dodaj element na kraj liste\n4)Brisi element liste\n5)Nadji element iz liste\n6)Dodaj novi element iza odreðenog elementa\n7)Dodaj novi element ispred odreðenog elemnta\n8)Sortiraj listu po prezimenima\n9)Upisi listu u datoteku10)Ucitaj novu listu iz druge datoteke\n");
	printf("\n");
	scanf("%d", &userchoice);
	printf("\n");
	switch (userchoice)
	{
	case 1:

		if ((AddUpfront(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("AddUpFront() ");
			return ERROR;
		}

		break;

	case 2:

		if ((PrintWhole(head.next) == SUCSESS))
		{
			printf("Ovo je vas registar\n");
		}
		else
		{
			perror("PrintWhole() ");
			return ERROR;
		}

		break;

	case 3:

		if ((AddBack(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("AddBack() ");
			return ERROR;
		}
		break;

	case 4:

		if ((Delete(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("Delete() ");
			return ERROR;
		}

		break;

	case 5:

		if ((Find(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("AddBack() ");
			return ERROR;
		}

		break;

	case 6:

		if ((AddUpfrontSomeone(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("AddUpfrontSomeone() ");
			return ERROR;
		}

		break;

	/*case 7:

		if ((AddBackSomeone(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("AddBackSomeone() ");
			return ERROR;
		}

		break;

	case 8:

		if ((Sort(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("Sort() ");
			return ERROR;
		}

		break;

	case 9:

		if ((PutInFile(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("PutInFile() ");
			return ERROR;
		}

		break;

	case 10:

		if ((ReadFile(&head) == SUCSESS))
		{
			printf("Vasa nova lista\n");
			PrintWhole(head.next);
		}
		else
		{
			perror("ReadFile() ");
			return ERROR;
		}

		break;*/

	default:
		printf("Niste unjeli jedan od ponudenih brojeva,nista od odabira\n");
		break;
	}

	return SUCSESS;
}
int ReadFile(position P)
{
	FILE* fp;
	char* buffime = NULL;
	char* buffprez = NULL;
	int buffgod = 0;
	char* filename = NULL;

	buffime = (char*)malloc(25 * sizeof(char));
	if (buffime == NULL)
		return ERROR;
	buffprez = (char*)malloc(25 * sizeof(char));
	if (buffprez == NULL)
		return ERROR;


	fp = fopen("studenti.txt", "r");

	if (fp == NULL)
		return ERROR;


	while (!feof(fp))
	{
		fscanf(fp, "%s %s %d", buffime, buffprez, &buffgod);


		if ((Insert(P, buffime, buffprez, buffgod) == ERROR))
			return ERROR;

	}

	return SUCSESS;

}
int Insert(position P, char* name, char* surname, int yrs)
{
	position NewNode = NULL;

	NewNode = (position)malloc(sizeof(stud));
	if (NewNode == NULL)
		return ERROR;

	NewNode->ime = (char*)malloc(25 * sizeof(char));
	if (NewNode->ime == NULL)
		return ERROR;
	NewNode->prez = (char*)malloc(25 * sizeof(char));
	if (NewNode->prez == NULL)
		return ERROR;
	NewNode->next = NULL;

	strcpy(NewNode->ime, name);
	strcpy(NewNode->prez, surname);
	NewNode->god = yrs;


	NewNode->next = P->next;
	P->next = NewNode;

	return SUCSESS;
}
int PrintWhole(position P)
{
	printf("\tIme\tPrezime\tGodiste \n");
	printf("\n");

	while (P != NULL) {

		printf("\t%s\t%s\t%d \n", P->ime, P->prez, P->god);

		P = P->next;

	}
	return SUCSESS;
}
int AddUpfront(position P)
{
	position NewNode = NULL;
	

	NewNode = (position)malloc(sizeof(stud));
	if (NewNode == NULL)
		return ERROR;

	NewNode->ime = (char*)malloc(25 * sizeof(char));
	if (NewNode->ime == NULL)
		return ERROR;
	NewNode->prez = (char*)malloc(25 * sizeof(char));
	if (NewNode->prez == NULL)
		return ERROR;
	NewNode->next = NULL;

	printf("Unesite ime novog covjeka\n");
	scanf("%s", NewNode->ime);

	printf("Unesite prezime novog covjeka\n");
	scanf("%s", NewNode->prez);

	printf("Unesite godine novog covjeka\n");
	scanf("%d", &(NewNode->god));

	NewNode->next = P->next;
	P->next = NewNode;

	return SUCSESS;
}
int AddBack(position P)
{
	position NewNode = NULL;


	NewNode = (position)malloc(sizeof(stud));
	if (NewNode == NULL)
		return ERROR;

	NewNode->ime = (char*)malloc(25 * sizeof(char));
	if (NewNode->ime == NULL)
		return ERROR;
	NewNode->prez = (char*)malloc(25 * sizeof(char));
	if (NewNode->prez == NULL)
		return ERROR;
	NewNode->next = NULL;

	printf("Unesite ime novog covjeka\n");
	scanf("%s", NewNode->ime);

	printf("Unesite prezime novog covjeka\n");
	scanf("%s", NewNode->prez);

	printf("Unesite godine novog covjeka\n");
	scanf("%d", &(NewNode->god));


	while (P->next != NULL)
	{
		P = P->next;
	}

	NewNode->next = P->next;
	P->next = NewNode;

	return SUCSESS;

}
int Delete(position P)
{
	char* surname = NULL;

	surname = (char*)malloc(sizeof(char) * 25);
	if (surname == NULL) return ERROR;

	printf("Unesi prezime covjeka kojeg zelis maknuti\n");
	scanf("%s", surname);

	while (P->next != NULL && strcmp(P->next->prez, surname) != 0)
	{
		P = P->next;
	}

	if (P->next != NULL)
	{
		P->next = P->next->next;
	}



	else
	{
		printf("Unjeli ste nepostojece prezime\n");
	}




	return SUCSESS;





}
int Find(position P)
{
	char* surname;

	surname = (char*)malloc(sizeof(char) * 20);
	if (surname == NULL) return ERROR;

	printf("Unesite prezime trazene osobe \n");
	scanf("%s", surname);

	while (P->next != NULL && strcmp(P->next->prez, surname) != 0) {

		P = P->next;
	}

	printf("%s %s %d \n", P->next->ime, P->next->prez, P->next->god);





	return SUCSESS;
}
int AddUpfrontSomeone(position P)
{
	position NewNode = NULL;
	char *covijek = NULL;


	NewNode = (position)malloc(sizeof(stud));
	if (NewNode == NULL)
		return ERROR;

	NewNode->ime = (char*)malloc(25 * sizeof(char));
	if (NewNode->ime == NULL)
		return ERROR;
	NewNode->prez = (char*)malloc(25 * sizeof(char));
	if (NewNode->prez == NULL)
		return ERROR;
	NewNode->next = NULL;

	covijek = (char*)malloc(30 * sizeof(char));
	if (covijek == NULL)
		return ERROR;

	printf("Unesite ime novog covjeka\n");
	scanf("%s", NewNode->ime);

	printf("Unesite prezime novog covjeka\n");
	scanf("%s", NewNode->prez);

	printf("Unesite godine novog covjeka\n");
	scanf("%d", &(NewNode->god));

	printf("Unesite prezime covjeka ispred kojega zelite dodati novog covijeka\n");
	scanf("%s", covijek);

	while ((P->next) != NULL && (strcmp(covijek,P->next->prez)!= 0))
	{
		P = P->next;
	}
	
	if (P->next == NULL)
		perror("AddUpfrontSomeone()");
	
	else
	{
		NewNode->next = P->next;
		P->next = NewNode;
	}
	
	return SUCSESS;

}
/*int AddBackSomeone(position);
int Sort(position);
int PutInFile(position);
*/
