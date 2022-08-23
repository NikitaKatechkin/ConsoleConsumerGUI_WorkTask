#include "ConsoleMenu.h"

#include <string>
#include <cstdlib>

int main()
{
	Menu menu;
	
	std::string userInput;

	while (true)
	{
		menu.showCurrentStateOptions();
		menu.processUserInput();

		system("CLS");
	}

	return 0;
}