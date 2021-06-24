#include "tunnel.h"

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

	sockaddr_in destAddr = create_sockaddr(ip.c_str(), serverPort);

	if (connect(sock, reinterpret_cast<sockaddr*>(&destAddr), sizeof(destAddr)) == SOCKET_ERROR)
	{
		perror("connect failed!");
		close_socket(sock);
		return -1;
	}

	c_tunnel_conn* tc = new c_tunnel_conn;
	tc->cmd_buf[0] = 0;
	tc->cmd_buf_len = 0;
	tc->last_alive = time(nullptr);

	connection* tunnel = create_conn(sock, C_TUNNEL, true, tc);

	return 0;
}

connection* Tunnel::create_conn(socket_t fd, int type, boolean is_asyn, void* ptr)
{
	struct connection* conn = new connection;
	conn->fd = fd;
	conn->type = type;
	conn->tag_close = false;
	conn->write_buf = null;
	conn->len = 0;
	conn->is_asyn = is_asyn;
	conn->asyn_conn = false;
	conn->ptr = ptr;
	if (is_asyn)
	{
		set_socket_nonblock(conn->fd);
	}
	return conn;
}
