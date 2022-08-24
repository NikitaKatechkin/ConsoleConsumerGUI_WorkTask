#pragma once

#include "States.h"

#include <vector>
#include <string>

class BaseState
{
public:
	virtual ConsumerGUIState Update(const unsigned int choice) = 0;
	void ShowOptions();

protected:
	virtual ConsumerGUIState Exit();

	void LoadOptions();
protected:
	std::vector<std::string> m_optionsList;
	ConsumerGUIState m_state;
};