#pragma once 
#include<iostream>
#include<string>
#include<cstring>
#include<sys/types.h>
#include<sys/socket.h>
#include<string>
#include<netinet/in.h>
#include<arpa/inet.h>

class UdpClient
{
  private:
    int _socketfd;
    std::string server_ip;
    int server_port;
    
  public:
    UdpClient(std::string ip, int port)
      :server_ip(ip)
      ,server_port(port)
    {}

    ~UdpClient()
    {}

    bool InitUdpClient()
    {
      _socketfd = socket(AF_INET, SOCK_DGRAM, 0);
      if(_socketfd < 0)
      {
        std::cerr << "socket create error" << std::endl;
        return false;
      } //客户端socket不需要绑定，但是需要port，由sendto交给OS分配
      return true;
    }

    void StartUdpClient()
    {
      struct sockaddr_in peer;
      memset(&peer, '\0', sizeof(peer));
      peer.sin_port = htons(server_port);
      peer.sin_family = AF_INET;
      peer.sin_addr.s_addr = inet_addr(server_ip.c_str());
      std::string msg;

      for( ; ; )
      {
        std::cout << "Please Input# ";
        std::getline(std::cin, msg);
        sendto(_socketfd, msg.c_str(), msg.size(), 0, (struct sockaddr*)&peer, sizeof(peer)); //注意强转sockaddr指针
      }
    }
};
