//=== CONSTRUCTORS ===\\



SnakeGame::SnakeGame()
{
    current_level = 0;
	height = 0;
	width = 0;
}



//=== METHODS ===\\



void SnakeGame::initialize_game(int argc, char** argv)
{
	std::string line;
	std::ifstream dat;
	dat.open(*(argv + 1), std::ifstream::in);

	if (!dat.is_open())
	{
		std::cout << "Unable to open file.\n";
		over = true;
	}

    int i = 0;

    while (!dat.eof())
    {
        std::getline(dat, line);
        std::stringstream ss;

        if(line[1] >= 48 and line[1] <= 57)
        {
            i++;
            ss << line;

            std::string temp;
            int found;
            for (int cont = 0; cont < 2; cont++)
            {
                ss >> temp;

                if (std::stringstream(temp) >> found) {

                    levels.resize(i);
                    buffer.resize(i);

                    if (cont == 0) {
                        height = found;
                    }
                    if (cont == 1) {
                        width = found;
                    }
                }
                temp = "";
            }

            levels[i - 1].init(height, width);

            bool headfound = false;

            for (auto l = 0; l < height; l++) {
                std::getline(dat, line);

                for (auto c = 0; c < line.size(); c++) {
                    if (c == width) {
                        break;
                    } else if (line.at(c) == '#') {
                        levels[i - 1].set('#', l, c);
                    } else if (line.at(c) == '.') {
                        levels[i - 1].set(' ', l, c);
                    } else if (line.at(c) == '*') {
                        levels[i - 1].set('*', l, c);
                        levels[i - 1].pos[0] = l;
                        levels[i - 1].pos[1] = c;
                        levels[i - 1].body[0].x = l;
                        levels[i - 1].body[0].y = c;
                        headfound = true;
                    } else {
                        levels[i - 1].set_empty(' ', l, c);
                    }
                }
            }

            if (!headfound) {
                over = true;

                std::cout << "Head not found in maze: " << i;
            }
        }
    }

    buffer = levels;

    for (int j = 0; j < levels.size(); ++j)
    {
        levels[j].set_apple();
    }

	dat.close();
}



void SnakeGame::render_welcome_msg()
{
    if(!game_over())
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n---> Welcome to the classic Snake Game <---\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Levels loaded: " << levels.size() << " | Snake lives: "<< cobra.lives <<" | Apples to eat: 5\n";
        std::cout << "Clear all levels to win the game. Good luck!!!\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Press <ENTER> to start the game!\n";
        std::getline(std::cin, input);
    }
}



void SnakeGame::process_events()
{
    //std::cout << "===PROCESS EVENTS===\n";
    if(!IA.solution(levels[current_level], cobra))
    {
        cobra.lives--;
        cobra.apples_eaten = 0;

        std::cout << "\nYOU DIED!\n\n";
        std::cout << "You have " << cobra.lives << " lives left\n";
        std::cout << "Press <ENTER> to continue!\n";
        std::getline(std::cin, input);

        levels[current_level] = buffer[current_level];
        levels[current_level].set_apple();
    }

}



void SnakeGame::update()
{

    //std::cout << "===UPDATE===\n";
    if(levels[current_level].apple == levels[current_level].pos)
    {
        int x = levels[current_level].apple[0];
        int y = levels[current_level].apple[1];

        cobra.apples_eaten++;

        ++cobra;
        levels[current_level].body.resize(cobra.snake.size() + 1); // To save pos before tail

        int t_x = levels[current_level].last_pos[0];
        int t_y = levels[current_level].last_pos[1];

        //levels[current_level].set("*", t_x, t_y);

        levels[current_level].set_empty(' ', x, y);

        levels[current_level].set_apple();
        //std::cout << "COMI!!\n";
        system("pause");
    }

    if(cobra.eaten() == 5)
    {
        std::cout << "\nEATEN 5 APPLES!\n\n";
        std::cout << "Press <ENTER> to continue!\n";
        std::getline(std::cin, input);
        cobra.apples_eaten = 0;
        cobra.clear();
        current_level++;
    }

    if(cobra.lives == 0)
    {
        std::cout << "\nThanks for playing!\n";
        over = true;
    }

    if(current_level >= levels.size())
    {
        std::cout << "\nCONGRATULATIONS YOU BEAT THE GAME!!!\n\n";
        std::cout << "Press <ENTER> to continue!\n";
        std::getline(std::cin, input);
        over = true;
    }
}



void SnakeGame::render()
{
    //std::cout << "===RENDER===";
    if(!over) {

        std::cout << "Level loaded: " << current_level + 1 << " | Snake lives: " << cobra.lives
                  << " | Apples to eat: 5 | Apples eaten: " << cobra.apples_eaten << "\n";


        std::cout << levels[current_level];

        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 10)); //10fps
    }
}



bool SnakeGame::game_over()
{
    return over;
}