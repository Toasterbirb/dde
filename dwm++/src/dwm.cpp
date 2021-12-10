#include <iostream>
#include <cstring>
#include "../include/program.hpp"

int main(int argc, char *argv[])
{
	program dwm;

	if (argc == 2 && !strcmp("-v", argv[1]))
	{
		std::cout << dwm.getversion() << std::endl;
		return EXIT_SUCCESS;
	}
	else if (argc != 1)
	{
		std::cout << "usage: dwm++ [-v]\n";
		return EXIT_FAILURE;
	}

	if (!std::setlocale(LC_CTYPE, "") || !XSupportsLocale())
		std::cout << "warning: no locale support\n";

	if (!dwm.opendisplay())
	{
		std::cout << "dwm++: cannot open display\n";
		return EXIT_FAILURE;
	}

	//dwm.checkotherwm();
	dwm.setup();
	dwm.scan();
	dwm.run();
	dwm.cleanup();

	dwm.closedisplay();
	return EXIT_SUCCESS;
}

