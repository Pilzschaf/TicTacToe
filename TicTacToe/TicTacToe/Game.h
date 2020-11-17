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
			field->switchPerspective();
			player1->doTurn(field);

			Player* player = player1;
			player1 = player2;
			player2 = player;

		}
		field->isPlayer1Perspective = true;

		if (field->hasWon())
		{
			system("clear");
			cout << "\n***** Spieler 1 hat gewonnen! *****" << endl;
			field->printCurrentField();

		}
		//field->isPlayer1Perspective = false;

		if (field->hasLost())
		{
			system("clear");
			cout << "\n***** Spieler 2 hat gewonnen! *****" << endl;
			field->printCurrentField();

		}

		if(!field->hasLost() && !field->hasWon())
		{
			system("clear");
			cout << "\n----- Unentschieden -----" << endl;
			field->printCurrentField();
		}
	}

private:
	Player* player1;
	Player* player2;
};
