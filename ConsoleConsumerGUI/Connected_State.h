#pragma once

#include "Base_State.h"

class ConnectedState final : public BaseState
{
public:
	ConsumerGUIState Update(const unsigned int choice) override;
private:
	ConsumerGUIState ShowAvailableDevicesOnInterface();
	ConsumerGUIState ChooseDeviceToSubscribe();
	ConsumerGUIState SubscribeToDevice();
	ConsumerGUIState StopDiscoveringInterface();
};