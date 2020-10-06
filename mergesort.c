#include<stdio.h>


void print_new_mids(int arr[], int arr_size)
{

	if(arr_size > 1)
	{
	int mid = arr_size / 2;
	int left[mid];
	int right[arr_size-mid];
	
		printf("\nleft array is : ");
		for(int i = 0; i < mid;i++)
		{	
			left[i] = arr[i];
			printf("%d ", arr[i]);
		}

		printf("\nright array is : ");
		for(int i = mid; i < arr_size;i++)
		{
			right[i-mid] = arr[i];
			printf("%d ", arr[i]);
		}

		printf("\n");
		
		int left_size = sizeof(left)/sizeof(int);
		int right_size = sizeof(right)/sizeof(int);

/*		if(left_size == 1 && right_size == 1)
		{
			if(left[0] > right[0])
			{
				int temp = right[0];
				right[0] = left[0];
				left[0] = temp;
			}

			printf("\nSorted New small array is : ");
			int new_array[] = {left[0], right[0]};
			for(int i =0;i<2;i++)
			{
				printf("%d ", new_array[i]);
			}
		}*/

		print_new_mids(left, sizeof(left)/sizeof(int));
		print_new_mids(right, sizeof(right)/sizeof(int));
		printf("\nMerge left of size %ld and right of size %ld\n", sizeof(left)/sizeof(int), sizeof(right)/sizeof(int));
	}

}


int main()
{
	int arr[] = {6, 3, 8, 5, 2, 7, 4, 1, 0};

	int arr_size = sizeof(arr)/sizeof(int);

//	printf("\n");

	print_new_mids(arr, arr_size);
}
