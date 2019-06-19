Block::Block()
{
	block = ' ';
	occupied = false;
}


Block::Block(char other)
{
	block = other;
	occupied = true;
}


Level::Level(std::string file)
{
	//TODO
}


void Level::init(const int H, const int W)
{
    level.resize(W);

    for (int i = 0; i < W; i++)
    {
        level[i].resize(H);
    }
}


std::vector<std::vector<Block>> Level::Maze()
{
	return level;
}


void Level::set( char c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = true;
}