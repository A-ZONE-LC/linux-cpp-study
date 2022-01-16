#include"Slist.h"


SLList* BuyNewNode(Datatype x)//建立新节点
{
  SLList* newnode = (SLList*)malloc(sizeof(SLList));
  newnode->data = x;// 赋值
  newnode->next = NULL;
  
  return newnode;//返回结点地址
}


void PrintList(SLList* phead)//打印该单链表
{
  if(phead==NULL)
  {
    printf("单链表为空\n");
  }
  else
  {
    SLList* cur = phead;
    while(cur != NULL)
    {
      printf("%d ->",cur->data);
      cur = cur->next;
    }
    printf("NULL\n");
  }
}


void SLLPushBack(SLList** pphead,Datatype x )//尾插
{
  SLList* newnode = BuyNewNode(x);
  //没有结点的情况
  if(*pphead == NULL)
  {
   *pphead = newnode;
  }
  //有节点的情况
  else
  {
    SLList* tail = *pphead;
    while(tail->next != NULL)//找尾
    {
      tail = tail->next;
    }
    tail->next = newnode;//在尾后插入结点
  }
}


void DestroyList(SLList** pphead)
{
  if(*pphead == NULL)//链表为空
  {
    return;
  }
  else
  {
    SLList* next = NULL;
    while((*pphead)!=NULL)//依次销毁各个结点
    {
      next = (*pphead)->next;
      free(*pphead);
      *pphead = next;
    }
  }
}


void SLLPopBack(SLList** pphead)
{
  //没有结点
  if(*pphead==NULL)
  {
    return;
  }
  //一个结点
  else if((*pphead)->next == NULL)
  {
    *pphead = NULL;
  }
  //多个结点
  else
  {
    SLList* prev = NULL;
    SLList* cur =*pphead;
    while(cur->next != NULL)
    {
      prev = cur;
      cur = cur->next;
    }
    prev->next = NULL;
  }
}


void SLLPushFront(SLList** pphead,Datatype x)
{
  //没有节点
  SLList* newnode = BuyNewNode(x);
  if(*pphead == NULL)
  {
    *pphead = newnode;
  }
  //有结点
  else 
  {
    newnode->next=*pphead;
    *pphead=newnode;
  }
}


void SLLPopFront(SLList** pphead)
{
  //没有结点
  if(*pphead == NULL)
  {
    return;
  }
  //有结点
  else 
  {
    SLList* next = (*pphead)->next;
    free(*pphead);
    *pphead = next;
  }
}


SLList* SLLFind(SLList* phead,Datatype x)
{
  SLList* cur = phead;
  while(cur!=NULL)
  {
    if(cur->data == x)
    {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}


void SLLModify(SLList* pos,Datatype x)
{
  assert(pos);
  pos->data=x;
}


SLList* SLLNumFind(SLList* phead,int num)
{
  SLList* cur = phead;
  while(--num)
  {
    if(cur == NULL)
    {
      return NULL;
    }
    cur=cur->next;
  }
  return cur;
}


void InsertAfter(SLList* pos,Datatype x)
{
  assert(pos);
  SLList* next = pos->next;
  SLList* newnode = BuyNewNode(x);
  pos->next=newnode;
  newnode->next=next;
}


void InsertBefore(SLList** pphead,SLList* pos,Datatype x)
{
  assert(pos);
  SLList* newnode = BuyNewNode(x);
  //pos是第一个位置
  if(*pphead == pos)
  {
    newnode->next=*pphead;
    *pphead=newnode;
  }
  //其它位置
  else 
  {
    SLList* prev =NULL;
    SLList* cur = *pphead;
    while(cur!=pos)
    {
      prev = cur;
      cur=cur->next;
    }
    newnode->next = pos;
    prev->next=newnode;
  }
}


void EraseAfter(SLList* pos)
{
  assert(pos);
  if(pos->next == NULL)
  {
    return;
  }
  else 
  {
    SLList* next = pos->next;
    pos->next=next->next;
    free(next);
  }
}


void EraseCurrent(SLList** pphead,SLList* pos)
{
  assert(pos);
  //pos在头位置
  if(pos == *pphead)
  {
    *pphead = pos->next;
    free(pos);
  }
  //pos在其他位置
  else 
  {
    SLList* prev = NULL;
    SLList* cur = *pphead;
    while(cur != pos)
    {
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
  }
}
