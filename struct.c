#include<stdio.h>

typedef struct
{
	int age;
	char name[];
}
person;

int main(void){
	person arr[10];

	printf("Enter person name and age : ");
	scanf("%s %d", arr[1].name, &arr[1].age);
	printf("\nName is %s, age is %d\n", arr[1].name, arr[1].age);

}
