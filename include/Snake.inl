//=== CONSTRUCTORS ===\\



Snake::Snake()
{
    snake.assign("*");

    lives = 10;

    apples_eaten = 0;
}



//=== METHODS ===\\



int Snake::eaten()
{
    return apples_eaten;
}


void Snake::operator++()
{
    snake.append("*");
}


void Snake::clear()
{
    snake.assign("*");
}