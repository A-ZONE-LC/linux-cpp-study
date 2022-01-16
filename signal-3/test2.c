#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
  signal(SIGCHLD, SIG_IGN);//信号处理方式为忽略可以自动回收
  if(fork() == 0)
  {
    //child
    printf("child:%d parent:%d\n",getpid(),getppid());
    sleep(3);
    exit(0);
  }
  while(1);
  return 0;
}
