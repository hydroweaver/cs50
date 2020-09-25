#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[])
{
	char pt[30];
	char ct[30];

	if(argc == 2 && strlen(argv[1])!=26)
	{
		printf("Some error...\n");
		return 1;
	}

	printf("plaintext : ");
	/*scanf does not provide overflow protection, as advised*/
	/*scanf("%[^\n]", pt);*/
	fgets(pt, 30, stdin);
	int l = strlen(pt)+1; /*adding extra char to compensate for \0*/
	/* just to explain - fgets adds a \n in the end which is read by strlen, 
	then since strlen does not read \0 in the end, l = str(pt) + 1 needs to be added
	to get correct length including \0, also we dont add \0 in the entry*/
	for(int i =0;i<l;i++)
	{
		if(isupper(pt[i]) && isalpha(pt[i]))
		{
			ct[i] = argv[1][pt[i]-65];
		}
		else
		{
			if(!isupper(pt[i]) && isalpha(pt[i]))
			{
				ct[i] = tolower(argv[1][toupper(pt[i])-65]);
			}
			else
			{
				ct[i] = pt[i];
			}
		}

	}
	printf("ciphertext : %s", ct);
}
