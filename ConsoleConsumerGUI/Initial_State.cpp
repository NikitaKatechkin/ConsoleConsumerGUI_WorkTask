#include "Initial_State.h"

#include <iostream>

namespace
{
	enum Options
	{
		UPDATE_NETWORK_INTERFACES_LIST = 0,
		EXIT
	};
}

ConsumerGUIState InitialState::Update(const unsigned int choice)
{
	ConsumerGUIState resultState = ConsumerGUIState::Initial_State;

	switch (choice)
	{
	case UPDATE_NETWORK_INTERFACES_LIST:
	{
		resultState = UpdateNetworkInterfaces();

		break;
	}
	case EXIT:
	{
		resultState = Exit();
		
		break;
	}
	default:
	{
		std::cerr << "[Initial_State::Update()] ";
		std::cerr << "Wrong option index was provided";

		break;
	}
	}

	return resultState;
}

ConsumerGUIState InitialState::UpdateNetworkInterfaces()
{
	return ConsumerGUIState::Updated_State;
}
