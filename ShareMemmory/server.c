#include"comm.h"

int main()
{
  //生成key
  key_t k = ftok(PATHNAME, PROJ_ID);
  if(k < 0)
  {
    printf("ftok error\n");
    return 1;
  }
  //创建共享内存
  int shmid = shmget(k, SIZE, IPC_CREAT|IPC_EXCL|0666);
  if(shmid < 0)
  {
    printf("shmget error\n");
    return 2;
  }
  
  //开始关联
  char* memaddr = (char*)shmat(shmid, NULL, 0);

  //correspond
  int i = 26;
  while(i--)
  {
    printf("client# %s\n",memaddr);
    sleep(1);
  }
  
  
  //去关联
  shmdt(memaddr);
  
  //销毁共享内存
  shmctl(shmid, IPC_RMID, NULL);
  sleep(5);
  
  return 0;
}
