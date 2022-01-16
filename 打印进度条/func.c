#include"func.h"

void PrintProgress()
{
  int  i=0;
  char arr[102]={0};
  for(i=0;i<=100;i++)
  {
    arr[i]='#';
    printf("[%-100s]%d%%\r",arr,i);
    fflush(stdout);
    usleep(200000);
  }
  printf("\nFinished!!\n");
}
