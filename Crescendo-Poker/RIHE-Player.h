#pragma once

typedef struct card {
	unsigned int suit;
	int value;
} card;

class RIHE_Player {

private:

	int chip_count;
	card player_hand;
	bool first_action;

public:

	void set_hand(card new_card) { player_hand = new_card };




};