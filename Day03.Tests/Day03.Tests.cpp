#include "pch.h"
#include "CppUnitTest.h"

#include <tuple>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Position = std::tuple<int, int>;

static class qweda
{
public:
    static std::vector<Position> AdjacentTo(Position aPosition)
    {
        std::vector<Position> result = {
            Position(std::get<0>(aPosition) - 1, std::get<1>(aPosition)),
            Position(std::get<0>(aPosition), std::get<1>(aPosition) - 1),
            Position(std::get<0>(aPosition) + 1, std::get<1>(aPosition)),
            Position(std::get<0>(aPosition), std::get<1>(aPosition) + 1),
            Position(std::get<0>(aPosition) - 1, std::get<1>(aPosition) - 1),
            Position(std::get<0>(aPosition) + 1, std::get<1>(aPosition) + 1),
            Position(std::get<0>(aPosition) - 1, std::get<1>(aPosition) + 1),
            Position(std::get<0>(aPosition) + 1, std::get<1>(aPosition) - 1),
        };

        return result;
    }
};

std::vector<Position> AdjacentToNumber(std::tuple<Position, int> aNumber)
{
    auto digits = std::to_string(std::get<1>(aNumber)).length();
    auto initialPosition = std::get<0>(aNumber);
    auto result = std::vector<Position>();

    for (int i = 0; i < digits; i++)
    {
        auto currentPosition = Position(std::get<0>(initialPosition) + i, std::get<1>(initialPosition));
        
        for (auto asfas : qweda::AdjacentTo(currentPosition))
        {
            result.push_back(asfas);
        }
    }

    return result;
}

bool ContainsIn(std::vector<Position> from, Position whichOne)
{
    for (auto position : from)
    {
        if (position == whichOne)
            return true;
    }

    return false;
}

bool IsPartNumber(std::tuple<Position, int> candidate, Position whereASymbolIs)
{
    return ContainsIn(qweda::AdjacentTo(std::get<0>(candidate)), whereASymbolIs);
}

namespace Day03Tests
{
    TEST_CLASS(Day03Tests)
    {
    public:

        // Objetivo: Suma de todos los PartNumber
        // - �Qu� es un PartNumber?
        // -- Es un n�mero adyacente a un s�mbolo
        // --- Qu� es un s�mbolo?
        // ----	Es cualquier car�cter distinto de . o un n�mero
        // - �Qu� es un n�mero?
        // -- Varios d�gitos unidos horizontalmente (sin otros s�mbolos entre ellos)
        // - �Qu� es ser adyacente?
        // -- Es estar en una casilla contigua vertical, horizontal o diagonalmente (1 unidad de distancia)

        TEST_METHOD(AdjacentPosition)
        {
            Position expected = Position(0, 1);
            Assert::IsTrue(qweda::AdjacentTo(Position(0, 0)).size() == 8);
        }

        TEST_METHOD(ContainsAdjacentPosition)
        {
            Assert::IsTrue(ContainsIn(qweda::AdjacentTo(Position(0, 0)), Position(0, 1)));
            Assert::IsTrue(ContainsIn(qweda::AdjacentTo(Position(4, 4)), Position(3, 4)));
            Assert::IsTrue(ContainsIn(qweda::AdjacentTo(Position(6, 5)), Position(7, 6)));
        }

        TEST_METHOD(SingleDigitNumber_IsPartNumber)
        {
            Assert::IsTrue(IsPartNumber(std::tuple<Position, int>(Position(0, 0), 5), Position(1, 0)));
            Assert::IsFalse(IsPartNumber(std::tuple<Position, int>(Position(43, 20), 5), Position(1, 0)));
        }

        TEST_METHOD(AdjacentsToMultipleDigitNumber)
        {
            Assert::IsTrue(AdjacentToNumber(std::tuple<Position, int>(Position(2, 0), 40)).size() == 16);
            Assert::IsTrue(AdjacentToNumber(std::tuple<Position, int>(Position(2, 0), 3)).size() == 8);
        }

        TEST_METHOD(MultipleDigitNumber_IsPartNumber)
        {
            Assert::IsTrue(IsPartNumber(std::tuple<Position, int>(Position(0, 0), 53), Position(2, 0)));
        }
    };
}