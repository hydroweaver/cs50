#include<stdio.h>

float average(int len, int arr[])
{
	int sum = 0;
	for(int i=0;i<len;i++)
	{
		sum += arr[i];
	}
	printf("%d\n", sum);
	return sum / (float) len;
}

int main()
{
	int array[3] = {1, 2, 3};
	int result = average(3, array);
	printf("average is %d : ", result);
}
