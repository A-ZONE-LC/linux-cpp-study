#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void printPending(sigset_t* pending)
{
  int i = 1;
  for(; i <=31; i++)
  {
    if(sigismember(pending, i))
      printf("1");
    else 
      printf("0");
  }
  printf("\n");
}

void handler(int signo)
{
  printf("handler singo:%d\n",signo);
}

int main()
{
  signal(2, handler);


  sigset_t set,oset;//用户空间定义的变量
  sigemptyset(&set);
  sigemptyset(&oset);

  sigaddset(&set, 2);//给set添加SIGINT信号
  sigprocmask(SIG_SETMASK, &set, &oset);//阻塞了SIGINT信号

  sigset_t pending;
  int count = 0;
  while(1)
  {
    sigemptyset(&pending);//用户层清空
    sigpending(&pending);//系统填入信号集
    printPending(&pending);
    count++;

    sleep(1);
    if(count == 10)
    {
      sigprocmask(SIG_SETMASK, &oset, NULL);//恢复曾经的信号屏蔽字
      printf("恢复信号屏蔽字\n");
    }
  }

  return 0;
}
