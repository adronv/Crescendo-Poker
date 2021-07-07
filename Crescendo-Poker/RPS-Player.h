#pragma once

class Player {


public: 

	Player() {};

	enum actions {
		ROCK,
		PAPER,
		SCISSORS,
		ACTION_COUNT
	};


	std::array<double, ACTION_COUNT> action_probabilities = { 0.45, 0.15, 0.40 };
	std::array<double, ACTION_COUNT> regret_sum = { 0.0, 0.0, 0.0 };
	std::array<double, ACTION_COUNT> strategy_sum = { 0.0, 0.0, 0.0 };
	std::array<double, ACTION_COUNT> average_strategy = { 0.45, 0.15, 0.40 };
	


};