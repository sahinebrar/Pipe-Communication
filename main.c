#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char *argv[], char ** envp){
	int pipefd[2];
	int pipes=pipe(pipefd);
	if(pipes< 0){
		perror("pipe hata");
		exit(1);
	}
	int i;
	int f;
	f= fork();
                if(f==0){
                        i= execve("prog1",argv,envp);
			close(pipefd[1]);
                }
		else{
			wait(&i);
		}
	f= fork();
		int j;
		
		if(f== 0){
			j=execve("prog2", argv,envp);
			close(pipefd[1]);
		}
		else{
			wait(&j);
		}
	f= fork();
		int z;

		if(f== 0){
			z=execve("prog3", argv,envp);
			close(pipefd[1]);
		}
		else{
			wait(&z);
		}
	
	return (0);
}
 

