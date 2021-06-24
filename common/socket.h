#pragma once
// using
using socket_t = int;

#ifdef _WIN32
// include
#include "ws2tcpip.h"
// link
#pragma comment(lib, "ws2_32.lib")
// using
// func
void wsa_startup();
#else
// include
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/un.h>
#include <sys/uio.h>
#include <sys/select.h>
#include <sys/resource.h>
// using
const int SOCKET_ERROR = -1;
const int INVALID_SOCKET = -1;
#endif

socket_t	create_socket();
void		close_socket(socket_t s);
sockaddr_in	create_sockaddr(const char* ip, int port);
int			set_socket_nonblock(socket_t s);