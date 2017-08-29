# include <string>
# include <Siv3D.hpp>
# include <cassert>
#include <thread>
# include "BlockingQueue.h"


void Main()
{
	Server server(5);
	server.start();
	while (System::Update());
}
