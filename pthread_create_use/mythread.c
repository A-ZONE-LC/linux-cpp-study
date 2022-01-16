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
    printf("%s: pid:%d ppid:%d\n",msg,getpid(),getppid());
    sleep(1);
  }
}

int main()
{
  pthread_t tid;
  //创建新线程
  pthread_create(&tid, NULL, Routine, (void*)"thread 1");
 
  //主线程
  while(1)
  {
    printf("I am main thread... pid: %d ppid: %d\n",getpid(),getppid());
    sleep(2);
  }
  return 0;
}
