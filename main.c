#include <sys/wait.h>
#include <random.h> 

int main(){
  pid_t p1 = fork();
  if(p1 == -1){
    perror("fork not working you idiot"); 
    exit(1);
  }
  return 0;
}
