#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>

//定义新线程要执行的动作
void* Routine(void* arg)
{
  char* msg = (char*)arg;
  while(1)
  {
    printf("%s: pid:%d ppid:%d tid: %lu\n",msg,getpid(),getppid(),pthread_self());
    sleep(1);
  }
}

int main()
{
  pthread_t tid[5];
  //创建新线程，连续创建5个
  for(int i=0;i<5;i++)
  {
    char buffer[64]={0};
    sprintf(buffer, "thread%d",i);
    pthread_create(&tid[i], NULL, Routine, (void*)buffer);
    printf("%s tid is %lu\n", buffer, pthread_self());
  }

  //主线程
  while(1)
  {
    printf("I am main thread... pid: %d ppid: %d tid: %lu\n",getpid(),getppid(),pthread_self());
    sleep(2);
  }
  return 0;
}
