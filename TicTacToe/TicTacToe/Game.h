#pragma once

#include "Player.h"
#include "Field.h"

class Game
{
public:
	Game(Player* player1, Player* player2) : player1(player1), player2(player2) {};

	void run(Field* field)
	{
		while (!field->isFull() && !field->hasLost() && !field->hasWon())
		{
			player1->doTurn(field);

			Player* player = player1;
			player1 = player2;
			player2 = player;

			field->switchPerspective();
		}

		if (field->hasWon())
		{
			player1->onWin();
			player2->onLose();
		}
		else if (field->hasLost())
		{
			player2->onWin();
			player1->onLose();
		}
		else
		{
			player1->onTie();
			player2->onTie();
		}
	}

private:
	Player* player1;
	Player* player2;
};