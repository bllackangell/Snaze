class Snake
{
private:
	std::string snake;

	int apples_eaten;

	friend SnakeGame;

public:
	Snake(char head)
	{
		snake = head;

		apples_eaten = 0;
	}

	~Snake()
	{
		/* EMPTY */
	}
};