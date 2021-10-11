#pragma once


#include "RIHE-Player.h"

#include <stdint.h>
#include <vector>
#include <random>

typedef struct bit_field {
	unsigned long long face_value : 15;
	unsigned long long face_count : 60;
} bit_field;


class RIHE_Game {

	private:

		std::vector<card> deck;
		std::vector<struct card> community_cards;
		int pot_size;
		int card_counter;

		RIHE_Player player_one;
		RIHE_Player player_two;

		std::mt19937_64 sys_rng;

	
	enum hand_rankings {
		HIGH_CARD,
		PAIR,
		FLUSH,
		STRAIGHT,
		TRIPS,
		STRAIGHT_FLUSH
	};

	enum face_position {
		JACK = 11,
		QUEEN,
		KING,
		ACE		
	};

	/*
	enum count_position {
		TWO = 8,
		THREE = 12,
		FOUR = 16,
		FIVE = 20,
		SIX = 24,
		SEVEN = 28,
		EIGHT = 32,
		NINE = 36,
		TEN = 40,
		JACK = 44,
		QUEEN = 48,
		KING = 52,
		ACE = 56
	};
	*/


	public:

		RIHE_Game();
	
	uint64_t tick_face(uint64_t bitfield, uint64_t position) {
		
		int mask = 1 << position;
		return ((bitfield & ~mask) | (1ULL << position));

	}

	uint64_t tick_count(uint64_t bitfield, int position) {

		for (int i = 0; i < 3; ++i) {

			if (!is_set(bitfield, position + i)) {
				int mask = 1 << (position + i);
				return ((bitfield & ~mask) | (1ULL << position + i));
			}
		}

	}

	bool is_set(uint64_t bitfield, int position) {

		int helper = bitfield >> (position - 1);

		return (helper & 1);
	}

	void shuffle_deck();

	card deal_card();

	


	void RIHE_loop(RIHE_Player& pone, RIHE_Player& ptwo) {

		//SET DECK
		shuffle_deck();

		//DEAL HANDS

		pone.set_hand(deal_card());
		ptwo.set_hand(deal_card());

		//FIRST BETTING ROUND




		//FLOP CARD


		//SECOND BETTING ROUND


		//TURN CARD


		//FINAL BETTER ROUND


		//SHOWDOWN







			
	}





};