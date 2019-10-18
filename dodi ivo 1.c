#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct {
	char *ime;
	char *prez;
	int bod;
}_stud;

int BrojimRedtke();
void UzimamPodatke(int, _stud *);
void Ispisujem(int, _stud *);

int main()
{
	int br;


	_stud *student;


	br = BrojimRedtke();

	student = (_stud *)malloc(br * sizeof(_stud));

	UzimamPodatke( br, student);

	Ispisujem( br, student);

	return 0;
}


int BrojimRedtke()
{
	char c;
	int br;
	FILE *f;

	f = fopen("studenti.txt", "r");


	if (f == NULL)
	{
		printf("Error!");
	}

	br = 1;//u zadnjem red nema newline-a

	do {

		c = getc(f);
		if (c == '\n')
			br++;

	} while (feof(f) == 0);


	fclose(f);

	return br;

}
void UzimamPodatke(int br, _stud *student)
{
	int i;
	char temp[30];
	char temp2[30];
	FILE *f;

	f = fopen("studenti.txt", "r");


	if (f == NULL)
	{
		printf("Error!");
	}



	for (i = 0; i<br; i++)
	{

		fscanf(f, "%d %s %s", &student[i].bod, temp, temp2);

		student[i].ime = (char *)malloc(strlen(temp) * sizeof(char));
		student[i].prez = (char *)malloc(strlen(temp2) * sizeof(char));

		strcpy(student[i].ime, temp);
		strcpy(student[i].prez, temp2);

	}

	fclose(f);

}
void Ispisujem(int br, _stud *student)
{
	int i;
	FILE *f;

	f = fopen("studenti.txt", "r");


	if (f == NULL)
	{
		printf("Error!");
	}



	printf("\tIme    Prezime\t RE Bod\t\t\t APS Bod\n");

	for (i = 0; i<br; i++)
	{
		printf(" %10s %10s \t %.2f percent \t\t %d \n", student[i].ime, student[i].prez, (float)((student[i].bod / (float)50) * 100), student[i].bod);
	}


	fclose(f);
}