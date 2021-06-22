#include "tunnel.h"
#include "../common/socket.h"

void Tunnel::configure_tunnel()
{
	// input ip
	std::cout << "Enter server ip: ";
	std::cin >> ip;
	clear_stdin();

	// input server port
	std::cout << "Enter server port(dafault 4399): ";
	serverPort = input(4399);

	// input local port
	std::cout << "Enter local port: ";
	std::cin >> localPort;
	clear_stdin();

	// input passwd
	std::cout << "Enter connect password(default pi): ";
	passwd = input("pi");

	// output configuration
	std::cout << "\nyour profile: \n";
	std::cout << "server ip:   " << ip << std::endl;
	std::cout << "server port: " << serverPort << std::endl;
	std::cout << "local port:  " << localPort << std::endl;
	std::cout << "password:    " << passwd << std::endl;
}

int Tunnel::create_tunnel()
{
#ifdef _WIN32
	wsa_startup();
#endif

	socket_t sock = create_socket();
	if (sock == INVALID_SOCKET)
	{
		perror("create socket failed!");
		return -1;
	}

	sockaddr_t destAddr = create_sockaddr(ip.c_str(), serverPort);

	if (connect(sock, reinterpret_cast<sockaddr*>(&destAddr), sizeof(destAddr)) == SOCKET_ERROR)
	{
		perror("connect failed!");
		close_socket(sock);
		return -1;
	}

	return 0;
}
