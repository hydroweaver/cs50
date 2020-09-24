#include<stdio.h>

int main()
{
	int stars = 1;
	int lines = 5;
	int max_stars =  (2*(lines-1)) + 1;
	for(int i = 0; i < lines ; i++)
	{		int mid = max_stars / 2;
			int blanks = max_stars - stars;
			for(int j = 0; j < max_stars; j++)
			{
				if(j<(blanks/2) || j>((blanks/2)+stars-1))
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}

			}
			printf("\n");
			stars += 2;
	}
}

