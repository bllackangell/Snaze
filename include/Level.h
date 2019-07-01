#ifndef LEVEL_H
#define LEVEL_H

#include "SnakeGame.h"

struct Block
{
	char block;  //!< Char saved
	bool occupied;      //!< Saves if block is empty or not



	//=== CONSTRUCTORS ===\\



	//!< Basic constructor
	Block();


	//!< Construct based on a string
	explicit Block(char other);
};

class Level
{
public:

	std::vector<std::vector<Block>> level; //!< Matrix of levels
    std::vector<int> pos;                  //!< Snake position
    std::vector<int> apple;                //!< Apple position
    std::vector<int> last_pos;             //!< Snake Head last position
	int h, w;                              //!< Level Height and width
    std::vector<coord> body;

public:
	//=== CONSTRUCTORS ===\\



	//!< Basic constructor
	Level();



	//=== DESTRUCTOR ===\\



	//!< Basic destructor
	~Level() = default;



	//=== METHODS ===\\



	//!< Resizes level
	void init(int H, int W);


	//!< Sets char on a block in level
	void set(char c , int H, int W);


    //!< Sets empty char on a block in level
	void set_empty(char c , int H, int W);


	//!< Returns char in block on pos(h,w)
    char element(int H, int W);


    //!< Returns level height
    int height();


    //!< Returns level width
    int width();


    //!< Set apple on level
    void set_apple();


    //!< Prints levels
    friend std::ostream& operator<<(std::ostream& os, Level lvl )
    {
        std::string aux; //Used an aux string 'cause if i send block directly to os, on windows the cmd screen displays a flickering behavior

        for (int i = 0; i < lvl.height(); ++i) {
            for (int j = 0; j < lvl.width(); ++j)
            {
                aux.push_back(lvl.element(i, j));
            }
            aux.push_back('\n');
        }

        os << aux;

        return os;
    }
};

#include"Level.inl"

#endif //LEVEL_H