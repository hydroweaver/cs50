#include<stdio.h>

void modify_arr_again(int *arr)
{
	for(int i =0;i<4;i++)
	{
		arr[i] *= 10;
	}
}

void modify_arr(int *arr, int x)
{
	for(int i =0;i<4;i++)
	{
		arr[i] += 10;
	}

	modify_arr_again(arr);

	x += 10;
}

int main()
{
	int arr[] = {1,2,3,4};
	int x = 20;

	modify_arr(arr, x);

	for(int i =0;i<4;i++)
	{
		printf("%d ", arr[i]);
	}

	printf("x is changed to : %d", x);

	printf("\n");
}

/* Passing array to a function using func(arr, size) is same as func(arr)
 * if func is defined as func(int *arr).
 * Arrays are passed by reference by default, that is,
 * they would be changed in same place, unlike,
 * regular int which are passed by value, that is,
 * a copy is passed instead of the original variable
 *
 * modify_arr(int *arr) can be changed to modify(int arr[], int size) if
 * when it's called size of the array is also passed, if not, arr is
 * passed as a pointer to arr or *arr. But without the size you won't be
 * able to iterate over it.*/
