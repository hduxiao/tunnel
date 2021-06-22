#pragma once

#ifdef _WIN32
// include
#include "ws2tcpip.h"
// link
#pragma comment(lib, "ws2_32.lib")
// using
using socket_t = int;
using sockaddr_t = sockaddr_in;
// func
void wsa_startup();
#endif

socket_t	create_socket();
void		close_socket(socket_t s);
sockaddr_t	create_sockaddr(const char* ip, int port);