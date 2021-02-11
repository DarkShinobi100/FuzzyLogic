#include <fl/Headers.h>
#include <iostream>
using namespace fl;

int main()
{
	Engine* engine = new Engine();

	std::string status;
	if (not engine->isReady(&status))
		std::cout << "Engine is not ready" << std::endl << status << std::endl;

	delete engine;
	return 0;
}