#include "ConsoleMenu.h"

#include <string>
#include <cstdlib>

int main()
{
	Menu menu;
	
	while (menu.isExitInitiated() == false)
	{
		menu.showCurrentStateOptions();
		menu.showStateServiceInfo();

		auto userInput = menu.processUserInput();
		menu.Update(userInput);
		
		menu.clearConsoleScreen();
	}

	return 0;
}