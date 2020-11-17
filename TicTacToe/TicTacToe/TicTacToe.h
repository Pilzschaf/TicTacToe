#pragma once

#include "Field.h"
#include "LocalPlayer.h"
#include "HardAIPlayer.h"
#include "Game.h"

class TicTacToe
{
public:
	void run()
	{
		std::cout << "\nTicTacToe";
		char input;
		while (true)
		{
			std::cout << "\n\nMain Menu:\n\n1: Singleplayer\n2: Local Multiplayer\n3: Quit\n\nInput: ";
			std::cin >> input;
			int numberEntered = input - '0';
			
			field.isPlayer1Perspective = false;

			if (numberEntered == 1)
			{
				(new Game(new LocalPlayer(), new HardAIPlayer()))->run(&field);
				field.resetField();
			}
			else if (numberEntered == 2)
			{
				(new Game(new LocalPlayer(), new LocalPlayer()))->run(&field);
				field.resetField();
			}
			else if (numberEntered == 3)
			{
				break;
			}
			else
			{
				std::cout << "\nInput not recognized. Pleasy try again\n";
			}
		}
	}

private:
	Field field = Field('X', 'o');
};
