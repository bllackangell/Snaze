Snake::Snake()
{
    snake.assign(">");

    apples_eaten = 0;
}


int Snake::eaten()
{
    return apples_eaten;
}


void Snake::operator++()
{
    snake.append("-");
}


void Snake::clear()
{
    snake.assign(">");
}