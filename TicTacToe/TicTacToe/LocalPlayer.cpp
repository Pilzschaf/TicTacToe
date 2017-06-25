#include "LocalPlayer.h"

void LocalPlayer::doTurn(Field* field)
{
	int pos = 0;
	char input = ' ';
	while (true)
	{
		field->printCurrentField();
		std::cout << "\n Select field you want to put your mark at: ";
		std::cin >> input;
		std::cout << std::endl;
		pos = input - '0';
		pos--;

		if (pos <= 8 && pos >= 0)
		{
			if (field->isEmptyMarkAt(pos))
			{
				field->putOwnMarkAt(pos);
				return;
			}
			else
			{
				std::cout << "Field at position " << pos << " is not empty\n";
			}
		}
		else
		{
			std::cout << "Input not recognized: Pleasy try again\n";
			pos = 0;
		}
	}
}

void LocalPlayer::onLose()
{
	std::cout << "\n You lost \n";
}

void LocalPlayer::onWin()
{
	std::cout << "\n You won \n";
}

void LocalPlayer::onTie()
{
	std::cout << "\n Tie \n";
}