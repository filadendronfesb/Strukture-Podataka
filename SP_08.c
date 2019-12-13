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


struct object;
typedef struct object* position_obj;
typedef struct object {
	char name[30];
	position_obj right_next;
	position_obj down_first;
}obj;

struct status;
typedef struct status* position_stat;
typedef struct status {
	position_obj object;
	position_stat next;
}stat;



int Dir_Print();
int MakeObject_ThatIsChildToCurrentObject(position_obj);
int ChangeDir_Forward(position_obj,position_stat);
int ChangeDir_Backward();
int BackToNull();

int main()
{
	obj Null_Object;
	stat Null_Status;
	int i;
	int a;
	char sime[30];
	
	Null_Object.right_next= NULL;
	Null_Object.down_first= NULL;

	Null_Status.next = NULL;
	Null_Status.object = &Null_Object;



	printf("\t\t MENI \t\t");
	printf("\t\t 1)md \t 2) cd.. \t 3)cd dir \t 4)dir \t 5)exit \t\n");
	
	switch (a)
	{
	case '1':
		printf("PutIn name of wanted object\n");
		scanf("%s", sime);



		MakeObject_ThatIsChildToCurrentObject(&Null_Object);


		break;
	case '2':


		break;
	case '3':


		break;
	case '4':


		break;
	case '5':


		break;
	}
		




	return SUCSESS;
}
int MakeObject_ThatIsChildToCurrentObject(position_obj Current)
{
	position_obj New_Child;
	New_Child = (position_obj)malloc(sizeof(obj));
	
	New_Child->down_first = NULL;
	New_Child->right_next = NULL;

	while (Current->down_first != NULL)
	{
		Current = Current->down_first;
	}

	Current->right_next = New_Child;
	
}
