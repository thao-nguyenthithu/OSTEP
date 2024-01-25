#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	// khoi tao bien luu ten file
	char filename[100];
	
	//ham pipe dung de tien trinh con doc du lieu tu doi so truyen va ghi vao pp
	// tien trinh cha doc tu pp va xuat ra.
	int fp[2];
	
	if(pipe(fp)==0) {
		//Khoi tao chuong trinh con 
		int pid = fork();
		
		if(pid < 0){
			printf("fork failed\n");
			return -1;
		}
		if(pid == 0){
			printf("Child\n");
			printf("Nhap vao ten file khoi tao: ");
			fflush(stdin);
			gets(filename);
			
			// dong dau doc cua ong trong tt con
			close(fp[0]);
			//ghi ten file vao ong de chuyen cho tien trinh cha
			write(fp[1],filename,strlen(filename));
			close(fp[1]); // dong dau ghi 
			
			execlp("vim","vim", filename, NULL);
			
			printf("vim loi!\n");
				
		}else{
			// doi tien trinh con ket thuc 
			wait(NULL);
			
			//doc file tu ong
			read(fp[0],filename,sizeof(filename));
			
			printf("Cha\n");
			execlp("cat","cat",filename,NULL);
			
			printf("cat loi\n");
			
			
		}
	}
}
