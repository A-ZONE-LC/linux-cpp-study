#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

int ticket = 10000;
pthread_mutex_t lock;

void* Routine(void* arg)
{
  int num = (int)arg;
  while(1)
  {
    pthread_mutex_lock(&lock);
    if(ticket > 0)
    {
      usleep(100);
      printf("thread%d GetTicket[%d]\n", num, ticket--);
      pthread_mutex_unlock(&lock);
      usleep(100);
    }
    else
    {
      pthread_mutex_unlock(&lock);
      break;
    }
  }
  pthread_exit((void*)11);
}

int main()
{
  pthread_t thread[5];
  pthread_mutex_init(&lock, NULL);
  for(int i=0; i<5; i++)
  {
    pthread_create(&thread[i], NULL, Routine, (void*)i);
  }

  for(int i=0; i<5; i++)
  {
    pthread_join(thread[i], NULL);
  }
  pthread_mutex_destroy(&lock);
  return 0;
}
