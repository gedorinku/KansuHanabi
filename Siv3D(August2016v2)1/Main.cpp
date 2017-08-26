# include <string>
# include <Siv3D.hpp>
# include <cassert>
#include <thread>
# include "BlockingQueue.h"

class Server{
	private:
		TCPServer tcp_server;
		std::string function_cnt;
		blocking_queue<std::string> request_queue;
		std::string read_req(void) {
			std::string message;
			while (true) {
				char character;
				if (!tcp_server.read(character)) {
					break;
				}

				if (character == '\0') {
					return message;
				}else {
					message.push_back(character);
				}
			}
			return "";
		}
		void update(void) {
			tcp_server.startAccept(80);
			while (!tcp_server.isConnected());
			std::string message;
			message = read_req();
			if (message == "") {
				return;
			}
			LOG(L"message:", FromUTF8(message));
			if (message == "get_list") {
				tcp_server.send(function_cnt.c_str(), sizeof(char) * (function_cnt.length() + 1));
				LOG(L"res:", FromUTF8(function_cnt));
			}else {
				std::string success("success");
				request_queue.enqueue(message);
				tcp_server.send(success.c_str(), sizeof(char) * (success.length() + 1));
			}
			tcp_server.disconnect();
		}
	public:
		
		Server(int functionCount) {
			function_cnt = std::to_string(functionCount);
		}
		void start() {
			std::thread s([&] {
				while (true) {
					update();
				}
			});
			s.detach();
		}
};
void Main()
{
	Server server(5);
	server.start();
	while (System::Update());
}
