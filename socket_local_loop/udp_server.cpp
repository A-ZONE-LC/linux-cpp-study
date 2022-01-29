#include"udp_server.hpp" 

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " port" << std::endl;
    return 1;
  }

  std::string ip = "127.0.0.1"; //"127.0.0.1" == localhost 本地主机,本地环回
  int port = atoi(argv[1]);
  UdpServer* sev = new UdpServer(ip, port);
  sev->InitUdpServer();
  sev->StartUdpServer();
  return 0;
}
