#include "Game.h"

bool Game::IsPossible()
{
	for (auto handful : handfuls)
	{
		if (!bag.CanPick(std::get<0>(handful), std::get<1>(handful), std::get<2>(handful)))
			return false;
	}

	return true;
}

int Game::Power()
{
	int minRed = { 0 };
	int minGreen = { 0 };
	int minBlue = { 0 };
	int minNeeded = { 0 };

	for (tuple<int, int, int> handful : handfuls)
	{
		minRed = std::max(minRed, std::get<0>(handful));
		minGreen = std::max(minGreen, std::get<1>(handful));
		minBlue = std::max(minBlue, std::get<2>(handful));
	}

	return minRed * minGreen * minBlue;
}
