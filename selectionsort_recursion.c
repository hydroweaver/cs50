#include<stdio.h>


/*void *swap(int arr[], int arr_size, int current_pos, int smallest_num_pos, int smallest_num)
{
	

	//return arr[];
}*/

int main()
{
	int arr[] = {4,3,1,5,6,7,0,1,4,7};
	int arr_size = sizeof(arr)/sizeof(int);
	int smallest_num;
	int smallest_num_pos;

	for(int j = 0; j < arr_size; j++)
	{
		smallest_num = arr[j];
		smallest_num_pos = j;
		for(int i = j; i < arr_size; i++)
		{

			if(arr[i] < smallest_num) 
			{	
				smallest_num = arr[i];
				smallest_num_pos = i;
				printf("\nSmallest number is %d and position is %d", smallest_num, smallest_num_pos+1);
			}
		}
	
		arr[smallest_num_pos] = arr[j];
		arr[j] = smallest_num;

		printf("\nNew array is : ");
		
		for(int i =0;i<arr_size;i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}

