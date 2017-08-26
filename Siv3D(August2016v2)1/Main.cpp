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
			while(true){
				char character;

				if (!tcp_server.read(character)) {
					Println(L"read error");
					return "";
				}

				if (character == '\0'){
					return message;
				}else{
					message.push_back(character);
				}
			}
		}
		void update(void) {
			if (tcp_server.isConnected()) {
				std::string message;
				message = read_req();
				Println(L"message:", FromUTF8(message));
				if (message == "get_list") {
					tcp_server.send(function_cnt.c_str(), sizeof(char) * (function_cnt.length() + 1));
					Println(L"res", FromUTF8(function_cnt));
				}
				else {
					request_queue.enqueue(message);
				}
				tcp_server.disconnect();
				tcp_server.startAccept(80);
				return;
			}
			
			
		}
	public:
		
		Server(int functionCount) {
			function_cnt = std::to_string(functionCount);
		}
		void start() {
			std::thread s([&] {
				tcp_server.startAccept(80);
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
