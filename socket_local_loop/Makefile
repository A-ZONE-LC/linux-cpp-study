.PHONY:all
all:udp_client udp_server

udp_client:udp_client.cpp 
		g++ -o udp_client udp_client.cpp -std=c++11
udp_server:udp_server.cpp 
		g++ -o udp_server udp_server.cpp -std=c++11

.PHONY:clean
clean:
		rm -rf udp_server udp_client 
