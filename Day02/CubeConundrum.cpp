#include "CubeConundrum.h"

int CubeConundrum::Score()
{
    auto result = 0;

    for (auto game : allGames)
    {
        if (game.IsPossible())
            result += game.id;
    }

    return result;
}
