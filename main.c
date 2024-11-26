#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h> 

int randomNumber();

int main(){
  printf("\e[36m%d\e[0m about to create 2 child processes\n", getpid());

  pid_t p1 = fork();
  if(p1 == -1){
    perror("fork not working you idiot"); 
    exit(1);
  }

  pid_t p2 = -1;
  if(p1 != 0){
    p2 = fork();
    if(p2 == -1){
      perror("fork not working you idiot");
      exit(1);
    }
  }

  pid_t p3 = -1;
  if(p1 != 0 && p2 != 0){
    p3 = fork();
    if(p3 == -1){
      perror("fork not working you dummy");
      exit(1);
    }
  }

  if(p2 == 0){
    printf("\e[36m%d\e[0m finished after sec\n", getpid());
  }
  if(p3 == 0){
    printf("\e[36m%d\e[0m finished after sec\n", getpid());
  }

  //int rand = randomNumber();
  return 0;
}

int randomNumber(){
  srand(time(NULL));
  int r = rand() % 5; //this might have to be ceiling, check this later 
  // also we might not be able to use this cause like it's not resetting every time soooo
  return r;
}
