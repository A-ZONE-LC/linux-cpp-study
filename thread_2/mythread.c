#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>

void* Routine(void* arg)
{
  char* msg = (char*)arg;
  int count = 5;
  while(count--)
  {
    printf("%s pid:%d ppid:%d tid:%lu\n",msg,getpid(),getppid(),pthread_self());
    sleep(1);
    // pthread_cancel(pthread_self());  方案三
  }
  // return (void*)11;  方案一
  pthread_exit((void*)11); // 方案二
}

int main()
{
  pthread_t tid[5];
  for(int i=0;i<5;i++)
  {
    char* buffer = (char*)malloc(64);
    sprintf(buffer, "thread%d",i);
    pthread_create(&tid[i], NULL, Routine, buffer);
    printf("create thread%d pid:%d ppid:%d tid:%lu\n",i,getpid(),getpid(),tid[i]);
  }

  printf("main thread pid:%d ppid:%d tid:%lu\n",getpid(),getppid(),pthread_self());
  for(int i = 0;i < 5 ;i++)
  {
    void* ret = NULL;
    pthread_join(tid[i], &ret);
    printf("thread%d tid:%lu exited  exit code:%d\n",i,tid[i],(int)ret);
  }
  return 0;
}
