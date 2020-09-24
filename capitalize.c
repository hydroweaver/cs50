#include<stdio.h>
#include<string.h>

int main(void)
{
	char c[10];
	printf("Enter string : ");
	scanf("%s", c);
	for(int i =0, l = strlen(c); i < l;i++)
	{
		if(c[i] >= 'a' && c[i] <= 'z')
		{
			c[i] = c[i] - 32;
		}
		printf("%c ", c[i]);
	}
	printf("\nLowercase : %s\n", c);
}
