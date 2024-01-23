#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 

int main(){
	printf("Thuc thi lenh shell: ");
	//ho lenh exec dung de thuc hien mot tien trinh moi bang cach thay the tien trinh hien tai dang chay duoc viet bang cac ngon ngu
	execl("/bin/ls","ls","-lt",".",NULL);
	//"." y la thuc thi o thu muc hien tai (co hay khong deu duoc)
	//thuong thi "." thay bang duong dan cua thu muc muon thuc thi 
	printf("\nDieu nay khong duoc hien thi");
}
