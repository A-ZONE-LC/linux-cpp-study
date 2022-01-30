#pragma once 
#include<iostream>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<cstring>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#define SIZE 1024
#define DEFAULT 8081

class UdpServer
{
  private:
    int _port; //端口号
    int _socketfd;
    //std::string _ip; //ip地址 云服务器
  public:

    UdpServer(int port = DEFAULT)
      :_port(port)
      ,_socketfd(-1)
    {}

    bool InitUdpServer()
    {
      _socketfd = socket(AF_INET, SOCK_DGRAM, 0); //AF_INET指ipv4协议，SOCK_DGRAM指UDP协议，返回值是文件描述符
      if(_socketfd < 0) //socket创建失败
      {
        std::cerr << "socket create error" << std::endl;
        return false;
      }
      std::cout<< "socket create success: socketfd: " << _socketfd << std::endl;

      struct sockaddr_in local; //填充属性信息
      memset(&local, '\0', sizeof(local));
      local.sin_family = AF_INET;
      local.sin_port = htons(_port); //port需要发送到网络中，需要设置为网络序列
      local.sin_addr.s_addr = INADDR_ANY; //可接受任意网卡

      //将socketfd与sockaddr_in进行绑定
      if(bind(_socketfd, (struct sockaddr*)&local, sizeof(local)) < 0)
      {
        std::cerr << "bind error" << std::endl;
        return false;
      }
      std::cout << "bind success" << std::endl;
      return true;
    }

    void StartUdpServer()
    {
      char buffer[SIZE];
      for( ; ; )
      {
        struct sockaddr_in peer; //对端的sockaddr输出型参数
        socklen_t len = sizeof(peer);
        ssize_t size = recvfrom(_socketfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&peer, &len); //获取内容到缓冲区和获取对端的sockaddr
        if(size > 0) //获取成功
        {
          buffer[size] = 0;
          int port = ntohs(peer.sin_port); //获取对端的端口号
          std::string ip = inet_ntoa(peer.sin_addr); //获取对端的ip地址
          std::cout << ip << ":" << port << "#" << buffer << std::endl; //打印缓冲区的内容

          //echo_msg += buffer;
          //sendto(_socketfd, echo_msg.c_str(), echo_msg.size(), 0, (struct sockaddr*)&peer, len); //给用户回复消息
          std::string cmd = buffer;
          std::string ret;
          if(cmd == "ls")
          {
            int pipefd[2];
            pipe(pipefd);
            pid_t id = fork();
            if(id == 0)
            {
              //child 子进程写，父进程读
              close(pipefd[0]);
              dup2(pipefd[1], 1); //输出重定向到管道文件
              execl("/usr/bin/ls", "ls", "-a", "-l", "-i", nullptr); //进程替换
              exit(1);
            } 
            //parent
            close(pipefd[1]);
            char c;
            while(1) //父进程读取管道文件
            {
              if(read(pipefd[0], &c, 1) > 0)
              {
                ret.push_back(c);
              }
              else 
                break;
            }
            wait(nullptr);

            std::string echo_msg = "server->";
            if(ret.empty())
            {
              echo_msg += "empty";
            }
            else 
            {
              echo_msg = ret;
            }
            sendto(_socketfd, echo_msg.c_str(), echo_msg.size(), 0, (struct sockaddr*)&peer, len); //将处理完的数据发送给用户端
          }
        }
        else 
        {
          std::cerr << "recvfrom error" << std::endl;
        }
      }
    }

    ~UdpServer()
    {
      if(_socketfd > 0)
        close(_socketfd);
    }

};
