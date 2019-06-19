#ifndef PLAYER_H
#define PLAYER_H

#include "SnakeGame.h"
class Player
{
private:

//TODO

public:
	Player() = default;
	~Player() = default;

	bool find_solution();

//	Direction next_move(); //TODO DIRECTION COULD BE AN STACK(?) THA ALLOWS REMOVING FROM BOTH END AND BEGIN
};

#endif //PLAYER_H