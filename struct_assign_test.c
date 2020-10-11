#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[20];
	int age;
}person;

person persons[10];


int main(int argc, char *argv[])
{
	//persons[0].name = argv[2];
	if(argc == 2)
	{
		printf("\nargv[1] is %s", argv[1]);
		printf("\nargv[1] size is %ld", strlen(argv[1]));
		
		for(int i=0;i<strlen(argv[1]);i++)
		{
			persons[0].name[i] = argv[1][i];
		}
	
		for(int i=0;i<20;i++)
		{
			printf("%c", persons[0].name[i]);
		}
		
		printf("\n");
	}
}
