#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

int main(char* argv[]){

	int cs = fork();
	
	if(cs < 0){
		printf("fork failed!\n"); 
		exit(1);
	}else if(cs == 0){
		printf("child process\n");
		printf("file name: ");
		scanf("%s",&argv);

		execl("/bin/vim","vi",argv[],NULL);

	}
}
