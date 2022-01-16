#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<cstdlib>
#include<ctime>
#include"RingQueue.hpp"

void* Comsume(void* arg)
{
  RingQueue<int>* rq = (RingQueue<int>*)arg;
  while(1)
  {
    sleep(3);
    int data = 0;
    rq->Pop(data);
    std::cout<<"comsume..."<<data<<std::endl;
  }
  pthread_exit((void*)0);
}

void* Product(void* arg)
{
  RingQueue<int>* rq = (RingQueue<int>*)arg;
  while(1)
  {
    sleep(1);
    int data = rand()%131 + 1;
    rq->Push(data);
    std::cout<<"product..."<<data<<std::endl;
  }
  pthread_exit((void*)0);
}

int main()
{
  srand((unsigned long)time(nullptr));
  RingQueue<int>* rq = new RingQueue<int>();
  pthread_t c1,c2,c3;
  pthread_t p1,p2,p3;
  pthread_create(&c1, nullptr, Comsume, rq);
  pthread_create(&c2, nullptr, Comsume, rq);
  pthread_create(&c3, nullptr, Comsume, rq);
  pthread_create(&p1, nullptr, Product, rq);
  pthread_create(&p2, nullptr, Product, rq);
  pthread_create(&p3, nullptr, Product, rq);

  pthread_join(c1, nullptr);
  pthread_join(c2, nullptr);
  pthread_join(c3, nullptr);
  pthread_join(p1, nullptr);
  pthread_join(p2, nullptr);
  pthread_join(p3, nullptr);
  return 0;
}
