#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>

void* Routine(void* arg)
{
  int count = 5;
  while(count--)
  {
    printf("thread tid:%p\n",pthread_self());
    sleep(1);
  }
}

int main()
{
  pthread_t tid;
  pthread_create(&tid, NULL, Routine, NULL);

  while(1)
  {
    printf("main tid:%p\n",pthread_self());
    sleep(1);
  }
  void* ret = NULL;
  pthread_join(tid, &ret);
  return 0;
}
