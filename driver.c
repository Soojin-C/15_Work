#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <time.h>


int main(){

  int status;
  wait(status);
  
  fork();
  

}
