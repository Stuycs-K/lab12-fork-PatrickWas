#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int randomNumber();

int main(){
  printf("\e[36m%d\e[0m about to create 2 child processes\n", getpid());

  pid_t parentId = getpid();

  pid_t p1 = fork();
  if(p1 == -1){perror("fork not working you idiot\n"); exit(1);}
  if(p1 == 0){
    int r1 = randomNumber();
    printf("\e[36m%d\e[0m %dsec\n", getpid(), r1);
    sleep(r1);
    printf("\e[36m%d\e[0m finished after %dsec\n", getpid(), r1);
    exit(r1);
  }

  pid_t p2 = fork();
  if(p2 == -1){perror("fork not working you dummy\n"); exit(1);}
  if(p2 == 0){
    int r2 = randomNumber();
    printf("\e[36m%d\e[0m %dsec\n", getpid(), r2);
    sleep(r2);
    printf("\e[36m%d\e[0m finished after %dsec\n", getpid(), r2);
    exit(r2);
  }

  int status;
  pid_t exitStatus = wait(&status);
  if(WIFEXITED(status)){
    printf("Main process \e[36m%d\e[0m is done. Child \e[36m%d\e[0m slept for %dsec\n", parentId, exitStatus, WEXITSTATUS(status) );
  }
  return 0;
}

int randomNumber(){
  int r_file;
  int x;

  r_file = open("/dev/random", O_RDONLY, 0);
  if(r_file==-1){perror("random number not working"); exit(1);}

  int bytesRead = read(r_file, &x, sizeof(int));
  if(bytesRead==-1){perror("random number not working"); exit(1);}

  return abs(x) % 5 + 1;
}
