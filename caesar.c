#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc == 2)
	{
		char pt[10];
		char ct[10];
		int shift;
		printf("plaintext: ");
		scanf("%s",pt); 
		for(int i=0, l = strlen(pt); i<l;i++)
		{	
			if((pt[i] >= 'a' && pt[i] <= 'z'))
			{
				ct[i] = (((int)pt[i]-97+atoi(argv[1]))%26)+97;
			}
		}
		printf("ciphertext: %s\n", ct);
	}
	else
	{
		printf("Enter second argument. \n");
	}
}
