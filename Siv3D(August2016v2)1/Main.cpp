# include <string>
# include <Siv3D.hpp>

void Main()
{
	const Font font(30);
	TCPServer server;
	int req;
	std::string res("114514\n");
	Window::SetTitle(L"サーバー");
	server.startAccept(80);
	while (System::Update())
	{
		if (server.isConnected()) {
			while (server.read(req));
			font(req).draw();
			server.send(res.c_str(),sizeof(char) * (res.length() + 1));

		}

	}
}
