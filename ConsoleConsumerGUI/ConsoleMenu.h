#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "States.h"

class Menu
{
public:
	Menu();
	~Menu() = default;

public:
	void showOptionsForAllStates();
	void showCurrentStateOptions();

	void processUserInput();
private:
	ConsumerGUIState m_state;
	std::unordered_map<ConsumerGUIState, std::vector<std::string>> m_optionsForStates;

private:
	void ExtractOptionsForStates();
	void ShowOptionsForState(const ConsumerGUIState& state);
};