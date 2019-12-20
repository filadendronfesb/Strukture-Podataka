#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define G printf("GRESKA!!!")
#define MAX 1024

struct Folder;
typedef struct Folder* position;
typedef struct Folder {
	char *name;
	position sibling;
	position child;
}FLD;

struct stog;
typedef struct stog * pos;
typedef struct stog {
	position folder;
	pos next;
}ST;

int CreateRoot(position *);
int CreateHead(pos *);
int Allocation_of_Buffers(char **, char **, char **, char **, char **);
int Print(char *);
int check(char *);
int Make_Directory(position, char *);
position Insert_Directory(position, position);
int Directory(position, char *);
position Enter_Directory(position, char *, pos, char *);
int PushStog(pos, position);
position Exit_Directory(position, char *, pos);
int PopStog(pos stog, position *temp);

int main()
{
	position root = NULL;
	position last = NULL;
	pos stog = NULL;
	char *dirname = NULL;
	char *instruction = NULL;
	char *path = NULL;
	char *buff = NULL;
	char *command = NULL;
	int count = 0;


	if (Allocation_of_Buffers(&path, &dirname, &instruction, &buff, &command) != 0)
		G;

	if (CreateRoot(&root) != 0)
		G;

	last = root;

	if (CreateHead(&stog) != 0)
		G;

	while (strcmp(instruction, "exit") != 0)
	{
		if (Print(path) != 0)
			G;

		memset(command, 0, MAX);
		memset(dirname, 0, MAX);
		memset(instruction, 0, MAX);

		fgets(command, MAX, stdin);
		count = sscanf(command, " %s %s", instruction, dirname);

		switch (check(instruction))
		{
		case 1:
			if (count != 2)
				printf("The syntax of the command is incorrect.\n");
			else
			{
				if (Make_Directory(last, dirname) != 0)
					G;
			}
			break;
		case 2:
			if (count != 1)
				printf("The syntax of the command is incorrect.\n");
			else
				last = Exit_Directory(last, path, stog);
			break;
		case 3:
			if(count != 2)
				printf("The syntax of the command is incorrect.\n");
			else
				last = Enter_Directory(last->child, dirname, stog, path);
			break;
		case 4:
			if (count != 1)
				printf("The syntax of the command is incorrect.\n");
			else
			{
				if (Directory(last->child, path) != 0)
					G;
			}
			break;
		case 5:
			if (count != 1)
				printf("The syntax of the command is incorrect.\n");
			break;
		default:
			printf("'%s' is not recognized as an internal or external command, operable program or batch file.\n", instruction);
			break;
		}
	}

	return 0;
}
position Exit_Directory(position last, char *path, pos stog)
{
	position temp = NULL;

	if (PopStog(stog, &temp) != 0)
		G;

	return temp;
}
int PopStog(pos stog, position *temp)
{
	pos temp1 = NULL;

	temp1 = stog->next;
	stog->next = temp1->next;

	*temp = temp1->next;

	free(temp1);

	return 0;
}
position Enter_Directory(position last, char *dirname, pos stog, char *path)
{
	position curr = NULL;
	curr = last;
	while (curr != NULL && (strcmp(curr->name, dirname) != 0))
		curr = curr->sibling;

	if (curr == NULL)
	{
		printf("The system cannit find the path specified.");
		return last;
	}

	if (PushStog(stog, last) != 0)
		G;

	strcat(path, "\\");
	strcat(path, curr->name);

	return curr;
}
int PushStog(pos stog, position last)
{
	pos NewNode = NULL;

	if (CreateHead(&NewNode) != 0)
		G;

	NewNode->folder = last;
	NewNode->next = stog->next;
	stog->next = NewNode;

	return 0;
}
int Directory(position last, char *path)
{
	position cur = NULL;
	
	if (*path == 0)
		printf("\nRoot : \n\n");
	else
		printf("\n Directory of %s \n", path);
	
	while (last != NULL)
	{
		printf("%s\n", last->name);
		last = last->sibling;
	} 

	return 0;
}
position Insert_Directory(position NN, position child)
{
	position prev = NULL;
	prev = child;

	if (prev == NULL)
		return NN;

	if (strcmp(NN->name, prev->name) < 0)
	{
		NN->sibling = prev;
		return NN;
	}
	else if (strcmp(NN->name, prev->name) == 0)
	{
		printf("Folder already exists!!!");
		return child;
	}
	else
	{
		while ((prev->sibling != NULL) && (strcmp(NN->name, prev->sibling->name) > 0))
			prev = prev->sibling;
		if ((prev->sibling != NULL) && (strcmp(NN->name, prev->sibling->name) == 0))
		{
			printf("Folder already exists!!!");
			return child;
		}
	}

	NN->sibling = prev->sibling;
	prev->sibling = NN;

	return child;
}
int Make_Directory(position p, char *dirname)
{
	position NewNode = NULL;

	NewNode = (position)malloc(sizeof(FLD));
	if (NewNode == NULL)
		G;

	NewNode->child = NULL;
	NewNode->sibling = NULL;

	if (strlen(dirname) != 0) {
		NewNode->name = (char *)malloc(strlen(dirname)* sizeof(char));
		if (NewNode->name == NULL)
			G;
	}

	strcpy(NewNode->name, dirname);

	p->child = Insert_Directory(NewNode, p->child);

	return 0;
}
int check(char *instr)
{
	if (!strcmp(instr, "md"))
		return 1;
	else if (!strcmp(instr, "cd.."))
		return 2;
	else if (!strcmp(instr, "cd"))
		return 3;
	else if (!strcmp(instr, "dir"))
		return 4;
	else if (!strcmp(instr, "exit"))
		return 5;
	else
		return 0;
}
int Print(char *path)
{
	printf("%s>", path);

	return 0;
}
int Allocation_of_Buffers(char **ppath, char **pdirname, char **pinstruction, char **pbuff, char **pcommand)
{
	char *path = NULL;
	char *dirname = NULL;
	char *instruction = NULL;
	char *buff = NULL;
	char *command = NULL;

	path = (char *)malloc(MAX * sizeof(char));
	if (path == NULL)
		G;

	memset(path, '\0', MAX);

	*ppath = path;

	dirname = (char *)malloc(MAX * sizeof(char));
	if (dirname == NULL)
		G;

	memset(dirname, '\0', MAX);

	*pdirname = dirname;

	instruction = (char *)malloc(MAX * sizeof(char));
	if (instruction == NULL)
		G;

	memset(instruction, '\0', MAX);

	*pinstruction = instruction;

	buff = (char *)malloc(MAX * sizeof(char));
	if (buff == NULL)
		G;

	memset(buff, '\0', MAX);

	*pbuff = buff;

	command = (char *)malloc(MAX * sizeof(char));
	if (command == NULL)
		G;

	memset(command, '\0', MAX);

	*pcommand = command;

	return 0;
}
int CreateHead(pos *p)
{
	pos NewNode = NULL;

	NewNode = (pos)malloc(sizeof(ST));
	if (NewNode == NULL)
		G;

	NewNode->folder = NULL;
	NewNode->next = NULL;

	*p = NewNode;

	return 0;
}
int CreateRoot(position *p)
{
	position NewNode = NULL;

	NewNode = (position)malloc(sizeof(FLD));
	if (NewNode == NULL)
		G;

	NewNode->child = NULL;
	NewNode->sibling = NULL;

	NewNode->name = (char *)malloc(4 * sizeof(char));
	if (NewNode->name == NULL)
		G;

	NewNode->name = "Root";

	*p = NewNode;

	return 0;
}