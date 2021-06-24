#pragma once
#include "../common/global.h"
#include "../common/socket.h"

const int C_TUNNEL = 1;
const int C_R_SERVER = 2;
const int C_L_SERVER = 3;
const int C_ALIVE_SECOND = 60;

struct connection;

class Tunnel
{
public:
	void    configure_tunnel();
	int     create_tunnel();

private:
	connection*	create_conn(socket_t fd, int type, boolean is_asyn, void* ptr);

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

struct connection {
	socket_t fd;
	char type; //1.与服务器建立的隧道 2.远程服务器连接 3.本地服务器连接
	void* write_buf; //等待写入的数据
	int len; //等待写入数据的长度
	boolean tag_close; //标记已关闭
	boolean is_asyn; //是否为异步连接
	boolean asyn_conn; //异步连接是否成功
	void* ptr; //额外数据指针
};

/**
 * 通道连接
 */
struct c_tunnel_conn {
	char cmd_buf[1024 * 2];
	int cmd_buf_len;
	time_t last_alive; //最后一次发送心跳时间（秒）
};

/**
 * 远程服务器连接
 */
struct r_server_conn {
	struct connection* l_server_conn;
};

/**
 * 本地服务器连接
 */
struct l_server_conn {
	struct connection* r_server_conn;
};