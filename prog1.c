#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char *argv[], char ** envp){
	printf("Prog1.c desin\n");
	
	int pipefd[2];
	char temp[100];
	printf("cümleyi giriniz:");
	fgets(temp, 100, stdin);

	char *p = strchr(temp, '\n');
	if (p) *p = 0;

	char *dosyaIsmi;
	printf("Dosya Ismi:");
	scanf("%s",dosyaIsmi);		
	int fd=open(dosyaIsmi, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
	write(fd,temp,strlen(temp));
	close(fd);

	write(4, dosyaIsmi, 30);
	
	return(0);
}
