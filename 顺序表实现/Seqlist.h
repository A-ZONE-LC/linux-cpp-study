#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Datatype;

typedef struct Seqlist
{
  Datatype* a;
  int size;
  int capacity;
}Seqlist;

void SeqInit(Seqlist* pseq);//初始化顺序表
void SeqDestroy(Seqlist* pseq);//销毁顺序表
void SeqPrint(Seqlist* pseq);//打印顺序表

void SeqCheckCapacity(Seqlist* pseq);//检查顺序表容量，容量不够增容
void SeqPushBack(Seqlist* pseq,Datatype x);//尾插x
void SeqPopBack(Seqlist* pseq);//尾删
void SeqPushFront(Seqlist* pseq,Datatype x);//头插x
void SeqPopFront(Seqlist* pseq);//头删
void SeqInsert(Seqlist* pseq,int pos,Datatype x);//在顺序表下标为pos的位置插入x
void SeqErase(Seqlist* pseq,int pos);//在顺序表中删除下表为pos的元素
void SeqFind(Seqlist* pseq,Datatype x);//在顺序表中查找x并打印下标
void SeqModify(Seqlist* pseq,int pos,Datatype x);//将顺序表中下表为pos的元素改为x

