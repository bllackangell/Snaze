#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeGame.h"

class Snake
{
public:
	std::string snake = "*";

	int lives;

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