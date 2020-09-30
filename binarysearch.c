#include<stdio.h>

int main(void){
	int number;
	/*int nums[] = {0,1,3,7,8,9,23,67};*/
	int nums[] = {0,1,3,7,8,9,23};

	printf("Enter number to search : ");
	scanf("%d", &number);


		int mid = (sizeof(nums)/sizeof(int))/2;
		printf("Mid is : %d", mid);
		if(number == nums[mid]){
			printf("\nPosition : %d", mid);
			return mid;
		}
		else if(number <= nums[mid]){
			for(int j = 0; j < nums[mid]; j++){
				if(nums[j] == number){
					printf("\nPosition : %d", j+1);
					return j;
				}
				
			
			}
			return 1;
		}
		else{
			for(int j = mid; j < sizeof(nums)/sizeof(int); j++){
				if(nums[j] == number){
					printf("\nPosition : %d", j+1);
					return j;
				}
			}
			return 0;
		}
}
