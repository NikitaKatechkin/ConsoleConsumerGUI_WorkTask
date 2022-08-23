#pragma once

#include <unordered_map>
#include <list>

#define NUMBER_OF_STATES 4

enum class ConsumerGUIState
{
	Initial_State = 0,
	Updated_State,
	Connected_State,
	Subscribed_State
};