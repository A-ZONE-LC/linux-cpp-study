#include"comm.h"

int main()
{
  //创建管道文件，创建失败退出进程
  if(mkfifo(FILE_NAME, 0644) < 0)
  {
    perror("mkfifo");
    return 1;
  }
  //打开管道文件进行读操作
  int fd = open(FILE_NAME, O_RDONLY);
  if(fd < 0)
  {
    printf("open error!\n");
    return 2;
  }
  
  char msg[128];
  while(1)
  {
    msg[0] = '\0';
    ssize_t s = read(fd, msg, sizeof(msg));
    if(s > 0)
    {
      msg[s] = '\0';
      printf("server# %s\n",msg);
      if(fork() == 0)
      {
        execlp(msg, msg, NULL);
        exit(1);

      }
      waitpid(-1, NULL, 0);
    }
    else if(s == 0) 
    {
      printf("client quit!\n");
      break;
    }
    else 
    {
      printf("read error\n");
      break;
    }
  }

  close(fd);
  return 0;
}
