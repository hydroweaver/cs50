#include<stdio.h>

void mergesort(int arr[], int left[], int left_size, int right[], int right_size)
{
	for(int x =0;x<left_size;x++){printf("%d ", left[x]);}
	for(int x =0;x<right_size;x++){printf("%d ", right[x]);}

	int i =0;
	int j =0;
	int c[left_size+right_size];
	int temp =0;
	
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

        for(int i =0;i<left_size+right_size;i++)
        {
                printf("%d- ", arr[i]);

        }

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
		
		split(left, mid);
		split(right, arr_size-mid);
		mergesort(arr, left, mid, right, arr_size-mid);
	}
	else
	{
		return;
	}

}


int main()
{
	int arr[] = {8, 3, 1, 4, 5, 6, 0};

	int arr_size = sizeof(arr)/sizeof(int);

	split(arr, arr_size);
}
