#pragma once

#include <vector>
#include <iostream>
#include <random>
#include "Player.h"
#include "ChickenYard.h"

class Game
{
	private:
		std::vector<Player> players;
		ChickenYard * boneYard;
		bool hasBones;
		int &leadPlayer; // store the players with a number, use a ref.

	public:
		Game();
		Game(std::vector<Player> &players, ChickenYard * yard);
		Game(const Game &);
		Game& operator=(const Game &);
		~Game();

		void gameStart();
		void getLeadPlayer(int &);
		void setLeadPlayer(int &); // get the player no as a ref from player obj

		void playRound();
		void getRoundResults();


};
