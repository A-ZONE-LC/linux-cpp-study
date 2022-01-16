#include"List.h"

void test1()
{
  ListNode* pHead = ListInit();
  ListPushBack(pHead,1);
  ListPushBack(pHead,2);
  ListPushBack(pHead,3);
  ListPushBack(pHead,4);
  ListPushBack(pHead,5);
  ListPrint(pHead);
}

void test2()
{
  ListNode* pHead = ListInit();
  ListPushFront(pHead,1);
  ListPushFront(pHead,2);
  ListPushFront(pHead,3);
  ListPushFront(pHead,4);
  ListPushFront(pHead,5);
  ListPrint(pHead);
}

void test3()
{
  ListNode* pHead = ListInit();
  ListPushBack(pHead,1);
  ListPushBack(pHead,2);
  ListPushBack(pHead,3);
  ListPrint(pHead);
  ListPopBack(pHead);
  ListPrint(pHead);
  ListPopBack(pHead);
  ListPrint(pHead);
  ListPopBack(pHead);
  ListPrint(pHead);
}

void test4()
{
  ListNode* pHead = ListInit();
  ListPushBack(pHead,1);
  ListPushBack(pHead,2);
  ListPushBack(pHead,3);
  ListPushBack(pHead,4);
  ListPushBack(pHead,5);
  ListPrint(pHead);
  ListPopFront(pHead);
  ListPrint(pHead);
  ListPopFront(pHead);
  ListPrint(pHead);
  ListPopFront(pHead);
  ListPrint(pHead);
  ListPopFront(pHead);
  ListPrint(pHead);
  ListPopFront(pHead);
  ListPrint(pHead);
}

void test5()
{
  ListNode* pHead = ListInit();
  ListPushBack(pHead,10);
  ListPushBack(pHead,20);
  ListPushBack(pHead,30);
  ListPushBack(pHead,40);
  ListPushBack(pHead,50);
  ListPrint(pHead);
  printf("Empty:%d\n",ListEmpty(pHead));
  printf("Size:%d\n",ListSize(pHead));
  ListInsert(ListFind(pHead,30),88);
  ListPrint(pHead);
}
int main()
{
  //test2();
  //test3();
  //test4();
  test5();
  return 0;
}
