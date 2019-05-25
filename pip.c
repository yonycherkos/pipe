#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pid;
	int mypipefd[2];
	int ret;
	char buf[20];
	ret = pipe(mypipefd);
	if(ret==-1){
		perror("pipe");
		exit(1);
	}
	pid = fork();

    if(pid==0){
    	/*chiled process*/
    	printf("child process \n");
       write(mypipefd[1],"Hello there!",12);
    }
    else{
    	/*parent process*/
    	printf("parent process \n");
      read(mypipefd[0],buf,15);
      printf("buf: %s\n", buf);
    }
	return 0;
}