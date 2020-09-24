#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	/* instead of using string in main function declaration for argv, we have used
	*argv, as they have not introduced pointers yet, just googled to refer char * */
	printf("%s %s\n",argv[0], argv[1]);
}
