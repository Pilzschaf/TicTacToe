#include "Field.h"

Field::Field(char player1Char, char player2Char)
{
	this->player1Char = player1Char;
	this->player2Char = player2Char;

	if (player1Char == player2Char || player1Char == ' ' || player2Char == ' ')
	{
		this->player1Char = 'X';
		this->player2Char = 'O';
	}

	resetField();
}

void Field::resetField()
{
	this->numFreePostions = 9;
	
	this->isPlayer1Perspective = true;

	for (int i = 0; i < 9; i++)
	{
		field[i] = ' ';
	}
}

int Field::getNumFreePositions()
{
	return numFreePostions;
}

int* Field::getFreePositions(int* positions)
{
	int arrayPos = 0;
	for (int i = 0; i < 9; i++)
	{
		if (field[i] == ' ')
		{
			positions[arrayPos] = i;
			arrayPos++;
		}
	}
	return positions;
}

void Field::switchPerspective()
{
	isPlayer1Perspective = !isPlayer1Perspective;
}

bool Field::putOwnMarkAt(int pos)
{
	if (field[pos] == ' ')
	{
		if (isPlayer1Perspective)
			field[pos] = player1Char;
		else
			field[pos] = player2Char;
		numFreePostions--;
		return true;
	}
	return false;
}

bool Field::putEnemyMarkAt(int pos)
{
	if (field[pos] == ' ')
	{
		if (isPlayer1Perspective)
			field[pos] = player2Char;
		else
			field[pos] = player1Char;
		numFreePostions--;
		return true;
	}
	return false;
}

void Field::putEmptyMarkAt(int pos)
{
	if (field[pos] != ' ')
	{
		field[pos] = ' ';
		numFreePostions++;
	}
}

bool Field::isOwnMarkAt(int pos)
{
	if (isPlayer1Perspective)
		return field[pos] == player1Char;
	else
		return field[pos] == player2Char;
}

bool Field::isEnemyMarkAt(int pos)
{
	if (isPlayer1Perspective)
		return field[pos] == player2Char;
	else
		return field[pos] == player1Char;
}

bool Field::isEmptyMarkAt(int pos)
{
	return field[pos] == ' ';
}

void Field::printCurrentField()
{
	std::cout << "\n\n\n"
		<< "     " << field[0] << " | " << field[1] << " | " << field[2] << std::endl
		<< "    ---|---|---" << std::endl
		<< "     " << field[3] << " | " << field[4] << " | " << field[5] << std::endl
		<< "    ---|---|---" << std::endl
		<< "     " << field[6] << " | " << field[7] << " | " << field[8] << std::endl;
}

bool Field::hasPlayerWithCharWon(char character)
{
	if (field[0] == character && field[1] == character && field[2] == character
		|| field[0] == character && field[3] == character && field[6] == character
		|| field[0] == character && field[4] == character && field[8] == character
		|| field[1] == character && field[4] == character && field[7] == character
		|| field[2] == character && field[5] == character && field[8] == character
		|| field[2] == character && field[4] == character && field[6] == character
		|| field[3] == character && field[4] == character && field[5] == character
		|| field[6] == character && field[7] == character && field[8] == character)
	{
		return true;
	}
	return false;
}

bool Field::hasWon()
{
	if (isPlayer1Perspective)
		return hasPlayerWithCharWon(player1Char);
	else
		return hasPlayerWithCharWon(player2Char);
}

bool Field::hasLost()
{
	if (isPlayer1Perspective)
		return hasPlayerWithCharWon(player2Char);
	else
		return hasPlayerWithCharWon(player1Char);
}

bool Field::isFull()
{
	return numFreePostions <= 0;
}
