#include<stdio.h>

int main()
{
	int arr[] = {6, 3, 8, 5, 2, 7, 4, 1, 98, 23, 1, 0, 9, 5, 4, 3, 2, 1};
	int arr_size = sizeof(arr)/sizeof(int);
	int swap_count=0;

	for(int j = 0;j<arr_size;j++)
	{

		for(int i = 0;i<arr_size-(j+1);i++)
		{
			if(arr[i] > arr[i+1])
			{
				int temp = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = temp;
				swap_count += 1;
			}
		}

		printf("New array is : ");
		for(int i =0;i<arr_size;i++)
		{
			printf("%d ", arr[i]);
		}	
		printf(" Swap count is : %d\n", swap_count);
		if(swap_count == 0)
		{
			printf("\nArray is sorted, halting algorithm\n");
			return 0;
		}
		else
		{
			swap_count = 0;
		}

	}
}
