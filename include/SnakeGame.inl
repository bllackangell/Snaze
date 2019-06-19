//=== CONSTRUCTORS ===\\



SnakeGame::SnakeGame()
{
	levels = 0;
	height = 0;
	width = 0;
}



//=== METHODS ===\\



void SnakeGame::render_welcome_msg()
{
	std::cout << "---> Welcome to the classic Snake Game <---\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Levels loaded: " << levels << " | Snake lives: 5 | Apples to eat: 10\n";
	std::cout << "Clear all levels to win the game. Good luck!!!\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Press <ENTER> to start the game!\n";
	std::getline(std::cin, input);
}


void SnakeGame::initialize_game(int argc, char** argv) //TODO THIS METHOD WAS COPIED FROM LIFE GAME, NEEDS CHANGES ON CODE TO WORK
{
	std::string line;
	std::ifstream dat;
	dat.open(*(argv + 1), std::ifstream::in);

	if (!dat.is_open())
	{
		std::cout << "Unable to open file.\n";
	}
	std::getline(dat, line);
	std::stringstream ss;

	ss << line;

	std::string temp;
	int found;
	for (int cont = 0; !ss.eof(); cont++)
	{
		ss >> temp;

		if (std::stringstream(temp) >> found)
		{
			if (cont == 0)
			{
				height = found;
			}
			if (cont == 1)
			{
				width = found;
			}
		}
		temp = "";
	}


	current_level.init(height, width);


	for (auto l = 0; l < height; l++)
	{
		bool headfound = false;

		std::getline(dat, line);

		for (auto c = 0; c < line.size(); c++)
		{
			if (c == width)
			{
				break;
			}
			else if (line.at(c) == '#')
			{
				current_level.set('#', l, c);
			}
			else if (line.at(c) == '.')
			{
                current_level.set('.', l, c);
			}
			else if (line.at(c) == '*')
			{
                current_level.set('*', l, c);
                headfound = true;
			}

			//TODO STOP IF FOUND IS FALSE
		}
	}

	dat.close();
}


void SnakeGame::update()
{
	//TODO ADD ACTIONS OF PLAYER IA
}


void SnakeGame::process_events()
{
    //TODO
}


void SnakeGame::render()
{
	std::cout << current_level;
}

bool SnakeGame::game_over()
{
	return cobra.eaten() == 5;
}