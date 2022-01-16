#pragma once
#include<iostream>
#include<queue>
#include<pthread.h>
#define NUM 10
template<class T>
class BlockQueue
{
  public:
    bool IsFull()
    {
      return q.size() == capacity;
    }

    bool IsEmpty()
    {
      return q.empty();
    }

    BlockQueue(size_t _capacity = NUM)
      :capacity(_capacity)
    {
      pthread_mutex_init(&lock, nullptr);
      pthread_cond_init(&full, nullptr);
      pthread_cond_init(&empty, nullptr);
    }

    void Push(const T& input)
    {
      pthread_mutex_lock(&lock);
      while(IsFull())
      {
        pthread_cond_wait(&full, &lock);//如果队列满了就阻塞
      }
      q.push(input);
      pthread_mutex_unlock(&lock);
      if(q.size() >= capacity/2)
      {
        std::cout<<"数据过半等待消费"<<std::endl;
        pthread_cond_signal(&empty);
      }
    }
    void Pop(T& output)
    {
      pthread_mutex_lock(&lock);
      while(IsEmpty())
      {
        pthread_cond_wait(&empty, &lock);//如果队列为空就阻塞
      }
      output = q.front();
      q.pop();
      pthread_mutex_unlock(&lock);
      if(q.size() < capacity/4)
      {
        std::cout<<"数据不足等待生产"<<std::endl;
        pthread_cond_signal(&full);
      }
    }
    ~BlockQueue()
    {
      pthread_mutex_destroy(&lock);
      pthread_cond_destroy(&full);
      pthread_cond_destroy(&empty);
    }
  private:
    std::queue<T> q;
    size_t capacity;
    pthread_mutex_t lock;
    pthread_cond_t full;
    pthread_cond_t empty;
    
};
