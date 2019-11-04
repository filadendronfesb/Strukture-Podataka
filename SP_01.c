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
int UzimamPodatke(int, _stud *);
int Ispisujem(int, _stud *);

int main()
{
	int br = 0;
	_stud *student = NULL;

	br = BrojimRedtke();

	student = (_stud *)malloc(br * sizeof(_stud));

	UzimamPodatke(br, student);

	Ispisujem(br, student);

	return 0;
}
int BrojimRedtke()
{
	char c = 0;
	int br = 0;
	FILE *f = NULL;

	f = fopen("studenti.txt", "r");

	if (f == NULL)
		printf("Error!");

	do {
		c = getc(f);

		if (c == '\n')
			br++;

	} while (feof(f) == 0);

	fclose(f);

	return br;
}
int UzimamPodatke(int br, _stud *student)
{
	int i = 0;
	char temp[30] = {0};
	char temp2[30] = {0};
	FILE *f = NULL;

	f = fopen("studenti.txt", "r");

	if (f == NULL)
		printf("Error!");

	for (i = 0; i < br; i++)
	{
		fscanf(f, "%d %s %s", &student[i].bod, temp, temp2);

		student[i].ime = (char *)malloc(strlen(temp) * sizeof(char));
		if (student[i].ime == NULL)
			printf("Error!");
		student[i].prez = (char *)malloc(strlen(temp2) * sizeof(char));
		if (student[i].prez == NULL)
			printf("Erorr!");

		strcpy(student[i].ime, temp);
		strcpy(student[i].prez, temp2);
	}

	fclose(f);

	return 0;
}
int Ispisujem(int br, _stud *student)
{
	int i = 0;
	FILE *f = NULL;

	f = fopen("studenti.txt", "r");

	if (f == NULL)
		printf("Error!");

	printf("\tIme    Prezime\t RE Bod\t\t\t APS Bod\n");

	for (i = 0; i < br; i++)
		printf(" %10s %10s \t %.2f percent \t\t %d \n", student[i].ime, student[i].prez, (float)((student[i].bod / (float)50) * 100), student[i].bod);

	fclose(f);

	return 0;
}
