#include<iostream>
#include<vector>
#include<semaphore.h>
#define NUM 32

template<class T>
class RingQueue
{
  private:
    void P(sem_t& sem)//P操作
    {
      sem_wait(&sem);
    }

    void V(sem_t& sem)//V操作
    {
      sem_post(&sem);
    }

  public:
    RingQueue(int cap = NUM)
      :_cap(cap)
      ,comsume_pos(0)
      ,product_pos(0)
  {
    q.resize(_cap);
    sem_init(&blank_sem, 0, _cap);
    sem_init(&data_sem, 0, 0);
  }

    ~RingQueue()
    {
      sem_destroy(&blank_sem);
      sem_destroy(&data_sem);
    }

    void Push(const T& input)
    {
      P(blank_sem);
      q[product_pos] = input;
      V(data_sem);
      ++product_pos;
      product_pos %= _cap;//模拟环形队列
    }

    void Pop(T& output)
    {
      P(data_sem);
      output = q[comsume_pos];
      V(blank_sem);
      ++comsume_pos;
      comsume_pos %= _cap;//模拟环形队列
    }
  private:
    std::vector<T> q;
    int _cap;
    sem_t blank_sem;
    sem_t data_sem;
    int comsume_pos;
    int product_pos;
};
