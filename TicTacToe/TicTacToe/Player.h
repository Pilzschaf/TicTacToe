#pragma once

#include "Field.h"

class Player abstract
{
public:
	virtual void doTurn(Field *field) = 0;
	virtual void onLose() {};
	virtual void onWin() {};
	virtual void onTie() {};
	virtual ~Player() {};
};