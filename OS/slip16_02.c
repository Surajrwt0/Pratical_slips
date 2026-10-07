/*Q.1 Write a C program to illustrate the concept of orphan process. Parent process creates
a child and terminates before child has finished its task. So child process becomes
orphan process. (Use fork(), sleep(), getpid(), getppid*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
      int pid = fork();
      if(pid<0){
            printf("process failed\n");
      }
      else if(pid==0){
            printf("child process started\n");
            printf("child process id : %d",getpid());
            printf("parent process id : %d",getppid());
            sleep(5);
            printf("After parent terminated\n");
            printf("child process id : %d",getpid());
            printf("parent process id : %d",getppid());
      }
      else{
            printf("Parent process started \n");
            printf("parent process id: %d ",getpid());
            sleep(2);
            printf("parent process terminated");
            exit(0);
      }
      return 0;
}