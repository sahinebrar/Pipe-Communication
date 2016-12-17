#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char *argv[], char ** envp){
	printf("Prog3.c desin\n");

	char dosya[30];
	read(3, dosya,30);
	
	printf("Okunan Dosya: %s\n", dosya);

	char newargv[100];
	int fd=open(dosya, O_RDONLY, 0644);
	int returnn = read(fd, newargv, strlen(dosya));
	printf("%s\n",newargv);
	close(fd);
	
	remove(dosya);
	
	return(0);
}
