#include "HardAIPlayer.h"

HardAIPlayer::HardAIPlayer()
{
	srand((unsigned int)time(nullptr));
}

void HardAIPlayer::doTurn(Field* field)
{
	int numPossibilities = field->getNumFreePositions();
	int* possibilities = new int[numPossibilities];

	field->getFreePositions(possibilities);

	for (int i = 0; i < numPossibilities; i++)
	{
		field->putOwnMarkAt(possibilities[i]);
		if (field->hasWon())
			return;
		field->putEmptyMarkAt(possibilities[i]);
	}

	for (int i = 0; i < numPossibilities; i++)
	{
		field->putEnemyMarkAt(possibilities[i]);
		if (field->hasLost())
		{
			field->putEmptyMarkAt(possibilities[i]);
			field->putOwnMarkAt(possibilities[i]);
			return;
		}
		field->putEmptyMarkAt(possibilities[i]);
	}

	field->putOwnMarkAt(possibilities[rand() % numPossibilities]);
}