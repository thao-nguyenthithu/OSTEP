#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h>

int main(){
	int pid = fork();
        sleep(20);	
	if(pid < 0){
	       	printf("Loi!");
		exit(-1);
	}
	else if(pid == 0){
	       	printf("Tien trinh con!");
		exit(0);
	}
	else{
	       	printf("Tien trinh cha!");
		exit(0);
	}
}
