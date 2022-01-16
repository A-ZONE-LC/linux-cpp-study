#include"Seqlist.h"


void SeqInit(Seqlist* pseq)//初始化顺序表
{
  assert(pseq);
  pseq->a=NULL;
  pseq->size=pseq->capacity=0;
}

void SeqDestroy(Seqlist* pseq)//销毁顺序表
{
  assert(pseq);
  free(pseq->a);
  pseq->a=NULL;
  pseq->capacity=pseq->size=0;
}

void SeqCheckCapacity(Seqlist* pseq)//检查顺序表容量，容量不够增容
{
  assert(pseq);

  if(pseq->size==pseq->capacity)
  {
    int newcapacity = pseq->capacity==0?4:pseq->capacity*2;
    Datatype* newa = (Datatype*)realloc(pseq->a,sizeof(Datatype)*newcapacity);
    pseq->a=newa;
    pseq->capacity=newcapacity;
  }
}

void SeqPushBack(Seqlist* pseq,Datatype x)//尾插x
{
  assert(pseq);
  //SeqCheckCapacity(pseq);//是否需要增容
  //pseq->a[pseq->size]=x;
  //pseq->size++;
  SeqInsert(pseq,pseq->size,x);//复用
}

void SeqPrint(Seqlist* pseq)//打印顺序表
{
  assert(pseq);
  int i=0;
  for(i=0;i<pseq->size;i++)
  {
    printf("%d ",pseq->a[i]);
  }
  if(pseq->size==0)
  { 
    printf("the seqlist is empty!\n");
  }
  printf("\n");
}

void SeqPopBack(Seqlist* pseq)//尾删
{
  assert(pseq);
  //pseq->size--;
  SeqErase(pseq,pseq->size-1);//复用
}

void SeqPushFront(Seqlist* pseq,Datatype x)//头插x
{
  assert(pseq);
  //SeqCheckCapacity(pseq);//是否需要增容

  //int end = pseq->size-1;//设置迭代起点
  //binwhile(end>=0)
  //{
  //  pseq->a[end+1]=pseq->a[end];
  //bin  end--;
  // }
  //pseq->a[0]=x;
  //pseq->size++;
  SeqInsert(pseq,0,x);//复用
}

void SeqPopFront(Seqlist* pseq)//头删
{
  assert(pseq);
  //int begin=0;
  //while(begin<pseq->size-1)
  //{
  //  pseq->a[begin]=pseq->a[begin+1];
  //  begin++;
  //}
  //pseq->size--;
  SeqErase(pseq,0);//复用
}

void SeqInsert(Seqlist* pseq,int pos,Datatype x)//在顺序表下标为pos的位置插入x
{
  assert(pseq);
  assert(pos>=0&&pos<=pseq->size);
  SeqCheckCapacity(pseq);

  int end = pseq->size-1;
  while(pos<=end)
  {
    pseq->a[end+1]=pseq->a[end];
    end--;
  }
  pseq->a[pos]=x;
  pseq->size++;
}

void SeqErase(Seqlist* pseq,int pos)//在顺序表中删除下表为pos的元素
{
  assert(pseq);
  assert(pos>=0&&pos<pseq->size);

  int begin =pos;
  while(begin<pseq->size-1)
  {
    pseq->a[begin]=pseq->a[begin+1];
    ++begin;
  }
  pseq->size--;
}

void SeqFind(Seqlist* pseq,Datatype x)//在顺序表中查找x并打印下标
{
  assert(pseq);
  int i=0;
  for(i=0;i<pseq->size;i++)
  {
    if(pseq->a[i]==x)
    {
      printf("Found it! The index is %d\n",i);
      return;
    }
  }
  printf("Not Found!\n");
}

void SeqModify(Seqlist* pseq,int pos,Datatype x)//将顺序表中下表为pos的元素改为x
{
  assert(pseq);
  assert(pos>=0&&pos<pseq->size);

  pseq->a[pos]=x;
}
