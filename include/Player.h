#ifndef PLAYER_H
#define PLAYER_H

#include <random>   // std::default_random_engine, std::uniform_int_distribution.
#include <chrono>
#include "Level.h"
#include "SnakeGame.h"
class Player
{
public:
    int life;

public:
	Player() = default;
	~Player() = default;

    bool move(Level &level, Snake &cobra); ///Random Solution

//	Direction next_move(); //TODO DIRECTION COULD BE AN STACK
};

#include "Player.inl"

#endif //PLAYER_H