//=== METHODS ===\\



bool Player::move(Level &level, Snake &cobra)
{
    int h = level.pos[0];
    int w = level.pos[1];

    bool l = false;
    bool r = false;
    bool u = false;
    bool d = false;

    int new_h = level.pos[0];
    int new_w = level.pos[1];

    bool flag = true;

    srand (time(nullptr));
    //srand (2);

    int pos = rand() % 4;

    while( flag )
    {
        if (pos == 0 and l != true)         /// left
        {
            if(level.last_pos[1] != w - 1 and !level.level[h][w - 1].occupied) {
                new_h = h;
                new_w = w - 1;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                l = true;
            if(r == true and u == true and d == true)
            {
                return false;
            }
        }
        else if (pos == 1 and r != true)    /// right
        {
            if(level.last_pos[1] != w + 1 and !level.level[h][w + 1].occupied) {
                new_h = h;
                new_w = w + 1;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                r = true;
            if(l == true and u == true and d == true)
            {
                return false;
            }
        }
        else if (pos == 2 and d != true)    /// down
        {
            if(level.last_pos[0] != h + 1 and !level.level[h + 1][w].occupied) {
                new_h = h + 1;
                new_w = w;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                d = true;
            if(l == true and r == true and u == true)
            {
                return false;
            }
        }
        else if (pos == 3 and u != true)    /// up
        {
            if(level.last_pos[0] != h - 1 and !level.level[h - 1][w].occupied) {
                new_h = h - 1;
                new_w = w;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else {
                u = true;
            }
            if(l == true and r == true and d == true)
            {
                return false;
            }
        }

        pos = rand() % 4;
    }

    level.set_empty(' ', h, w);

    level.set('*', new_h, new_w);

    level.last_pos = level.pos;

    level.pos[0] = new_h;   //TODO make block have coord
    level.pos[1] = new_w;

    return true;
}



bool Player::solution(Level &level, Snake &cobra)
{
    int h = level.pos[0];
    int w = level.pos[1];

    int x = level.apple[0];
    int y = level.apple[1];

    bool l = false;
    bool r = false;
    bool u = false;
    bool d = false;

    int new_h = level.pos[0];
    int new_w = level.pos[1];

    bool flag = true;

    int pos = rand() % 4;

    while( flag )
    {
        if ((pos == 0 || y < w) and l != true)         /// left
        {
            if(level.last_pos[1] != w - 1 and !level.level[h][w - 1].occupied) {
                new_h = h;
                new_w = w - 1;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                l = true;
            if(r == true and u == true and d == true)
            {
                return false;
            }
        }
        if ((pos == 1 || y > w) and r != true)    /// right
        {
            if(level.last_pos[1] != w + 1 and !level.level[h][w + 1].occupied) {
                new_h = h;
                new_w = w + 1;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                r = true;
            if(l == true and u == true and d == true)
            {
                return false;
            }
        }
        if ((pos == 2 || x > h) and d != true)    /// down
        {
            if(level.last_pos[0] != h + 1 and !level.level[h + 1][w].occupied) {
                new_h = h + 1;
                new_w = w;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else
                d = true;
            if(l == true and r == true and u == true)
            {
                return false;
            }
        }
        if ((pos == 3 || x < h) and u != true)    /// up
        {
            if(level.last_pos[0] != h - 1 and !level.level[h - 1][w].occupied) {
                new_h = h - 1;
                new_w = w;

                flag = false;
                l = false;
                r = false;
                u = false;
                d = false;
            }
            else {
                u = true;
            }
            if(l == true and r == true and d == true)
            {
                return false;
            }
        }

        pos = rand() % 4;
    }

    if(cobra.snake.size() == 1)
    {
        if (level.level[h][w].block != 'A')
        level.set_empty(' ', h, w);

        level.set('*', new_h, new_w);

        level.last_pos = level.pos;

        level.pos[0] = new_h;   //TODO make block have coord
        level.pos[1] = new_w;

        return true;
    }
    else {
        if (level.level[h][w].block != 'A')
            level.set_empty(' ', h, w);

        level.set('*', new_h, new_w);

        level.last_pos = level.pos;

        level.pos[0] = new_h;   //TODO make block have coord
        level.pos[1] = new_w;

        return true;
    }
}