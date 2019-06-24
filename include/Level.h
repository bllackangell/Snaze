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

	std::vector<std::vector<Block>> level; //!< Matrix of levels
	int snake_pos[2];

public:
	//=== CONSTRUCTORS ===\\



	Level() = default;



	//=== DESTRUCTOR ===\\



	~Level() = default;



	//=== METHODS ===\\



	void init(const int H, const int W);

	std::vector<std::vector<Block>> Maze();


	void set( char c , int H, int W);


	void set_empty( char c , int H, int W);


	//!< Prints levels
    friend std::ostream& operator<<(std::ostream& os, std::vector<Level> lvl)
    {
        for (int k = 0; k < lvl.size(); ++k) {
            for (int i = 0; i < lvl[k].level.size(); ++i) {
                for (int j = 0; j < lvl[k].level[i].size(); ++j) {
                    os << lvl[k].level[i][j].block;
                }
            }
        }
        return os;
    }


    int *pos();
};

#include"Level.inl"

#endif //LEVEL_H