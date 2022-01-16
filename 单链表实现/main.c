#include"Slist.h"

void test1()
{
  SLList* phead = NULL;
  SLLPushBack(&phead,1);
  SLLPushBack(&phead,2);
  SLLPushBack(&phead,3);
  SLLPushBack(&phead,4);
  SLLPushBack(&phead,5);
  SLLPushBack(&phead,6);

  PrintList(phead);

  SLLPushFront(&phead,100);
  SLLPushFront(&phead,200);

  PrintList(phead);

  SLLPopFront(&phead);

  PrintList(phead);

  SLLPopFront(&phead);
   
  PrintList(phead);
  DestroyList(&phead);
}
void test2()
{
  SLList* phead = NULL;
  SLLPushFront(&phead,100);
  SLLPushFront(&phead,200);
  SLLPushFront(&phead,300);
  SLLPushFront(&phead,400);
  PrintList(phead);

  SLLPopFront(&phead);
  SLLPopFront(&phead);
  SLLPopFront(&phead);
  PrintList(phead);
  DestroyList(&phead);
}
void test3()
{
  SLList* phead = NULL;
  SLLPushBack(&phead,1);
  SLLPushBack(&phead,2);
  SLLPushBack(&phead,3);
  SLLPushBack(&phead,4);
  SLLPushBack(&phead,5);
  SLLPushBack(&phead,6);
  PrintList(phead);
  SLLModify(SLLFind(phead,3),100);
  PrintList(phead);
  SLLModify(SLLFind(phead,1),888);
  PrintList(phead);
  DestroyList(&phead);
}
void test4()
{
  SLList* phead = NULL;
  SLLPushBack(&phead,1);
  SLLPushBack(&phead,2);
  SLLPushBack(&phead,3);
  SLLPushBack(&phead,4);
  SLLPushBack(&phead,5);
  SLLPushBack(&phead,6);
  SLLPushBack(&phead,7);
  SLLPushBack(&phead,8);
  SLLPushBack(&phead,9);
  PrintList(phead);
  EraseCurrent(&phead,SLLNumFind(phead,1));
  PrintList(phead);
  DestroyList(&phead);

}
int main()
{
  //test1();
  //test2();
  //test3();
  test4();

  return 0;
}
