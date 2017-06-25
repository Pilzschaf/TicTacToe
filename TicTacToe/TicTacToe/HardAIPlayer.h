#pragma once

#include <random>
#include <time.h>

#include "Player.h"
#include "Field.h"

class HardAIPlayer : public Player
{
public:
	HardAIPlayer();
	void doTurn(Field* field) override;
};