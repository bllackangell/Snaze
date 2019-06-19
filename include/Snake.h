#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeGame.h"

class Snake
{
private:
	std::string snake;

	int apples_eaten;

public:
	Snake();

	int eaten();

	void operator++();

	void clear();

	~Snake() = default;
};

#include "Snake.inl"

#endif //SNAKE_H