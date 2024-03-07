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
			Position(0, 1),
			Position(0, 1),
			Position(0, 1),
			Position(0, 1),
			Position(0, 1),
			Position(0, 1),
			Position(0, 1),
		};



		return result;
	}
};

namespace Day03Tests
{
	TEST_CLASS(Day03Tests)
	{
	public:

		// Objetivo: Suma de todos los PartNumber
		// - ¿Qué es un PartNumber?
		// -- Es un número adyacente a un símbolo
		// --- Qué es un símbolo?
		// ----	Es cualquier carácter distinto de . o un número
		// - ¿Qué es un número?
		// -- Varios dígitos unidos horizontalmente (sin otros símbolos entre ellos)
		// - ¿Qué es ser adyacente?
		// -- Es estar en una casilla contigua vertical, horizontal o diagonalmente (1 unidad de distancia)

		bool ContainsIn(std::vector<Position> from, Position whichOne)
		{
			for (auto position : from)
			{
				if (position == whichOne)
					return true;
			}

			return false;
		}

		TEST_METHOD(AdjacentPosition)
		{
			Position expected = Position(0, 1);
			Assert::IsTrue(qweda::AdjacentTo(Position(0, 0)).size() == 8);
		}

		TEST_METHOD(ContainsAdjacentPosition)
		{
			Assert::IsTrue(ContainsIn(qweda::AdjacentTo(Position(0, 0)), Position(0, 1)));
			
			Assert::IsTrue(ContainsIn(qweda::AdjacentTo(Position(4, 4)), Position(3, 4)));
		}
	};

}