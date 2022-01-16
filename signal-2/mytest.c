#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler(int signo)
{
  printf("Get a signal: %d\n",signo);
}

int main()
{
  signal(6, handler);
  while(1)
  {
    printf("I am a process... pid: %d\n",getpid());
    //raise(2);
    sleep(1);
    abort();
  }
  return 0;
}
