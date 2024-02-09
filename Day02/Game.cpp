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
