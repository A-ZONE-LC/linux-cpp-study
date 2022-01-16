#include"List.h"

ListNode* ListInit()//对带头双向循环链表进行初始化，建立头结点
{
  ListNode* guardHead = (ListNode*)malloc(sizeof(ListNode));
  if(guardHead == NULL)
  {
    printf("malloc fail\n");
    exit(-1);
  }
  guardHead->next = guardHead;
  guardHead->prev = guardHead;
  return guardHead;
}

ListNode* BuyListNode(Datatype x)//建立新结点
{
  ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
  if(newnode == NULL)
  {
    printf("malloc fail\n");
    exit(-1);
  }
  newnode->data = x;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

void ListPrint(ListNode* pHead)//打印链表
{
  assert(pHead);
  if(pHead->next == pHead)
  {
    printf("The List Is Empty!\n");
  }
  else 
  {
    ListNode* cur = pHead->next;
    while(cur != pHead)
    {
      printf("%d -> ",cur->data);
      cur = cur->next;
    }
    printf("\n");
  }
}

void ListInsert(ListNode* pos,Datatype x)//在pos位置之前插入x
{
  assert(pos);
  ListNode* prev = pos->prev;
  ListNode* newnode = BuyListNode(x);
  newnode->next = pos;
  pos->prev = newnode;
  newnode->prev = prev;
  prev->next = newnode;
}

void ListErase(ListNode* pos)//删除pos位置的结点
{
  assert(pos);
  ListNode* prev = pos->prev;
  ListNode* next = pos->next;
  prev->next = next;
  next->prev = prev;
  free(pos);
  pos = NULL;
}

void ListPushBack(ListNode* pHead,Datatype x)//尾插x
{
  assert(pHead);
  ListInsert(pHead,x);
}

void ListPopBack(ListNode* pHead)//尾删x
{
  assert(pHead);
  assert(pHead->next);
  ListErase(pHead->prev);
}

void ListPushFront(ListNode* pHead,Datatype x)//头插x
{
  assert(pHead);
  ListInsert(pHead->next,x);
}

void ListPopFront(ListNode* pHead)//头删
{
  assert(pHead);
  assert(pHead->next);
  ListErase(pHead->next);
}

ListNode* ListFind(ListNode* pHead,Datatype x)//查找x,返回x的地址
{
  assert(pHead);
  ListNode* cur = pHead->next;
  while(cur != pHead)
  {
    if(cur->data == x)
    {
      return cur;
    }
    else 
    {
      cur = cur->next;
    }
  }
  return NULL;
}

bool ListEmpty(ListNode* pHead)//检查链表是否为空
{
  assert(pHead);
  return pHead->next == pHead;
}

int ListSize(ListNode* pHead)//计算链表长度
{
  assert(pHead);
  ListNode* cur = pHead->next;
  size_t n = 0;
  while(cur != pHead)
  {
    ++n;
    cur = cur->next;
  }
  return n;
}
