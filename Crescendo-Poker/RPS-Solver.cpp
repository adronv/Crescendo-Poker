#include "RPS-Solver.h"

RPS_Solver::RPS_Solver(Player& one, Player& two) 
	: player_one(one), player_two(two), sys_rng(std::random_device{}()), dist(std::uniform_real_distribution<>(0.0, 1.0))
{}

int RPS_Solver::return_action(std::array<double, Player::ACTION_COUNT> probabilities)
{
	double rand = get_rand();

	double cumulative_probability = 0.0;

	for (int action = 0; action < Player::ACTION_COUNT; ++action) {

		cumulative_probability += probabilities[action];

		if (rand <= cumulative_probability) return action;

	}

}

std::array<double, Player::ACTION_COUNT> RPS_Solver::return_strategy(Player& player)
{
	int regret_sum = 0;

	std::array<double, Player::ACTION_COUNT> new_strategy;

	for (int action = 0; action < Player::ACTION_COUNT; action++) {
		
		new_strategy[action] = (player.regret_sum[action] > 0) ? player.regret_sum[action] : 0;

		regret_sum += new_strategy[action];

	}

	for (int action = 0; action < Player::ACTION_COUNT; action ++) {

		new_strategy[action] =  (regret_sum > 0) ? new_strategy[action] /= regret_sum : new_strategy[action] = 1.0 / Player::ACTION_COUNT;

		player.strategy_sum[action] += new_strategy[action];

	}

	return new_strategy;

}

std::array<double, Player::ACTION_COUNT> RPS_Solver::return_avg_strategy(Player& player)
{
	double regret_sum = 0;

	std::array<double, Player::ACTION_COUNT> avg_strategy;

	for (int action = 0; action < Player::ACTION_COUNT; action++) {

		regret_sum += player.strategy_sum[action];

	}

	for (int action = 0; action < Player::ACTION_COUNT; action++) {

		avg_strategy[action] = (regret_sum > 0) ? player.strategy_sum[action] /= regret_sum : avg_strategy[action] = 1.0 / Player::ACTION_COUNT;

	}

	return avg_strategy;
}


void RPS_Solver::set_regret(Player& player_one, Player& player_Two)
{

	int our_action = return_action(player_one.action_probabilities);

	int	other_action = return_action(player_two.action_probabilities);

	int static_utility = action_utilities[our_action][other_action];

	for (int action = 0; action < Player::ACTION_COUNT; action++) {

		player_one.regret_sum[action] += action_utilities[action][other_action] - static_utility;	

	}

	static_utility = -static_utility;

	for (int action = 0; action < Player::ACTION_COUNT; action++) {

		player_two.regret_sum[action] += action_utilities[action][our_action] - static_utility;

	}

}

void RPS_Solver::solve_RPS(int iterations)
{
	for (int i = 0; i < iterations; ++i) {

		set_regret(player_one, player_two);

		player_one.action_probabilities = return_strategy(player_one);
		
		player_two.action_probabilities = return_strategy(player_two);

	}

	std::cout << return_avg_strategy(player_one)[0] << std::endl;
	std::cout << return_avg_strategy(player_two)[2] << std::endl;
}

double RPS_Solver::get_rand()
{
    return dist(sys_rng);
}
