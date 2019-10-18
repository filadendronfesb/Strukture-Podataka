#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#define MAX 30

typedef struct oso {	char ime[MAX];	char prez[MAX];	int god;	struct oso *pozicija;}osoba;osoba * unos_napocetak(int)
int main()
{
	osoba *head = NULL;
	osoba *f;
	int i;

	f = (osoba *)malloc(5 * sizeof(osoba));

	for (i = 0; i < 5; i++) {
		printf("%d. student : ", i + 1);
		scanf("%s %s %d", f[i].ime, f[i].prez, &f[i].god);
	}







	return 0;
}