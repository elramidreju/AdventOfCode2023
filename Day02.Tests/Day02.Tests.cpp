#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <tuple>
#include "../Day02/Game.h"
#include "../Day02/CubeConundrum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Day02Tests
{
	TEST_CLASS(Day02Tests)
	{
	public:
		
		TEST_METHOD(IsHandful_NotPossible)
		{
			auto sut = Bag();
			Assert::IsFalse(sut.CanPick(1));
		}

		TEST_METHOD(IsHandfulPossible)
		{
			auto sut = Bag(1);
			Assert::IsTrue(sut.CanPick(1));
		}

		TEST_METHOD(IsHandful_NotPossible_WithOtherColor)
		{
			auto sut = Bag(1);
			Assert::IsFalse(sut.CanPick(0, 1));
		}

		TEST_METHOD(IsHandfulPossible_WithOtherColor)
		{
			auto sut = Bag(0, 1);
			Assert::IsTrue(sut.CanPick(0, 1));
		}

		TEST_METHOD(IsHandfulPossible_MoreThanEnough)
		{
			auto sut = Bag(10, 10, 10);
			Assert::IsTrue(sut.CanPick(9, 9, 9));
		}

		TEST_METHOD(IsGamePossible)
		{
			auto doc = Bag(10, 10, 10);
			auto handfuls = std::tuple<int, int, int>(5, 1, 3);
			auto sut = Game(1, doc, { handfuls });

			Assert::IsTrue(sut.IsPossible());
		}

		TEST_METHOD(IsGameImpossible)
		{
			auto doc = Bag(10, 10, 10);
			auto correctHandful = std::tuple<int, int, int>(5, 1, 3);
			auto wrongHandful = std::tuple<int, int, int>(11, 1, 3);
			auto sut = Game(1, doc, { correctHandful, wrongHandful });

			Assert::IsFalse(sut.IsPossible());
		}

		TEST_METHOD(ConundrumOnePossibleGame)
		{
			auto doc = Bag(10, 10, 10);
			auto correctHandful = std::tuple<int, int, int>(5, 1, 3);
			auto game = Game(1, doc, { correctHandful});

			auto sut = CubeConundrum({ game });

			Assert::AreEqual(1, sut.Score());
		}

		TEST_METHOD(ConundrumOnePossibleOneImpossible)
		{
			auto doc = Bag(10, 10, 10);
			auto correctHandful = std::tuple<int, int, int>(5, 1, 3);
			auto possibleGame = Game(2, doc, { correctHandful });

			auto wrongHandful = std::tuple<int, int, int>(50, 10, 30);
			auto impossibleGame = Game(1, doc, { wrongHandful });

			auto sut = CubeConundrum({ possibleGame, impossibleGame });

			Assert::AreEqual(2, sut.Score());
		}

		TEST_METHOD(ConundrumSeveralPossible)
		{
			auto doc = Bag(10, 10, 10);
			auto correctHandful = std::tuple<int, int, int>(5, 1, 3);
			
			auto possibleGame = Game(2, doc, { correctHandful });
			auto anotherPossibleGame = Game(1, doc, { correctHandful });

			auto sut = CubeConundrum({ possibleGame, anotherPossibleGame });

			Assert::AreEqual(3, sut.Score());
		}
	};
}
