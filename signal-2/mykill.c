#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>

void Usage(const char* msg)
{
  printf("Usage: %s  pid  signo\n",msg);
}

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    Usage(argv[0]);
    return 1;
  }

  //从命令行参数中得到pid和信号编号
  pid_t pid = atoi(argv[1]);
  int signo = atoi(argv[2]);

  //使用系统调用向进程pid发送信号
  kill(pid, signo);
  return 0;
}
