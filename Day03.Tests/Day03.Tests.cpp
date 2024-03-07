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
		return std::vector<Position>(8);
	}
};

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

	};

}