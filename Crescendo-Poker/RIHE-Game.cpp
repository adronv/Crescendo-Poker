
#include "RIHE-Game.h"


RIHE_Game::RIHE_Game() {

	int counter = 0;

	deck.resize(52);

	for (unsigned int i = 1; i < 4; ++i) {
		for (int j = 2; j < 14; ++j) {
			deck[counter] = card{ i, j };
			++counter;
		}
	}

	pot_size = 0;

	card_counter = 0;



}

void RIHE_Game::shuffle_deck()
{

	for (int i = 0; i < deck.size(); ++i) {

		int rand_num = rand() % (deck.size() - i + 1);

		card holder = deck[rand_num];
		deck[rand_num] = deck[i];
		deck[i] = holder;

	}
}

card RIHE_Game::deal_card()
{
	++card_counter;
	return deck[card_counter];
}
