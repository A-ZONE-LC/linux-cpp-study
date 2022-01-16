#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

struct sigaction act,oact;

void handler(int signum)
{
  //这里也可以调switch,针对多个信号进行捕捉
  printf("Recieve a signal: %d\n",signum);
  sigaction(SIGINT, &oact, NULL);//恢复原来的信号处理方法
}

int main()
{
  memset(&act, 0, sizeof(act));//将结构体清空
  memset(&oact, 0, sizeof(oact));
  act.sa_handler = handler;//设置自定义方法，给函数指针
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);//这里不需要

  sigaction(SIGINT, &act, &oact);//进行捕捉
  while(1)
  {
    printf("I am a process...\n");
    sleep(1);
  }
  return 0;
}
