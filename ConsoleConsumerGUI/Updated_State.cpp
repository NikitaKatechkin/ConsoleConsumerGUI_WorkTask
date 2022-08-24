#include "Updated_State.h"

#include <iostream>

namespace
{
	enum Options
	{
		UPDATE_NETWORK_INTERFACES_LIST = 0,
		SHOW_AVAILABLE_INTERFACES_LIST,
		CHOOSE_INTERFACE_TO_CONNECT,
		CONNECT_TO_CHOOSED_INTERFACE,
		EXIT
	};
}

ConsumerGUIState UpdatedState::Update(const unsigned int choice)
{
	ConsumerGUIState resultState = ConsumerGUIState::Updated_State;

	switch (choice)
	{
	case UPDATE_NETWORK_INTERFACES_LIST:
	{
		resultState = UpdateNetworkInterfaces();

		break;
	}
	case SHOW_AVAILABLE_INTERFACES_LIST:
	{
		resultState = ShowAvailableInterfaces();

		break;
	}
	case CHOOSE_INTERFACE_TO_CONNECT:
	{
		resultState = ChooseInterfaceToConnect();

		break;
	}
	case CONNECT_TO_CHOOSED_INTERFACE:
	{
		resultState = ConnectToInterface();

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

ConsumerGUIState UpdatedState::UpdateNetworkInterfaces()
{
	return ConsumerGUIState::Updated_State;
}

ConsumerGUIState UpdatedState::ShowAvailableInterfaces()
{
	return ConsumerGUIState::Updated_State;
}

ConsumerGUIState UpdatedState::ChooseInterfaceToConnect()
{
	return ConsumerGUIState::Updated_State;
}

ConsumerGUIState UpdatedState::ConnectToInterface()
{
	return ConsumerGUIState::Connected_State;
}
