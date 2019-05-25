// C program to demonstrate use of fork() and pipe() 
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	int pfd[2];
	int pfd1[2];
	pid_t pid;
    char buff[50];
    char buff1[50];
    //char store[4][30] = {"Enkoklsh","mn awklh","Arat egir alew wenz mayshager","Alga"};
    char inp[50];
if (pipe(pfd) == -1) {
     perror("pipe"); 
     exit(EXIT_FAILURE); 
 }
if (pipe(pfd1) == -1) {
     perror("pipe"); 
     exit(EXIT_FAILURE); 
 }

  pid = fork();
 
	switch(pid){
		case -1:
		perror("fork");

		case 0:
		
            close(pfd[0]);
            close(pfd1[1]);
            for(int x=0;x<3;x++){
            for(int i=0;i<2;i++){
              printf("Parent:");
              scanf("%s",inp);
            write(pfd[1],inp,50);
           
            wait(NULL);
            read(pfd1[0],buff1,50);
            
            printf("%s \n",buff1);

            
            printf("\n");//}
            }}
		break;
		default:
		
		close(pfd[1]);
		close(pfd1[0]);
    for(int y=0;y<3;y++){
		for(int j=0;j<2;j++){
        read(pfd[0],buff,50);
       
        
        printf("%s \n",buff);
        printf("Child:");
        scanf("%s",inp);
        write(pfd1[1],inp,50);}}
        
     
		break;
	
	}
return 0;
}

