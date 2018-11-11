#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int fd = open("error.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
    write(fd,"Program exited due to SIGINT", 30);
    close(fd);
    exit(0);
  }

  if (signo == SIGUSR1)
    printf("The parent PID is: %d\n", getppid());
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("PID is: %d", getpid());
    sleep(1);
  }

  return 0;

}
