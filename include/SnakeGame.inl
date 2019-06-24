//=== CONSTRUCTORS ===\\



SnakeGame::SnakeGame() //TODO REDO
{
	levels = 0;
	height = 0;
	width = 0;
}



//=== METHODS ===\\



void SnakeGame::render_welcome_msg() //DONE!!!
{
    if(!game_over())
    {
        std::cout << "---> Welcome to the classic Snake Game <---\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Levels loaded: " << levels << " | Snake lives: 5 | Apples to eat: 10\n";
        std::cout << "Clear all levels to win the game. Good luck!!!\n";
        std::cout << "-------------------------------------------\n";
        std::cout << "Press <ENTER> to start the game!\n";
        std::getline(std::cin, input);
    }
}


void SnakeGame::initialize_game(int argc, char** argv) //DONE!!!
{
	std::string line;
	std::ifstream dat;
	dat.open(*(argv + 1), std::ifstream::in);

	std::cout << *(argv + 1) << "\n";

	if (!dat.is_open())
	{
		std::cout << "Unable to open file.\n";
	}

    while (!dat.eof())
    {
        int i = -1;

        std::getline(dat, line);
        std::stringstream ss;

        if(line[1] >= 48 and line[1] <= 57)
        {
            ss << line;

            std::string temp;
            int found;
            for (int cont = 0; !ss.eof(); cont++) {
                ss >> temp;

                if (std::stringstream(temp) >> found) {
                    i++;

                    current_level.resize(i + 1);

                    if (cont == 0) {
                        height = found;
                        std::cout << height << " ";
                    }
                    if (cont == 1) {
                        width = found;
                        std::cout << width << "\n";
                    }
                }
                temp = "";
            }

            current_level[i].init(height, width);

            bool headfound = false;

            for (auto l = 0; l < height; l++) {
                std::getline(dat, line);

                for (auto c = 0; c < line.size(); c++) {
                    if (c == width) {
                        break;
                    } else if (line.at(c) == '#') {
                        current_level[i].set('#', l, c);
                        std::cout << line.at(c);
                    } else if (line.at(c) == '.') {
                        current_level[i].set('.', l, c);
                        std::cout << line.at(c);
                    } else if (line.at(c) == '*') {
                        current_level[i].set('*', l, c);
                        headfound = true;
                        std::cout << line.at(c);
                    } else {
                        current_level[i].set_empty(' ', l, c);
                        std::cout << line.at(c);
                    }
                }
                std::cout << l << "\n";
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
    std::cout << "YO\n";
	//TODO ADD ACTIONS OF PLAYER IA
}


void SnakeGame::process_events()
{
    std::cout << "YO\n";
    //TODO
}


void SnakeGame::render()
{
	std::cout << current_level;
}

bool SnakeGame::game_over()
{
    if(cobra.eaten() == 5)
        over = true;

	return over;
}