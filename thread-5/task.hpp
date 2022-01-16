#pragma once 
#include<iostream>

class Task 
{
  public:
    Task(int x=1,char op='+',int y=1)
      :_x(x)
      ,_op(op)
      ,_y(y)
  {}

    void Run()
    {
      int ret;
      switch(_op)
      {
        case '+':
          ret = _x+_y;
          break;
        case '-':
          ret = _x-_y;
          break;
        case '*':
          ret = _x*_y;
          break;
        case '/':
          if(_y ==0)
          {
            std::cout<<"error:div zero"<<std::endl;
            ret = -1;
            break;
          }
          ret = _x/_y;
          break;
        default:
          ret = -1;
          std::cout<<"no matching char"<<std::endl;
          break;
      }
      std::cout<<_x<<_op<<_y<<"="<<ret<<std::endl;
    }

  private:
    int _x;
    char _op;
    int _y;
};
