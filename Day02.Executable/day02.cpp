#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "../Day02/CubeConundrum.h"
#include "../Day02/Game.h"

using std::ifstream;
using std::vector;
using Handful = std::tuple<int, int, int>;

Handful DecodeHandfulString(string& input)
{
	int r = 0, g = 0, b = 0;

	size_t redPos = input.find("red");
	size_t greenPos = input.find("green");
	size_t bluePos = input.find("blue");

	if (redPos != string::npos)
	{
		size_t prevSpacePos = input.rfind(" ", redPos - 2);
		string number = {};
		if (prevSpacePos == string::npos)
		{
			number = input.substr(0, redPos - 1);
		}
		else
		{
			number = input.substr(prevSpacePos, redPos - prevSpacePos);
		}
		r = stoi(number);
	}

	if (greenPos != string::npos)
	{
		size_t prevSpacePos = input.rfind(" ", greenPos - 2);
		string number = {};
		if (prevSpacePos == string::npos)
		{
			number = input.substr(0, greenPos - 1);
		}
		else
		{
			number = input.substr(prevSpacePos, greenPos - prevSpacePos);
		}
		g = stoi(number);
	}

	if (bluePos != string::npos)
	{
		size_t prevSpacePos = input.rfind(" ", bluePos - 2);
		string number = {};
		if (prevSpacePos == string::npos)
		{
			number = input.substr(0, bluePos - 1);
		}
		else
		{
			number = input.substr(prevSpacePos, bluePos - prevSpacePos);
		}
		b = stoi(number);
	}

	Handful result = {r, g, b};
	return result;
}

int main()
{
	//ifstream infile("example01.txt");
	//ifstream infile("example02.txt");
	ifstream infile("input.txt");
	string line;

	Bag bag = Bag(12, 13, 14);

	vector<Game> allGames = vector<Game>();

	while (getline(infile, line))
	{
		vector<Handful> handfuls = vector<Handful>();
		int id = {};

		size_t a = line.find(" ");
		size_t b = line.find(":");
		id = stoi(line.substr(a + 1, b));

		line.erase(0, b + 2);

		while (line.length() > 0)
		{
			size_t spacer = line.find(";");
			string handfulString = line.substr(0, spacer);
			line.erase(0, spacer + 2);
			
			handfuls.push_back(DecodeHandfulString(handfulString));

			if (spacer == string::npos)
			{
				break;
			}
		}

		Game game = Game(id, bag, handfuls);
		allGames.push_back(game);
	}

	CubeConundrum conundrum(allGames);
	cout << "Cube Conundrum Score = " << conundrum.Score();
}
