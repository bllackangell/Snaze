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
        std::cout << "Levels loaded: " << levels.size() << " | Snake lives: 5 | Apples to eat: 10\n";
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

	std::cout << *(argv + 1) << "\n";

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
                        levels[i - 1].set(u8"\u29DB", l, c);
                    } else if (line.at(c) == '.') {
                        levels[i - 1].set(u8"\u0020", l, c);
                    } else if (line.at(c) == '*') {
                        levels[i - 1].set(u8"\u1F40D", l, c);
                        headfound = true;
                    } else {
                        if(l == 1 and c == 1)
                        {
                            levels[i - 1].set(u8"\u1F34E", l, c);
                        }
                        levels[i - 1].set_empty(u8"\u0020", l, c);
                    }
                }
            }

            if (!headfound) {
                over = true;

                std::cout << "Head not found in maze: " << i;
            }
        }
    }
	dat.close();
}


void SnakeGame::update()
{

    std::cout << "===UPDATE===\n";
	//TODO ADD ACTIONS OF PLAYER IA
}


void SnakeGame::process_events()
{
    std::cout << "===PROCES SEVENTS===\n";
    //TODO
}


void SnakeGame::render()
{
	std::cout << current_level << std::endl;
	std::cout << levels[current_level];

    std::cout << "Press <ENTER> to continue!\n";
    std::getline(std::cin, input);
}

bool SnakeGame::game_over()
{
    if(cobra.eaten() == 5)
        over = true;

	return over;
}