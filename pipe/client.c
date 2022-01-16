#include"comm.h"

int main()
{
  //打开管道文件
  int fd = open(FILE_NAME, O_WRONLY);
  if(fd < 0)
  {
    printf("open error!\n");
    return 1;
  }

  char msg[128];
  while(1)
  {
    msg[0] = '\0';
    printf("Please input# ");
    fflush(stdout);
    ssize_t s = read(0, msg, sizeof(msg));
    //printf("%d",msg[s-1]); 换行的ASCII码 10
    msg[s] = '\0';
    if(s > 0)
    {
      ssize_t w = write(fd, msg, strlen(msg)-1);
      //msg的最后一个字符是换行，如果不减1，结果就会多换一行
      if(w < 0)
      {
        printf("write error!\n");
        break;
      }
    }
  }
  close(fd);
  return 0;
}
