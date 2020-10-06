#include<stdio.h>
#include<stdlib.h>

int factorial(int n)
{
	if(n == 1)
	{
		printf("1\n");
		return 1;
	}
	else
	{	
		printf("%d * ",n);
		return n*factorial(n-1);
	}
}

int main(int argc, char *argv[])
{
	int final;
	if(argc == 2)
	{	
		printf("Factorial of %d is %d.\n", atoi(argv[1]), factorial(atoi(argv[1]))); 
	}
	else
	{
		printf("Provide second argument.\n");
		return 1;
	}
}
