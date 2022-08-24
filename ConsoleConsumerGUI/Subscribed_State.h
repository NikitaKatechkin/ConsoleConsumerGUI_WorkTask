#pragma once

#include "Base_State.h"

class SubscribedState final : public BaseState
{
public:
	ConsumerGUIState Update(const unsigned int choice) override;
private:
	ConsumerGUIState UpdateInformationFromDevice();
	ConsumerGUIState UnsubscribeFromDevice();
};