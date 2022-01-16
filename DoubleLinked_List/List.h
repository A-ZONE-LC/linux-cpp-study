#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datatype;
typedef struct ListNode
{
  struct ListNode* prev;
  struct ListNode* next;
  Datatype data;
}ListNode;

ListNode* ListInit();//对带头双向循环链表进行初始化，建立头结点
ListNode* BuyListNode(Datatype x);//建立新结点
void ListPrint(ListNode* pHead);//打印链表
void ListInsert(ListNode* pos,Datatype x);//在pos位置之前插入x
void ListErase(ListNode* pos);//删除pos位置的结点
void ListPushBack(ListNode* pHead,Datatype x);//尾插x
void ListPopBack(ListNode* pHead);//尾删x
void ListPushFront(ListNode* pHead,Datatype x);//头插x
void ListPopFront(ListNode* pHead);//头删
ListNode* ListFind(ListNode* pHead,Datatype x);//查找x,返回x的地址
bool ListEmpty(ListNode* pHead);//检查链表是否为空
int ListSize(ListNode* pHead);//计算链表长度
