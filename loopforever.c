#include "types.h"
#include "user.h"
#include "pdx.h"

int
main(int argc, char *argv[])
{
  int pid, max;
  unsigned long x = 0;

  if (argc == 1) {
    printf(2, "Enter number of processes to create\n");
    exit();
  }

  max = atoi(argv[1]);


  for (int i=0; i<max; i++) {
    sleep(5*TPS);  // pause before each child starts
    pid = fork();
    if (pid < 0) {
      printf(2, "fork failed!\n");
      exit();
    }

    if (pid == 0) { // child
      sleep(getpid()*TPS); // stagger start
      do {
        x += 1;
      } while (1);
      printf(1, "Child %d exiting\n", getpid());
      exit();
    }
  }

  pid = fork();
  if (pid == 0) {
    sleep(20);
    do {
      x = x+1;
    } while (1);
  }

  sleep(15*TPS);
  wait();
  printf(1, "Parent exiting\n");
  exit();
}
