#pragma once

#include "Base_State.h"

class UpdatedState final : public BaseState
{
public:
	ConsumerGUIState Update(const unsigned int choice) override;
private:
	ConsumerGUIState UpdateNetworkInterfaces();
	ConsumerGUIState ShowAvailableInterfaces();
	ConsumerGUIState ChooseInterfaceToConnect();
	ConsumerGUIState ConnectToInterface();
};