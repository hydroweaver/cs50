#include<stdio.h>
#include<string.h>

int main(void)
{
	char c[10];
	printf("Enter string : ");
	scanf("%s", c);
	printf("%lu\n", strlen(c));
	for(int i =0, l = strlen(c); i < l;i++)
	{
		printf("%c ", c[i]);
		printf("%c ", c[i] - 32);
	}
}
