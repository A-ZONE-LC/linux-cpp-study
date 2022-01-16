#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;

typedef struct SLList
{
  Datatype data;
  struct SLList* next;
}SLList;


SLList* BuyNewNode(Datatype x);//建立新节点
void PrintList(SLList* phead);//打印该单链表
void DestroyList(SLList** pphead);//销毁单链表

void SLLPushBack(SLList** pphead,Datatype x );//尾插
void SLLPopBack(SLList** pphead);//尾删
void SLLPushFront(SLList** pphead,Datatype x);//头插
void SLLPopFront(SLList** pphead);//头删

SLList* SLLFind(SLList* phead, Datatype x);//在单链表中查找第一个为x的元素位置
SLList* SLLNumFind(SLList* phead,int num);//找到单链表第num位置的结点
void SLLModify(SLList* pos,Datatype x);//把单链表pos位置的元素值改为x

void InsertAfter(SLList* pos,Datatype x);//在pos位置之后插入x
void InsertBefore(SLList** pphead,SLList* pos,Datatype x);//在pos位置之前插入x
void EraseAfter(SLList* pos);//删除pos位置之后的结点
void EraseCurrent(SLList** pphead,SLList* pos);//删除cur位置的结点
