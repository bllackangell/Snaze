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


void Level::init(const int H, const int W)
{
    level.resize(H);

    for (int i = 0; i < H; i++)
    {
        level[i].resize(W);
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

    if(c == '*')
    {
        snake_pos[0] = H;
        snake_pos[1] = W;
    }

}


void Level::set_empty( char c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = false;


}


int *Level::pos()
{
    return snake_pos;
}