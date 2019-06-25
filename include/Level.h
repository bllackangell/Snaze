#ifndef LEVEL_H
#define LEVEL_H

#include "SnakeGame.h"

struct Block
{
	const char *block;

	bool occupied;

	Block();

	explicit Block(const char *other);
};

class Level
{
public:

	std::vector<std::vector<Block>> level; //!< Matrix of levels
	int h, w;
	int snake_pos[2];
	const char *apple;

public:
	//=== CONSTRUCTORS ===\\



	Level();



	//=== DESTRUCTOR ===\\



	~Level() = default;



	//=== METHODS ===\\



	void init(int H, int W);

	std::vector<std::vector<Block>> Maze();


	void set( const char *c , int H, int W);


	void set_empty( const char *c , int H, int W);


    int *pos();


    char element(int H, int W);


    int height();


    int width();


    //!< Prints levels
    friend std::ostream& operator<<(std::ostream& os, Level lvl )
    {
        for (int i = 0; i < lvl.height(); ++i) {
            for (int j = 0; j < lvl.width(); ++j)
            {
                os << lvl.element(i, j);
            }
            os << std::endl;
        }

        return os;
    }
};

#include"Level.inl"

#endif //LEVEL_H