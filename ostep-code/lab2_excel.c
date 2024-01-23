#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
#include<sys/wait.h> 

int main(){
	printf("pid: %d\n",(int) getpid());

	// tao ban sao cua tien trinh hien tai. 
	// ham fork() dung de tao tien trinh con
	int sc = fork(); 

	if(sc < 0){
		printf("fork failed!\n");
		exit(-1);
	}else if (sc == 0){
		printf("Child pid: %d\n", (int)getpid());
		
		// thay doi tien trinh con bang chuong trinh chi dinh
		execl("/bin/ls","ls","-lt",".",NULL);
		
		// dong nay se khong bao gio duoc thuc hien vi tien trinh con da thay doi chuong trinh cua minh 
		printf("this shouldn't print out\n");
	}else{
		//doi cho tien trinh con ket thuc
		int wc = wait(NULL);
		
		printf("parent of %d sc %d pid %d\n",sc, wc, (int)getpid());
	}
}
