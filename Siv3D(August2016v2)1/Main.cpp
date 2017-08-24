# include <string>
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	TCPServer server;
	int req;
	std::string res("114514\n");
	Window::SetTitle(L"サーバー");
	bool isOpen = false;
	while (System::Update())
	{
		if (!isOpen) {
			server.startAccept(80);
			isOpen = true;
		}
		if (server.isConnected()) {
			while (server.read(req));
			Println(L"req:",req);
			server.send(res.c_str(), sizeof(char) * (res.length() + 1));
			Println(L"send:114514");
			server.disconnect();
			isOpen = false;
		}

	}
}
