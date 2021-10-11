// Crescendo-Poker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RPS-Solver.h"
#include "RIHE-Game.h"

int main()
{

    Player player_one = Player();
    Player player_two = Player();

    RPS_Solver solver = RPS_Solver(player_one, player_two);

    solver.solve_RPS(10000);

    /*---------------------------------------------------------------------------------------------*/

    RIHE_Game rihg = RIHE_Game();
    bit_field bf = { 0,0 };

    uint64_t face = rihg.tick_face(bf.face_value, 11);

    std::cout << bf.face_count << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
