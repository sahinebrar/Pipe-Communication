#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
int main(int argc, char *argv[], char ** envp){
	printf("Prog2.c desin\n");
	char dosya[30];
	read(3, dosya,30);
	printf("Dosya: %s\n", dosya);

	int fd=open(dosya, O_RDWR, 0644);
	
	char temp[1];
	printf("karakteri giriniz:");
	gets(temp);
	char *p = strchr(temp, '\n');
	if (p) *p = 0;			
	printf("temp: %s\n",temp);	
	const char *bosluk=" ";
	char newargv[32];
	char okunan[1];

	int w=read(fd, okunan, 1);
	int byte=0;
	while(w> 0){
		if(okunan[0]==' '){
			lseek(fd,byte,SEEK_SET);
			write(fd, temp, 1);			
		}
		byte++;
		w= read(fd, okunan, 1);
	}

	char* name_with_extension=malloc(30);
	strcpy(name_with_extension, dosya);
	strcat(name_with_extension, "_");
	strcat(name_with_extension, temp);
	strcat(name_with_extension, ".txt");
	close(fd);
	rename(dosya, name_with_extension);	

	
	write(4, name_with_extension, 30);
	return(0);
}
