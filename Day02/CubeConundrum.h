#pragma once
#include <vector>
#include "Game.h"
class CubeConundrum
{
private:
    std::vector<Game> allGames;
public:
    CubeConundrum(std::vector<Game> allGames)
        :allGames(allGames){}

    int Score();
};
