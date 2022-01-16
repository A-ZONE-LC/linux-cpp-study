#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  char cmd[1024];
  char* arg[32];
  while(1)
  {
    printf("[cga@my-shell A-ZONE]$ ");
    fgets(cmd, 1024, stdin);
    cmd[strlen(cmd)-1] = '\0';

    char* p = cmd;
    while(*p != '\0')
    {
      if(*p == '>')
      {
        *p = '\0';
        p++;
        break;
      }
      else 
      {
        p++;
      }
    }
    if(*p != '\0')
    {
      while(isspace(*p))
      {
        p++;
      }
    }

    arg[0] = strtok(cmd , " ");
    int i = 1;
    while(arg[i] = strtok(NULL , " "))
    {
      i++;
    }

    pid_t id = fork();
    if(id == 0)
    {
      if(*p != '\0')
      {
        int fd = open(p ,O_WRONLY|O_CREAT,0644);
        if(fd < 0)
        {
          perror("open");
          exit(2);
        }
        dup2(fd ,1);
      }
      execvp(arg[0], arg);
      exit(1);
    }
    int status = 0;
    pid_t ret = waitpid(id ,&status,0);
    if(ret > 0)
    {
      printf("exit code: %d\n",WEXITSTATUS(status));
    }
  }  
    
  return 0;
}
