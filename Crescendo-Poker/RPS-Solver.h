#pragma once

#include <array>
#include <random>
#include <iostream>
#include "RPS-Player.h"

class RPS_Solver {

public:

	RPS_Solver(Player& one, Player& two);

	int return_action(std::array<double, Player::ACTION_COUNT> probabilities);
	std::array<double, Player::ACTION_COUNT> return_strategy(Player& player);
	std::array<double, Player::ACTION_COUNT> return_avg_strategy(Player& player);
	void set_regret(Player& player_one, Player& player_two);

	void solve_RPS(int iterations);

	double get_rand();

private:

	Player& player_one;
	Player& player_two;

	std::mt19937_64 sys_rng;
	std::uniform_real_distribution<> dist;
		
		
	int action_utilities[Player::ACTION_COUNT][Player::ACTION_COUNT] = {{ 0,  1, -1},
																		{-1,  0,  1},
																		{ 1, -1,  0}};






};