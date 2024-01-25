#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<sys/wait.h>

int main(){
	//tao tien trinh con
	int pid = fork();

	if(pid < 0){
		printf("fork failed!\n");
		exit(-1);
	}
	if(pid == 0){
		printf("child!\n");
		
		//Ho lenh exec de thuc thi lenh ps -a
		execlp("ps","ps","-a",NULL);

		printf("\nps -a that bai!\n");
		exit(0);

	}else{
		//Doi tien trinh con ket thuc
		wait(NULL);
		printf("Cha\n");

		printf("Nhap PID cua tien trinh can ket thuc: ");
		//char pid_tokill[100];
		//fflush(stdin);
		//gets(pid_tokill);
		
		int pid_tokill;
		scanf("%d",&pid_tokill);
		// Chuyển đổi PID thành chuỗi sử dụng sprintf
        	char pid_str[20];
        	sprintf(pid_str, "%d", pid_tokill);

		//Goi lenh kill -9
		execlp("kill","kill","-9",pid_str, NULL);
		
		//Neu ham execlp that bai thi in ra thong bao sau 
		printf("\nkill -9 that bai!\n");
		exit(0);

	}
}
