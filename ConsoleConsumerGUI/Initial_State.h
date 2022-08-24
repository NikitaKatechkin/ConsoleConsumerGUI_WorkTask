#pragma once

#include "Base_State.h"

class InitialState final : public BaseState
{
public:
	ConsumerGUIState Update(const unsigned int choice) override;
private:
	ConsumerGUIState UpdateNetworkInterfaces();
};