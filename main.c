#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  printf("%d about to create 2 child processes.\n", getpid());

  pid_t p1;
  pid_t p2;
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
    srand(getpid());
    int time = rand() % 5 + 1;
    printf("%d %dsec\n", getpid(), time);
    sleep(time);
    printf("%d finished after %d seconds\n", getpid(), time);
    exit(time);
  }
  else {
    
  }
  return 0;
}
