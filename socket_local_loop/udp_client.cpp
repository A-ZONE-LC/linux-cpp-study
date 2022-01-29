#include"udp_client.hpp"

 int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage:" << argv[0] << "server_ip server_port" << std::endl;
    return 1;
  }
  std::string server_ip = argv[1];
  int server_port = atoi(argv[2]);
  UdpClient* cle = new UdpClient(server_ip, server_port);
  cle->InitUdpClient();
  cle->StartUdpClient();
  return 0;
}
