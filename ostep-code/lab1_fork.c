#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

//Lab1: process creation fork()
//run "ps" command to view the PID - Processe ID - of the processes

int main(){
	
	// tao ban sao cua tien trinh hien tai 
	// ham fork() tra ve ID cua tien trinh con neu no la cha va 0 cho tien trinh con 
	int pid = fork();

	if(pid < 0){
		printf("fork failed!\n"); 
		exit(-1);
	}else if(pid == 0){
		//child
		printf("child process pid: %d\n", (int) getpid());
		exit(0);
	}else{
		//parent process wait for child prcess
		printf("parent process of %d pid: %d \n",pid,(int) getpid());
	}
}
