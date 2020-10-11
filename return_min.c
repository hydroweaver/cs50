#include<stdio.h>

typedef struct
{
	int votes;
}
candidate;


candidate candidates[10];

int main()
{

	int a[] = {5,6,4,1,2,6,7,8,9};

	int size = sizeof(a)/sizeof(int);

	for(int i=0;i<size;i++)
	{
		candidates[i].votes = a[i];
	}

	int min = candidates[0].votes;
	for(int i=0;i<size;i++)
	{
		if(candidates[i].votes < min)
		{
			min = candidates[i].votes;
		}
	}

	printf("%d", min);
	printf("\n");
}
