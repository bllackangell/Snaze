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
    pos[0] = -1;
    pos[1] = -1;
    apple.resize(2);
    apple[0] = -1;
    apple[1] = -1;
    last_pos.resize(2);
    last_pos[0] = -1;
    last_pos[1] = -1;
    body.resize(1);


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
        do {
            x = rand() % h;
            y = rand() % w;
        }while((x > apple[0] + 5 or x < apple[0] - 5 ) and (y > apple[1] + 5 or y < apple[1] - 5 ));
        //x = 10, y = 7;

    }while(level[x][y].occupied);

    level[x][y].block = 'A';
    apple[0] = x;
    apple[1] = y;

}