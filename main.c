#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("%d about to create 2 child processes.\n", getpid());

  pid_t p1 = -1;
  pid_t p2 = -1;
  p1 = fork();
  if (p1 < 0) {
    perror("Fork 1 failed.");
    exit(1);
  }
  else if (p1 == 0) {
    p2 = fork();
    if (p2 < 0) {
      perror("Fork 2 failed.");
      exit(1);
    }
  }
  if (p2 < 0) {
    exit(1);
  }

  int time = 3;
  if(p1 == 0 || p2 == 0) {
    time = 3; // open urandom and pull file
    sleep(time);
    printf("%d finished after %d seconds.\n", getpid(), time);
    exit(time);
  }
  else {
    int status = 0;
    int pid = wait(&status);
    time = WEXITSTATUS(status);
    printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), pid, time);
  }
  return 0;
}
