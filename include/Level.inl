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
    pos.resize(2);
    apple.resize(2);
    last_pos.resize(2);
    last_pos[0] = -1;
    last_pos[1] = -1;

    h = 0;
    w = 0;
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


void Level::set( const char *c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = true;
}


void Level::set_empty( const char *c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = false;
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