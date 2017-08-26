# include <string>
# include <Siv3D.hpp>

class Server{
	private:
		TCPServer tcp_server;
		std::string function_cnt;
		bool is_open;
		std::string read_req(void) {
			std::string message;
			while(true){
				char character;

				if (!tcp_server.read(character)) {
					return "";
				}

				if (character == '\0'){
					return message;
				}else{
					message.push_back(character);
				}
			}
		}
	public:
		Server(int functionCount) {
			function_cnt = std::to_string(functionCount);
			is_open = false;
		}
		std::string update(void) {
			std::string message;
			if (!is_open) {
				tcp_server.startAccept(80);
				is_open = true;
			}
			if (tcp_server.isConnected()) {
				message = read_req();
				Println(L"req:", FromUTF8(message));
				if (message == "get_list") {
					tcp_server.send(function_cnt.c_str(), sizeof(char) * (function_cnt.length() + 1));
					return "";
				}
				tcp_server.disconnect();
				is_open = false;
				return message;
			}
			return "";
		}
};
void Main()
{
	Server server(5);
	while (System::Update()) {
		server.update();
	}
}
