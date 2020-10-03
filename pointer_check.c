#include<stdio.h>

int main()
{
	int *a;
	int b = 22;
	int x;
	a = &b;
	x = *a;
	printf("%d\n", x+1);
	printf("%d\n", ++x);
	printf("%d\n", x);
}


