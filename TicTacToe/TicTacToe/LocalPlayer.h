#pragma once

#include "Player.h"
#include "Field.h"

class LocalPlayer : public Player
{
public:
	void doTurn(Field* field) override;
	void onWin() override;
	void onLose() override;
	void onTie() override;
};