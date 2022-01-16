#include"Seqlist.h"

void test1()
{
  Seqlist s;
  SeqInit(&s);
  SeqPushBack(&s,1);
  SeqPushBack(&s,2);
  SeqPushBack(&s,3);
  SeqPushBack(&s,4);
  SeqPushBack(&s,5);
  SeqPrint(&s);
  SeqPopBack(&s);
  SeqPrint(&s);
  SeqDestroy(&s);
}

void test2()
{
  Seqlist t;
  SeqInit(&t);
  SeqPushFront(&t,1);
  SeqPushFront(&t,2);
  SeqPushFront(&t,3);
  SeqPushFront(&t,4);
  SeqPrint(&t);
  SeqPopFront(&t);
  SeqPrint(&t);
  SeqDestroy(&t);
}

void test3()
{
  Seqlist k;
  SeqInit(&k);
  SeqPushBack(&k,1);
  SeqPushBack(&k,2);
  SeqPushBack(&k,3);
  SeqPushBack(&k,4);
  SeqPrint(&k);
  SeqInsert(&k,2,100);
  SeqPrint(&k);
  SeqDestroy(&k);
}  

void test4()
{
  Seqlist s;
  SeqInit(&s);
  SeqPushBack(&s,1);
  SeqPushBack(&s,2);
  SeqPushBack(&s,3);
  SeqPushBack(&s,4);
  SeqPushBack(&s,5);
  SeqPrint(&s);
  SeqErase(&s,2);
  SeqPrint(&s);
  SeqFind(&s,4);
  SeqFind(&s,100);
  SeqDestroy(&s);
}

void test5()
{
  Seqlist s;
  SeqInit(&s);
  SeqPushBack(&s,100);
  SeqPushBack(&s,200);
  SeqPushBack(&s,300);
  SeqPushBack(&s,400);
  SeqPushBack(&s,500);
  SeqPrint(&s);
  SeqModify(&s,3,985);
  SeqPrint(&s);
  SeqDestroy(&s);
}
int main()
{
  //test1();
  //test2();
  //test3();
  //test4();
  test5();
  return 0;
}
