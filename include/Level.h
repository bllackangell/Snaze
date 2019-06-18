struct Block
{
	char block;

	bool occupied;

	Block()
	{
		block = NULL;
		occupied = false;
	}

	Block(char other, bool is)
	{
		block = other;
		occupied = true;
	}
};

class Level
{
private:

	std::vector<std::vector<Block>> maze;

	friend SnakeGame;

public:

	Level(std::string file)
	{
		//TODO
	}

	~Level(){/*EMPTY*/};

	//overload << operator
;
}