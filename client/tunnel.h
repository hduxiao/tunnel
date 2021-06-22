#pragma once
#include "../common/global.h"

class Tunnel
{
public:
	void    configure_tunnel();
	int     create_tunnel();

private:
	//std::string ip, passwd;
	//int	        serverPort{ -1 };
	////int	    proxyPort{ -1 };
	//int	        localPort{ -1 };
	std::string ip{ "47.98.215.97" };
	std::string passwd{ "pi" };
	int	        serverPort{ 8877 };
	//int	    proxyPort{ -1 };
	int	        localPort{ 22 };
};