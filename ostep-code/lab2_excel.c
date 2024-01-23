#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(){
	printf("pid: %d",(int) getpid());

	// tao ban sao cua tien trinh hien tai. 
	// ham fork() dung de tao tien trinh con
	int sc = fork(); 

	if(sc < 0){
		printf("fork failed!\n");
		exit(-1);
	}else if (sc == 0){
		printf("Child pid: %d", (int)getpid());
		execl("/bin/ls","ls","-lt",".",NULL);
		printf("this shouldn't print out");
	}else{
		
	}
}
