//=== CONSTRUCTORS ===\\



SnakeGame::SnakeGame() //TODO REDO
{
    current_level = 0;
	height = 0;
	width = 0;
}



//=== METHODS ===\\



void SnakeGame::render_welcome_msg()
{
    if(!game_over())
    {
        std::cout << "\n\n\n\n\n---> Welcome to the classic Snake Game <---\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Levels loaded: " << levels.size() << " | Snake lives: "<< cobra.lives <<" | Apples to eat: 5\n";
        std::cout << "Clear all levels to win the game. Good luck!!!\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Press <ENTER> to start the game!\n";
        std::getline(std::cin, input);
    }
}


void SnakeGame::initialize_game(int argc, char** argv)
{
	std::string line;
	std::ifstream dat;
	dat.open(*(argv + 1), std::ifstream::in);

	if (!dat.is_open())
	{
		std::cout << "Unable to open file.\n";
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
                        levels[i - 1].set(u8"#", l, c);
                    } else if (line.at(c) == '.') {
                        levels[i - 1].set(u8".", l, c);
                    } else if (line.at(c) == '*') {
                        levels[i - 1].set(u8"*", l, c);
                        levels[i - 1].pos[0] = l;
                        levels[i - 1].pos[1] = c;
                        headfound = true;
                    } else {
                        levels[i - 1].set_empty(u8"\u0020", l, c);
                    }
                }
            }

            if (!headfound) {
                over = true;

                std::cout << "Head not found in maze: " << i;
            }

            set_apple();

        }
    }

    buffer = levels;

	dat.close();
}


void SnakeGame::update()
{

    std::cout << "===UPDATE===\n";
    if(!IA.move(levels[current_level], cobra))
    {
        std::cout << "YOU DIED!\n";
        std::cout << "Press <ENTER> to continue!\n";
        std::getline(std::cin, input);
        levels[current_level] = buffer[current_level];
    }
}


void SnakeGame::process_events()
{
    std::cout << "===PROCESS EVENTS===\n";
    if(levels[current_level].apple == levels[current_level].pos)
    {
        levels[current_level] = buffer[current_level];
        cobra.apples_eaten++;
    }

    if(cobra.eaten() == 5)
    {
        std::cout << "EATEN 5 APPLES!\n";
        std::cout << "Press <ENTER> to continue!\n";
        std::getline(std::cin, input);
        cobra.apples_eaten = 0;
        cobra.clear();
        current_level++;
    }

    else if(current_level > levels.size())
        over = true;

}


void SnakeGame::render()
{
    std::cout << "Level loaded: " << current_level + 1<< " | Snake lives: " << cobra.lives << " | Apples to eat: 5 | Apples eaten: " << cobra.apples_eaten << "\n";

	std::cout << levels[current_level];

    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 10));


    //std::cout << "Press <ENTER> to continue!\n";
   // std::getline(std::cin, input);
}

bool SnakeGame::game_over()
{
    return over;
}


void SnakeGame::set_apple()
{
    srand (time(nullptr));

    int x, y;

    do{

        x = rand() % levels[current_level].height(), y = rand() % levels[current_level].width();

    }while(levels[current_level].level[x][y].occupied);

    levels[current_level].level[x][y].block = u8"A";
    levels[current_level].apple[0] = x;
    levels[current_level].apple[1] = y;

}