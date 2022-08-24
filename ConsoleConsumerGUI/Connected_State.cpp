#include "Connected_State.h"

#include <iostream>

namespace
{
	enum Options
	{
		SHOW_AVAILABLE_DEVICES_ON_INTERFACE_LIST = 0,
		CHOOSE_DEVICE_TO_SUBSCRIBE,
		SUBSCRIBE_TO_CHOOSED_DEVICE,
		STOP_DISCOVERING_INTERFACE,
		EXIT
	};
}

ConsumerGUIState ConnectedState::Update(const unsigned int choice)
{
	ConsumerGUIState resultState = ConsumerGUIState::Updated_State;

	switch (choice)
	{
	case SHOW_AVAILABLE_DEVICES_ON_INTERFACE_LIST:
	{
		resultState = ShowAvailableDevicesOnInterface();

		break;
	}
	case CHOOSE_DEVICE_TO_SUBSCRIBE:
	{
		resultState = ChooseDeviceToSubscribe();

		break;
	}
	case SUBSCRIBE_TO_CHOOSED_DEVICE:
	{
		resultState = SubscribeToDevice();

		break;
	}
	case STOP_DISCOVERING_INTERFACE:
	{
		resultState = StopDiscoveringInterface();

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

ConsumerGUIState ConnectedState::ShowAvailableDevicesOnInterface()
{
    return ConsumerGUIState::Connected_State;
}

ConsumerGUIState ConnectedState::ChooseDeviceToSubscribe()
{
    return ConsumerGUIState::Connected_State;
}

ConsumerGUIState ConnectedState::SubscribeToDevice()
{
    return ConsumerGUIState::Subscribed_State;
}

ConsumerGUIState ConnectedState::StopDiscoveringInterface()
{
    return ConsumerGUIState::Updated_State;
}
