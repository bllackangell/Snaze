//=== CONSTRUCTORS ===\\



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


//= LEVEL CLASS =\\


//=== CONSTRUCTORS ===\\



Level::Level()
{
    pos.resize(2);
    apple.resize(2);
    last_pos.resize(2);
    body.resize(1);
    last_pos[0] = -1;
    last_pos[1] = -1;

    h = 0;
    w = 0;
}



//=== METHODS ===\\



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


void Level::set(char c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = true;
}


void Level::set_empty(char c , int H, int W)
{
    level[H][W].block = c;
    level[H][W].occupied = false;
}


char Level::element(int H, int W)
{
    return level[H][W].block;
}


int Level::height()
{
    return h;
}


int Level::width()
{
    return w;
}


void Level::set_apple()
{
    srand(time(nullptr));

    int x, y;

    do{

        x = rand() % h;
        y = rand() % w;
        //x = 10, y = 7;

    }while(level[x][y].occupied);

    level[x][y].block = 'A';
    apple[0] = x;
    apple[1] = y;

}