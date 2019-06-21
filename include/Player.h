#ifndef PLAYER_H
#define PLAYER_H

#include <random>   // std::default_random_engine, std::uniform_int_distribution.
#include <chrono>
#include "SnakeGame.h"
class Player
{
private:

    int snake_pos[2];
//TODO

public:
	Player() = default;
	~Player() = default;

	bool find_solution(); ///Random Solution

//	Direction next_move(); //TODO DIRECTION COULD BE AN STACK(?) THA ALLOWS REMOVING FROM BOTH END AND BEGIN
};

#include "Player.inl"

#endif //PLAYER_H