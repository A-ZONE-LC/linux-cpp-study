#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

volatile int flag = 0;

void handler(int signum)
{
  printf("receive a signal: %d\n",signum);
  flag = 1;//捕捉到信号之后将flag改为1，使得循环退出
}

int main()
{
  signal(2, handler);
  while(!flag);//死循环
  printf("process normal quit\n");
  return 0;
}
