#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<ctype.h>
#include<stdlib.h>
#define G { printf("GRESKA!!!") perror("eeh")}

#ifndef SUCSESS
#define SUCSESS 0
#endif

#ifndef ERROR
#define ERROR 1
#endif


struct element;
typedef struct element *position;
typedef struct element {
	char x;
	position next;

}_el;

int ReadFromFile(position);
int PutIn(char *, position);


int main()
{
	_el stog;

	stog.next = NULL;

	if (ReadFromFile(&stog) == ERROR)
	{
		printf("GRESKA!!!");
		perror("eeh");
	}











}
int ReadFromFile(position P)
{

	FILE *f;
	char* temp;

	f = fopen("postfix.txt", "r");

	temp = (char *)malloc(sizeof(char));

	while (!feof(f))
	{
		fscanf(f, "%c", temp);
		
		if (PutIn(temp, P) == ERROR)
			{
				printf("GRESKA!!!");
				perror("eeh");
			}
	}

	return SUCSESS;
}
int PutIn(char * c,position P)
{
	position NewNode;
	int a;
	

	NewNode = (position)malloc(sizeof(_el));

	NewNode->next = NULL;

	if(isdigit(c) == 1)
	
	a = atoi(c);



	while (P->next != NULL)
	{
		P = P->next;
	}

	NewNode->next = P->next;
	P->next = NewNode;

	return SUCSESS;

}