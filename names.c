#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
	
	char *names[] = {"alpha", "beta", "charlie", "delta", "gamma"};

	if(argc == 2){
		for(int i=0;i<strlen(*names);i++){
			if(strcmp(names[i], argv[1])==0){
				printf("Found\n");
				return 0;
			}
		}
		printf("Not Found\n");
		return 0;
	}
	else{
		printf("\nEnter 2 arguments");
	}

}



