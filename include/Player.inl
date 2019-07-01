bool Player::move(Level &level, Snake &cobra)
{
    int cont = 0;
    int h = level.pos[0];
    int w = level.pos[1];

    int new_h = level.pos[0];
    int new_w = level.pos[1];

    bool flag = true;

    srand (time(nullptr));

    int pos = rand() % 4;

    while( flag )
    {
        if (!level.level[h][w - 1].occupied and pos == 0 and level.last_pos[1] != w - 1) {
            new_h = h;
            new_w = w - 1;

            cont++;
            flag = false;
        }
        if (!level.level[h][w + 1].occupied and pos == 1 and level.last_pos[1] != w + 1) {
            new_h = h;
            new_w = w + 1;

            cont++;
            flag = false;
        }
        if (!level.level[h + 1][w].occupied and pos == 2 and level.last_pos[0] != h + 1) {
            new_h = h + 1;
            new_w = w;

            cont++;
            flag = false;
        }
        if (!level.level[h - 1][w].occupied and pos == 3 and level.last_pos[0] != h - 1) {
            new_h = h - 1;
            new_w = w;

            cont++;
            flag = false;
        }

        pos = rand() % 4;
    }

    std::cout << cont;

    if(cont == 0)
        return false;

    level.level[h][w].block = " ";
    level.level[h][w].occupied = false;

    level.set(u8"*", new_h, new_w);

    level.last_pos = level.pos;

    level.pos[0] = new_h;
    level.pos[1] = new_w;

    return true;
}