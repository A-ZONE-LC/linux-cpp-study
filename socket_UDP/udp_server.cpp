#include"udp_server.hpp" 

int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cout << "Usage: " << argv[0] << " port" << std::endl;
    return 1;
  }

  int port = atoi(argv[1]);
  UdpServer* sev = new UdpServer(port);
  sev->InitUdpServer();
  sev->StartUdpServer();
  return 0;
}
