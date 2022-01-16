#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<cstdlib>

class Sem
{
  public:
    Sem(int num=1)
    {
      sem_init(&sem, 0,num);
    }

    ~Sem()
    {
      sem_destroy(&sem);
    }

    void P()
    {
      sem_wait(&sem);
    }

    void V()
    {
      sem_post(&sem);
    }
  private:
    sem_t sem;
};

Sem sem(1);
int ticket = 2000;

void* Getticket(void* arg)
{
  sem.P();
  while(1)
  {
    usleep(500);
    if(ticket > 0)
    {
      std::cout<<(char*)arg<<" getticket"<<ticket--<<std::endl;
      sem.V();
    }
    else{
      sem.V();
      std::cout<<(char*)arg<<"exit"<<std::endl;
      break;
    }
  }
  pthread_exit((void*)0);
}

int main()
{
  pthread_t t1, t2, t3, t4, t5, t6;
  pthread_create(&t1, nullptr, Getticket, (void*)"thread1");
  pthread_create(&t2, nullptr, Getticket, (void*)"thread2");
  pthread_create(&t3, nullptr, Getticket, (void*)"thread3");
  pthread_create(&t4, nullptr, Getticket, (void*)"thread4");
  pthread_create(&t5, nullptr, Getticket, (void*)"thread5");
  pthread_create(&t6, nullptr, Getticket, (void*)"thread6");


  pthread_join(t1, nullptr);
  pthread_join(t2, nullptr);
  pthread_join(t3, nullptr);
  pthread_join(t4, nullptr);
  pthread_join(t5, nullptr);
  pthread_join(t6, nullptr);
  return 0;
}
