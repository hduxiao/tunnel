#include "socket.h"

#ifdef _WIN32
void _wsa_cleanup()
{
	WSACleanup();
}

void wsa_startup()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0)
	{
		atexit(_wsa_cleanup);
	}
}
#endif

socket_t create_socket()
{
	return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

void close_socket(socket_t s)
{
#ifdef _WIN32
	closesocket(s);
#else
	close(s);
#endif
}

sockaddr_in create_sockaddr(const char* ip, int port)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	return addr;
}

int set_socket_nonblock(socket_t s)
{
#ifdef _WIN32
	u_long mode = 1;
	return ioctlsocket(s, FIONBIO, &mode);
#else
	int mode = fcntl(s, F_GETFL, 0);
	if (mode == SOCKET_ERROR)
		return SOCKET_ERROR;
	if (mode & O_NONBLOCK)
		return 0;
	return fcntl(s, F_SETFL, mode | O_NONBLOCK);
#endif
}
