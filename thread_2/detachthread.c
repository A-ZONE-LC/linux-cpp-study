#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

void* Routine(void* arg)
{
  pthread_detach(pthread_self());//将自身分离
  char* msg = (char*)arg;
  int count = 5;
  while(count--)
  {
    printf("%s:pid:%d ppid:%d tid:%lu\n", msg, getpid(), getppid(), pthread_self());
    sleep(1);
  }
  pthread_exit((void*)11);
}

int main()
{
  pthread_t tid[5];
  for(int i=0; i<5; i++)
  {
    char* buffer = (char*)malloc(64);
    sprintf(buffer, "thread%d", i);
    pthread_create(&tid[i], NULL, Routine, (void*)buffer);
    printf("thread%d create\n", i);
  }

  int count = 3;
  while(count--)
  
  {
    sleep(1);
  };
  return 0;
}
