#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<unistd.h>
#include<ctime>
#include"BlockQueue.hpp"
#include"task.hpp"

void* Comsume(void* arg)
{
  auto bq = (BlockQueue<Task>*)arg;
  while(1)
  {
    sleep(1);
    Task t;
    bq->Pop(t);//消费数据
    t.Run();
    std::cout<<"comsume finish..."<<std::endl;
  }
}

void* Product(void* arg)
{
  auto bq = (BlockQueue<Task>*)arg;
  while(1)
  {
    sleep(2);
    char operate[] = {'+','-','*','/'};
    int x = rand()%128+33;
    int y = rand()%7+17;
    char op = operate[rand()%4];
    Task t(x, op, y);
    bq->Push(t);//生产数据
    std::cout<<"product finish..."<<std::endl;
  }
}

int main()
{
  srand((unsigned long)time(nullptr));
  BlockQueue<Task>* bq = new BlockQueue<Task>();
  pthread_t coms, prod;
  pthread_create(&coms, nullptr, Comsume, bq);
  pthread_create(&prod, nullptr, Product, bq);


  pthread_join(coms, nullptr);
  pthread_join(prod, nullptr);
  return 0;
}
