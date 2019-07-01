#ifndef PLAYER_H
#define PLAYER_H

#include <random>   // std::default_random_engine, std::uniform_int_distribution.
#include <chrono>
#include "Level.h"
#include "SnakeGame.h"
class Player
{
public:
	Player() = default;
	~Player() = default;



	//=== METHODS ===\\


    //!< Random Solution
    bool move(Level &level, Snake &cobra);

    //!< Tries to find a way to apple, if there's none do random movements
	bool solution(Level &level, Snake &cobra);
};

#include "Player.inl"

#endif //PLAYER_H