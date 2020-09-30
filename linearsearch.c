#include<stdio.h>

int main(){
	int num[] = {3,6,1,2,3,7,0,2};

	int search_term;

	printf("Enter search number : ");
	scanf("%d", &search_term);

	printf("%li\n", sizeof(num));

	for(int i = 0; i < sizeof(num)/sizeof(int); i++){
		printf("i is %d\n", i);
		if(num[i] == search_term){
			printf("\nNumber found at %d position", i+1);
			return i;
		}
	

	}
	printf("\nNumber not found");
}

