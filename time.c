#ifdef CS333_P2
#include "types.h"
#include "user.h"

#define SPM (60)
#define SPH (60  * SPM)
#define pad(x,y) if ((x)<10) printf(1,"0"); printf(1, "%d%s", (x), (y));

void
padms(int ms)
{
    if(ms < 10)  printf(1,"00");
    if(ms < 100) printf(1,"0");
}

int 
main (int argc, char* argv[])
{
  int start_time;
  int pid;
 
  start_time = uptime();
  pid = fork();

  if(pid < 0) {
    printf(2, "Fork failed.\n");
    exit();
    // child process
  } else if (pid == 0) {
    if(argc < 2) {
      exit();
    } else {
      exec(argv[1], &argv[1]);
      exit();
    }
    // parent process
  } else {
    wait();
    printf(1, "%s ran in ", argv[1]);

    int runtime = uptime() - start_time;
    int ms = runtime % 1000;
    runtime = runtime/1000;
    
    //pad(runtime, ".");
    padms(ms);
    printf(1, "%d.%d seconds.\n",runtime, ms);
   

  }
  exit();
}

#endif // CS333_P2
