#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int ticket = 2000;

void* Routine(void* arg)
{
  const char* name = (char*)arg;
  while(1)
  {
    if(ticket > 0)
    {
      usleep(100);
      printf("[%s] get a tickect:%d\n",name,ticket--);
    }
    else 
    {
      break;
    }
  }
  printf("%s quit...\n",name);
  pthread_exit((void*)11);
}

int main()
{
  pthread_t t1, t2, t3, t4;

  pthread_create(&t1, NULL, Routine, (void*)"thread1");
  pthread_create(&t2, NULL, Routine, (void*)"thread2");
  pthread_create(&t3, NULL, Routine, (void*)"thread3");
  pthread_create(&t4, NULL, Routine, (void*)"thread4");

  void* ret1, *ret2, *ret3, *ret4;
  pthread_join(t1, &ret1);
  pthread_join(t2, &ret2);
  pthread_join(t3, &ret3);
  pthread_join(t4, &ret4);
  return 0;
}
