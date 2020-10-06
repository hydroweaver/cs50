#include<stdio.h>

int main()
{
	int a[] = {8};
	int b[] = {1, 3};

	int i =0;
	int j =0;
	int a_size = sizeof(a)/sizeof(int);
	int b_size = sizeof(b)/sizeof(int);
	int c[a_size+b_size];

	while(i < a_size && j < b_size)
	{
		if(a[i] < b[j])
		{
			c[i+j] = a[i];
			i++;
		}
		else
		{
			c[i+j] = b[j];
			j++;
		}
	}


	while(i<a_size)
	{
		c[i+j] = a[i];
		i++;
	}

	while(j<b_size)
	{
		c[i+j] = b[j];
		j++;
	}

	for(int i =0;i<a_size+b_size;i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
}
