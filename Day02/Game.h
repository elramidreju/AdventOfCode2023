#pragma once
#include "Bag.h"
#include <tuple>
#include <vector>

using namespace std;

class Game
{
private:
	Bag bag;
	vector<tuple<int, int, int>> handfuls;

public:
	Game(int id, Bag bag, vector<tuple<int, int, int>> handfuls)
		:bag(bag), handfuls(handfuls)
	{
		this->id = id;
	}

	int id;
	bool IsPossible();
};
