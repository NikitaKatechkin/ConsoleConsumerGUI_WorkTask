#include "Subscribed_State.h"

#include <iostream>

namespace
{
	enum Options
	{
		UPDATE_INFORMATION_FROM_DEVICE = 0,
		UNSUBSCRIBE_FROM_DEVICE,
		EXIT
	};
}

ConsumerGUIState SubscribedState::Update(const unsigned int choice)
{
	ConsumerGUIState resultState = ConsumerGUIState::Updated_State;

	switch (choice)
	{
	case UPDATE_INFORMATION_FROM_DEVICE:
	{
		resultState = UpdateInformationFromDevice();

		break;
	}
	case UNSUBSCRIBE_FROM_DEVICE:
	{
		resultState = UnsubscribeFromDevice();

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

ConsumerGUIState SubscribedState::UpdateInformationFromDevice()
{
    return ConsumerGUIState::Subscribed_State;
}

ConsumerGUIState SubscribedState::UnsubscribeFromDevice()
{
    return ConsumerGUIState::Connected_State;
}
