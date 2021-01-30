#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"
#define MAX 72

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
main(int argc, char * argv[])
{
//  int MAX = atoi(argv[1]);
  struct uproc *proc = malloc(sizeof(struct uproc)*MAX);
  int x = getprocs(MAX,proc);

  int i; 
  printf(1,"PID\tName\t     UID\tGID\tPPID\tElapsed\tCPU\tState\tSize\n");
  for(i = 0; i<x;i++){
    int elapsed_ms = (proc[i].elapsed_ticks)%1000;
    //int elapsed_s  = proc[i].elapsed_ticks/1000;
    

    //int cpu_t_s = proc[i].CPU_total_ticks/1000;
    int cpu_t_ms = (proc[i].CPU_total_ticks)%1000;

    printf(1,"%d\t%s\t     %d     \t%d\t%d\t%d.", 
        proc[i].pid,
        proc[i].name,
        proc[i].uid,
        proc[i].gid,
        proc[i].ppid,
        proc[i].elapsed_ticks/1000);

        
        padms(proc[i].elapsed_ticks%1000);

        printf(1,"%d\t%d.",
        elapsed_ms,
        proc[i].CPU_total_ticks/1000);
        
        padms(proc[i].CPU_total_ticks%1000);

    printf(1,"%d\t%s\t%d\n",
        cpu_t_ms,
        proc[i].state, 
        proc[i].size);
  }
  free(proc);
//  printf(1,"\n");

//  printf(1,"Max processes: %d, but %d processes returned\n", MAX, x);
  exit();
}
#endif //CS333_P2
