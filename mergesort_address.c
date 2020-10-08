/* Important to note:

How the array is used recursively:

1. Addresses allocated in main are used, and finally the array is sorted there itself.
2. However, during each function call, array allocated in point 1 is not sorted, rather
3. a new array / memory location is created with each recursive call, obviosuly!
4. This call stack calls sort(arr, size) for left and right and finally, calls
5. merge(arr, left, right), NOW, how this works is as follows:
	
	actual array is split into left and right in new memory location
	new memory locations are created until merge is called
	once, merge is done with the arr sent with merge, merge ROLLS into the previous merge
	in the stack, and BY THAT WAY, the arr is passed into the higher / previous call
	so the understanding that the original array is changed in each call was wrong, 
	
	even though its pass by reference, in each subsequent recursive call, a new memoryy location
	is provided for a new small sub array which after merge / sort rolls back to the caller.
	
	e.g. 
	split(831, 3) 					merge(831, left=8, right=31) -> merges sorted 13 & 8 as 138 into 831
	split(8, 1) 	split(31, 2) 			merge(31, left =3, right = 1) -> merges sorted 1 & 3 as 13 into 31
	STOP		split(3, 1) split(1, 1)
			STOP	    STOP
			
	So, more simply:
	
	merge(arr, left, right) gets the sorted array in arr which is provided in it's call.
	
	So it's like merge(unsorted_arr, left, right) merges unsroted_arr into sorted_arr
	and this sorted_arr is then put into the upper level merge and this goes on recursively until the main / original array 		is sorted 
	
	So this is what I was missing, it took me time to understand, where exactly is the value being returned, its returned 		in memory. Although i had to cheat my way through it :)
	
	*/


#include<stdio.h>

void mergesort(int arr[], int arr_size, int left[], int left_size, int right[], int right_size)
{
	printf("\n-------------MERGE\n");
	
	for(int x =0;x<arr_size;x++)
	{
		printf("%p ", &arr[x]);
	}
	
	printf("\nArray before merge is : ");

	
	for(int x =0;x<arr_size;x++)
	{
		printf("%d ", arr[x]);
	}
	
	printf("\nLEFT ADDRESS : ");
	for(int x =0;x<left_size;x++)
	{
		printf("%p ", &left[x]);
	}
	
	printf("\nRIGHT ADDRESS : ");
	for(int x =0;x<arr_size;x++)
	{
		printf("%p ", &right[x]);
	}
	
	int i =0;
	int j =0;
	
	
	
	while(i < left_size && j < right_size)
        {
                if(left[i] < right[j])
                {
                	arr[i+j] = left[i];
                        i++;
                }
                else
                {
                        arr[i+j] = right[j];
                        j++;
                }
        }


        while(i<left_size)
        {
                arr[i+j] = left[i];
                i++;
        }

        while(j<right_size)
        {
                arr[i+j] = right[j];
                j++;
        }
}

void split(int arr[], int arr_size)
{
	printf("\n------------------------------------------------Split\n");
	
	for(int x =0;x<arr_size;x++)
	{
		printf("%p ", &arr[x]);
	}
	
	printf("\nCurrent Array is : ");
	for(int x =0;x<arr_size;x++)
	{
		printf("%d ", arr[x]);
	}
	
	if(arr_size > 1)
	{
	int mid = arr_size / 2;
	int left[mid];
	int right[arr_size-mid];
	
		for(int i = 0; i < mid;i++)
		{	
			left[i] = arr[i];
		}

		for(int i = mid; i < arr_size;i++)
		{
			right[i-mid] = arr[i];
		}

		split(left, mid);
		split(right, arr_size-mid);
		mergesort(arr, arr_size, left, mid, right, arr_size-mid);
		
		printf("\nArray after merge is : ");
		for(int x =0;x<arr_size;x++)
		{
			printf("%d ", arr[x]);
		}
		
		printf("\n");
		
		for(int x =0;x<arr_size;x++)
		{
			printf("%p ", &arr[x]);
		}
		
	}

}


int main()
{
	int arr[] = {8, 3, 1, 4, 5, 6, 0};

	int arr_size = sizeof(arr)/sizeof(int);
	
	for(int x =0;x<arr_size;x++)
	{
		printf("%p ", &arr[x]);
	}

	split(arr, arr_size);
}
