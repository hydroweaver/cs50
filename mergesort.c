void mergesort(int arr[], int left[], int left_size, int right[], int right_size)
{
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

	printf("\nSorted Array is : ");
	for(int x =0;x<left_size+right_size;x++){printf("%d ", arr[x]);}

        printf("\n");
}

void split(int arr[], int arr_size)
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
	
		printf("\nSplitting Left\nArray is : ");
		for(int i=0;i<mid;i++){printf("%d ", left[i]);}
		split(left, mid);

		printf("\nSplitting Right\nArray is : ");
		for(int i=0;i<arr_size-mid;i++){printf("%d ", right[i]);}
		split(right, arr_size-mid);
		
		printf("\nMerging Left & Right : ");
		for(int i=0;i<mid;i++){printf("%d ", left[i]);}
		for(int i=0;i<arr_size-mid;i++){printf("%d ", right[i]);}
		printf("\nCurrent arr is : ");//This current array is deceptive, since arr is changin in mergesort function and getting displayed.
		// arr is changed as its passed as a pointer
		// We can see it being passed up until the start
		// and the merge is done, meaning
		// displaying intermittent arr does not display the
		// recursive calls to itself in mergersort
		for(int i=0;i<arr_size;i++){printf("%d ", arr[i]);}
		mergesort(arr, left, mid, right, arr_size-mid);
	}
	else
	{
		printf("\nWill not split single item\n");
	}

}


int main()
{
	int arr[] = {8, 3, 1, 4, 5, 6, 0};

	int arr_size = sizeof(arr)/sizeof(int);

	split(arr, arr_size);
}
