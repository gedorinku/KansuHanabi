# include <string>
# include <Siv3D.hpp>
# include <cassert>
# include <thread>
# include "BlockingQueue.h"

class Server{
	private:
		TCPServer tcp_server;
		bool exit_flag = false;
		bool exited = false;
		std::string function_data;
		std::string read_req(void) {
			std::string message;
			while (true) {
				char character;
				if (!tcp_server.read(character)) {

					if (tcp_server.hasError()) {
						tcp_server.disconnect();
					}
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
			while (!exit_flag && !tcp_server.isConnected());
			if (exit_flag) {
				tcp_server.disconnect();
				return;
			}
			LOG(L"connect");
			std::string message;
			message = read_req();
			if (message == "") {
				return;
			}
			LOG(L"message:", FromUTF8(message));
			if (message == "get_list") {
				tcp_server.send(function_data.c_str(), sizeof(char) * (function_data.length() + 1));
				LOG(L"res:", FromUTF8(function_data));
			}else {
				std::string success("success\n");
				request_queue.enqueue(message);
				tcp_server.send(success.c_str(), sizeof(char) * (success.length() + 1));
			}
			tcp_server.disconnect();
		}
	public:
		blocking_queue<std::string> request_queue;
		Server(int functionCount) {
			function_data = std::to_string(functionCount);
			function_data.push_back('\n');
			//それっぽい文字列を生成
			for (int i = 0; i < functionCount; i++) {
				std::string id;
				id = std::to_string(i);
				id.push_back('\n');
				std::string func("y=sin(x)");
				func.push_back('\n');
				function_data += (id + func);
			}
		}
		void start() {
			std::thread s([&] {
				while (!exit_flag) {
					update();
				}
				exited = true;
				return;
			});
			s.detach();
		}
		~Server(){
			exit_flag = true;
			while (!exited) {
				LOG(L"Waiting exit");
			};
		}
};
void Main()
{
	Server server(5);
	server.start();
	while (System::Update());
}
