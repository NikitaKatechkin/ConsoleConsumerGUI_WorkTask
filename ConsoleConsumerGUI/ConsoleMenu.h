#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include "States.h"
#include "Base_State.h"
#include "Initial_State.h"
#include "Updated_State.h"
#include "Connected_State.h"
#include "Subscribed_State.h"

class Menu
{
public:
	Menu();
	~Menu() = default;

public:
	void showOptionsForAllStates();
	void showCurrentStateOptions();
	void showStateServiceInfo();

	unsigned int processUserInput();
	void clearConsoleScreen();

	void Update(const unsigned int option);
	bool isExitInitiated();
private:
	ConsumerGUIState m_state = ConsumerGUIState::Exit_State;
	BaseState* m_stateHandler = nullptr;

	std::unordered_map<ConsumerGUIState, std::vector<std::string>> m_optionsForStates;

	bool m_isExitInitiated = true;
private:
	void ExtractOptionsForStates();
	void ShowOptionsForState(const ConsumerGUIState& state);
};