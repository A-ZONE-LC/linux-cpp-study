#include<iostream>
#include<pthread.h>
#include<cstdio>
using namespace std;

pthread_mutex_t lock;
pthread_cond_t cond;

void* Routine(void* arg)
{
  pthread_detach(pthread_self());//线程分离
  cout<<(char*)arg<<" run..."<<endl;
  while(1)
  {
    pthread_cond_wait(&cond, &lock);//阻塞，等待被唤醒,注意用法（左条件右锁）
    cout<<(char*)arg<<" wake up..."<<endl;
  }
}


int main()
{
  pthread_mutex_init(&lock, NULL);
  pthread_cond_init(&cond, NULL);

  pthread_t t1,t2,t3;
  pthread_create(&t1, NULL, Routine, (void*)"thread1");
  pthread_create(&t2, NULL, Routine, (void*)"thread2");
  pthread_create(&t3, NULL, Routine, (void*)"thread3");

  while(1)
  {
    getchar();//每键入一个值就会唤醒一次
    //pthread_cond_signal(&cond);
    pthread_cond_broadcast(&cond);
  }

  pthread_mutex_destroy(&lock);
  pthread_cond_destroy(&cond);
  return 0;
}
