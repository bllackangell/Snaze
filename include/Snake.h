#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeGame.h"

class Snake
{
public:
	std::string snake = "*"; //!< Snake head
	int lives;               //!< Snake lives
	int apples_eaten;        //!< Number of apples eaten

public:



    //=== CONSTRUCTORS ===\\


    /// Basic constructor
    Snake();



    //=== DESTRUCTORS ===\\



    /// Basic constructor
    ~Snake() = default;



    //=== METHODS ===\\



    /// Returns number of apples eaten
	int eaten();


    /// Increase snake size
	void operator++();


	/// Change snake size to 1 and set head
	void clear();
};

#include "Snake.inl"

#endif //SNAKE_H