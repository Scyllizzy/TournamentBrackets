#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Player.h"
#include "TournamentBrackets.h"
#include <algorithm>

using namespace std;

Player determineWinner(std::vector<Player>& players) {
	vector<Player> game1Winners;
	vector<Player> game2Winners;
	Player game3Winner;

	cout << "Let the games begin!" << endl << endl;

	//////////////////GAME 1//////////////////
#pragma region Game1

	cout << "---------FIRST GAME---------" << endl;

	// Pair 1
	cout << endl << "FIRST PAIR:" << endl;

	cout << "------------" << endl;
	cout << players.at(0).name << " | " << players.at(0).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << players.at(1).name << " | " << players.at(1).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	if (players.at(0).gameScore1 >= players.at(1).gameScore1) {
		game1Winners.push_back(players.at(0));
	}
	else {
		game1Winners.push_back(players.at(1));
	}

	cout << "                   Winner: " << game1Winners.at(0).name << endl;

	// Pair 2
	cout << endl << "SECOND PAIR:" << endl;

	cout << "------------" << endl;
	cout << players.at(2).name << " | " << players.at(2).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << players.at(3).name << " | " << players.at(3).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	if (players.at(2).gameScore1 >= players.at(3).gameScore1) {
		game1Winners.push_back(players.at(2));
	}
	else {
		game1Winners.push_back(players.at(3));
	}

	cout << "                   Winner: " << game1Winners.at(1).name << endl;

	// Pair 3
	cout << endl << "THIRD PAIR:" << endl;

	cout << "------------" << endl;
	cout << players.at(4).name << " | " << players.at(4).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << players.at(5).name << " | " << players.at(5).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	if (players.at(4).gameScore1 >= players.at(5).gameScore1) {
		game1Winners.push_back(players.at(4));
	}
	else {
		game1Winners.push_back(players.at(5));
	}

	cout << "                   Winner: " << game1Winners.at(2).name << endl;

	// Pair 4
	cout << endl << "FOURTH PAIR:" << endl;

	cout << "------------" << endl;
	cout << players.at(6).name << " | " << players.at(6).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << players.at(7).name << " | " << players.at(7).gameScore1 << " | " << endl;
	cout << "------------" << endl;

	if (players.at(6).gameScore1 >= players.at(7).gameScore1) {
		game1Winners.push_back(players.at(6));
	}
	else {
		game1Winners.push_back(players.at(7));
	}

	cout << "                   Winner: " << game1Winners.at(3).name << endl;
#pragma endregion

	//////////////////GAME 2//////////////////
#pragma region Game2
	
	cout << "---------SECOND GAME---------" << endl;

	// Pair 1
	cout << endl << "FIRST PAIR:" << endl;

	cout << "------------" << endl;
	cout << game1Winners.at(0).name << " | " << game1Winners.at(0).gameScore2 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << game1Winners.at(1).name << " | " << game1Winners.at(1).gameScore2 << " | " << endl;
	cout << "------------" << endl;

	if (game1Winners.at(0).gameScore2 >= game1Winners.at(1).gameScore2) {
		game2Winners.push_back(game1Winners.at(0));
	}
	else {
		game2Winners.push_back(game1Winners.at(1));
	}

	cout << "                   Winner: " << game2Winners.at(0).name << endl;

	// Pair 2
	cout << endl << "SECOND PAIR:" << endl;

	cout << "------------" << endl;
	cout << game1Winners.at(2).name << " | " << game1Winners.at(2).gameScore2 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << game1Winners.at(3).name << " | " << game1Winners.at(3).gameScore2 << " | " << endl;
	cout << "------------" << endl;

	if (game1Winners.at(2).gameScore2 >= game1Winners.at(3).gameScore2) {
		game2Winners.push_back(game1Winners.at(2));
	}
	else {
		game2Winners.push_back(game1Winners.at(3));
	}

	cout << "                   Winner: " << game2Winners.at(1).name << endl;

#pragma endregion

	//////////////////GAME 3//////////////////
#pragma region Game3

	cout << "---------THIRD GAME---------" << endl;

	// Final pair
	cout << endl << "FINAL PAIR:" << endl;

	cout << "------------" << endl;
	cout << game2Winners.at(0).name << " | " << game2Winners.at(0).gameScore3 << " | " << endl;
	cout << "------------" << endl;

	cout << "------------" << endl;
	cout << game2Winners.at(1).name << " | " << game2Winners.at(1).gameScore3 << " | " << endl;
	cout << "------------" << endl;

	if (game2Winners.at(0).gameScore3 >= game2Winners.at(1).gameScore3) {
		game3Winner = game2Winners.at(0);
	}
	else {
		game3Winner = game2Winners.at(1);
	}

	cout << "                   Winner: " << game3Winner.name << endl;

#pragma endregion

	return game3Winner;
}

int main() {
	srand(time(0));

	string text;
	vector<string> fileText;
	vector<Player> players;

	ifstream inFile("tournament.txt", ios::in);

	// In case there is no file to be read...
	if (!inFile) {
		cout << "Unable to open file";
		exit(1);
	}

	// Grabbing all the contents in the file
	while (inFile >> text) {
		fileText.push_back(text);
	}

	addPlayersToVector(fileText, players);

	Player winner = determineWinner(players);

	cout << endl << "WINNER: " << winner.name << endl;

	inFile.close();

	return 0;
}

/// <summary>
/// Puts player information from fileText into Player object and adds those players to a vector.
/// </summary>
/// <param name="fileText">List of player information.</param>
/// <param name="players">Vector for players to be put in.</param>
void addPlayersToVector(std::vector<std::string>& fileText, std::vector<Player>& players)
{
	// For the for loop below
	int playersIndex = -1;

	// Add names and scores to the Player class
	for (int i = 0; i < fileText.size(); i++) {
		if (i % 4 == 0) {
			Player newPlayer;
			players.push_back(newPlayer);
			playersIndex++;
		}

		switch (i % 4)
		{
		case 0:
			players.at(playersIndex).name = fileText.at(i);
			break;
		case 1:
			players.at(playersIndex).gameScore1 = stoi(fileText.at(i));
			break;
		case 2:
			players.at(playersIndex).gameScore2 = stoi(fileText.at(i));
			break;
		case 3:
			players.at(playersIndex).gameScore3 = stoi(fileText.at(i));
			break;
		default:
			cout << "case failed.";
			break;
		}
	}

	// Add random numbers for player position
	for (int i = 0; i < players.size(); i++) {
		players.at(i).randPosition = rand() % players.size();
	}

	sort(players.begin(), players.end());
}
