#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int count = 0;
void handler(int signo)
{
  printf("signal: %d\ncount: %d\n",signo,count);
  alarm(1);
}

int main()
{
  signal(SIGALRM, handler);
  alarm(1);

  while(1)
  {
    count++;
  }
  return 0;
}
