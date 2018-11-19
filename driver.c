#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/wait.h>

#include <fcntl.h>

int randomInt(){

  int fd = open( "/dev/random", O_RDONLY );
  int * pointer = malloc(sizeof(int));
  read(fd, pointer, sizeof(int));

  //printf("%d\n", *pointer);
  close(fd);
  if (*pointer < 0){
    *pointer = randomInt();
  }
  return *pointer;

}

int main(){

  int status;

  pid_t child = fork();
  pid_t child0 = 0;

  if (child){

    printf("Before forking ...\n");
    child0 = fork();

  }

  if (child0){

    int child_pid = wait(&status);
    int child_time = WEXITSTATUS(status);
    printf("Child %d slept for %d seconds\n", child_pid, child_time);

  }

  if (child0 == 0 || child == 0){

    int sleeptime = (randomInt() % 15) + 5;
    printf("My PID: %d\nSleeping for ... %d\n", getpid(), sleeptime);
    sleep(sleeptime);
    printf("Done Sleeping\n");
    return sleeptime;

  }


  return 0;


}
