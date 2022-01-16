#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void handler(int signo)
{
  printf("got a signal! signo: %d\n",signo);
  signal(signo, handler);
}

int main()
{
  for(int signo = 1;signo < 32;signo++)
  {
    signal(signo, handler);
  }
  while(1)
  {
    sleep(1);
  }
  return 0;
}

  //pid_t id = fork();
  //if(id == 0)
  //{
  //  //child
  //  int i;
  //  i = 1/0;
  //  exit(0);
  //}
  //int status = 0;
  //waitpid(id, &status, 0);
  //printf("exit code: %d  core dump: %d  signal code: %d\n",\
  //    (status>>8)&0xff,(status>>7)&1,status&0x7f);
  //return 0;
  //}
