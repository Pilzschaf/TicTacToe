#pragma once

#include <iostream>

class Field
{
public:
	Field(char player1Char = 'X', char player2Char = 'O');
	void switchPerspective();

	bool putOwnMarkAt(int pos);
	bool putEnemyMarkAt(int pos);
	void putEmptyMarkAt(int pos);

	bool isOwnMarkAt(int pos);
	bool isEnemyMarkAt(int pos);
	bool isEmptyMarkAt(int pos);

	int getNumFreePositions();
	int* getFreePositions(int* positions);

	void printCurrentField();

	bool hasWon();
	bool hasLost();
	bool isFull();

	void resetField();

private:
	bool hasPlayerWithCharWon(char character);

	bool isPlayer1Perspective = true;
	char player1Char = ' ';
	char player2Char = ' ';
	int numFreePostions = 9;
	char field[9];
};