#pragma once
#include <string>
using namespace std;

class Player
{
	public:
	string name;
	int gameScore1;
	int gameScore2;
	int gameScore3;
	int randPosition;

	bool operator< (const Player & other) const {
		return randPosition < other.randPosition;
	}
};

