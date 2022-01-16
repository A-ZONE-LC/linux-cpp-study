#include"comm.h"

int main()
{
  //得到与server相同的key
  key_t k = ftok(PATHNAME, PROJ_ID);
  if(k < 0)
  {
    perror("ftok");
    return 1;
  }
  
  //得到与server相同的shmid
  int shmid = shmget(k, SIZE, IPC_CREAT);
  if(shmid < 0)
  {
    perror("shmget");
    return 2;
  }

  //得到映射到client的虚拟地址,挂接
  char* memaddr = (char*)shmat(shmid, NULL, 0);
  
  //correspond
  int i = 0;
  while(26)
  {
    memaddr[i] = 'A' + i;
    i++;
    sleep(1);
  }

  //去关联
  shmdt(memaddr);
  return 0;
}
