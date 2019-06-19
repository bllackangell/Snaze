#ifndef LEVEL_H
#define LEVEL_H

#include "SnakeGame.h"

struct Block
{
	char block;

	bool occupied;

	Block();

	Block(char other);
};

class Level
{
private:

	std::vector<std::vector<Block>> level;

public:
	//=== CONSTRUCTORS ===\\



	Level() = default;


	Level(std::string file); //TODO



	//=== DESTRUCTOR ===\\



	~Level() = default;



	//=== METHODS ===\\



	void init(const int H, const int W);

	std::vector<std::vector<Block>> Maze();


	void set( char c , int H, int W);


    friend std::ostream& operator<<(std::ostream& os, Level lvl)
    {
        for (int i = 0; i < lvl.level.size(); ++i)
        {
            for (int j = 0; j < lvl.level[i].size(); ++j)
            {
                os << lvl.level[i][j].block;
            }
        }

        return os;
    }
};

#include"Level.inl"

#endif //LEVEL_H