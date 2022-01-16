#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>
#include<ctime>
#include"BlockQueue.hpp"

void* Comsume(void* arg)
{
  auto bq = (BlockQueue<int>*)arg;
  while(1)
  {
    sleep(1);
    int data = 0;
    bq->Pop(data);//消费数据
    std::cout<<"comsume finish..."<<data<<std::endl;
  }
}

void* Product(void* arg)
{
  auto bq = (BlockQueue<int>*)arg;
  while(1)
  {
    sleep(2);
    int data = rand()% 100 +1;
    bq->Push(data);//生产数据
    std::cout<<"product finish..."<<data<<std::endl;
  }
}

int main()
{
  srand((unsigned long)time(nullptr));
  BlockQueue<int>* bq = new BlockQueue<int>();
  pthread_t coms, prod;
  pthread_create(&coms, nullptr, Comsume, bq);
  pthread_create(&prod, nullptr, Product, bq);


  pthread_join(coms, nullptr);
  pthread_join(prod, nullptr);
  return 0;
}
