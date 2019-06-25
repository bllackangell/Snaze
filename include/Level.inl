Block::Block()
{
    char c = ' ';
	block = &c;
	occupied = false;
}


Block::Block(const char *other)
{
	block = other;
	occupied = true;
}


Level::Level()
{
    h = 0;
    w = 0;
    snake_pos[0] = 0;
    snake_pos[1] = 0;
    apple = u8"\u1F34E";
}


void Level::init(int H, int W)
{
    h = H;
    w = W;

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


void Level::set( const char *c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = true;

    char s = '*';
    if(c == &s)
    {
        snake_pos[0] = H;
        snake_pos[1] = W;
    }

}


void Level::set_empty( const char *c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = false;
}


int *Level::pos()
{
    return snake_pos;
}


char Level::element(int H, int W)
{
    return *level[H][W].block;
}


int Level::height()
{
    return h;
}


int Level::width()
{
    return w;
}