#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define LEN 1024
#define NUM 32

int main()
{
  char cmd[LEN];
  char* myarg[NUM];
  while(1)
  {
    printf("[cga@my-shell A-ZONE]# ");
    fgets(cmd, LEN, stdin); //从输入流中获取字符串存到cmd中
    cmd[strlen(cmd)-1] =  '\0';
    myarg[0] = strtok(cmd," "); //将字符串拆分成各部分放到myargv中
    int i=1;
    while(myarg[i] = strtok(NULL," "))
    {
      i++;
    }

    pid_t id = fork();
    if(id == 0) //子进程进程替换
    {
      execvp(myarg[0],myarg);
    }
    
    int status = 0;
    pid_t ret = waitpid(id,&status,0);
    if(ret > 0)
    {
      printf("exit code: %d\n",WEXITSTATUS(status));
    }
  }
  return 0;
}
