#pragma once
#include <Siv3D.hpp>
#include "BlockingQueue.h"


class Server {
private:
	TCPServer tcp_server;
	bool exit_flag = false;
	bool exited = false;
	std::string function_data;
	
	std::string read_req(void);
	void update(void);
public:

	Server(int functionCount);
	void start();
	~Server();

	blocking_queue<std::string> request_queue;
};