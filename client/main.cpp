#include "tunnel.h"

int main()
{
	Tunnel* pTunnel = new Tunnel;

	//pTunnel->configure_tunnel();
	if (pTunnel->create_tunnel() >= 0)
	{
		std::cout << "create tunnel successfully\n";
	}
}