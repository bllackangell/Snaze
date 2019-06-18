//=== CONSTRUCTORS ===\\



Game::Game()
{
	levels = 0;
	height = 0;
	width = 0;
}



//=== METHODS ===\\



Game::render_welcome_msg()
{
	std::cout << "---> Welcome to the classic Snake Game <---\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Levels loaded: " << levels << " | Snake lives: 5 | Apples to eat: 10\n"
	std::cout << "Clear all levels to win the game. Good luck!!!\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Press <ENTER> to start the game!\n";
	std::getline(cin, input);
}


Game::initialize_game(const int argc, const char **argv) //TODO THIS METHOD WAS COPIED FROM LIFE GAME, NEEDS CHANGES ON CODE TO WORK
{
	else{
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

            for(auto l=0; l<height; l++)
            {
            	bool found = false;

                std::getline(dat, line);

                for (auto c = 0; c < line.size(); c++)
                {
                    if (c == width)
                    {
                        break;
                    }
                    else if (line.at(c) == '#')
                    {
                        current_level[l][j](Block('#'));
                    }
                    else if (line.at(c) == '.')
                    {
                        current_level[l][j](Block('.'));
                    }
                    else if (line.at(c) == '*')
                    {
                        current_level[l][j](Block('*'));
                    	found = true;
                    }

                    //TODO STOP IF FOUND IS FALSE
                }
            }

            dat.close();
        }
}


Game::update()
{
	//TODO ADD ACTIONS OF PLAYER IA
}


Game::render()
{
	std::cout << current_level;
}

Game::game_over()
{
	return cobra.apples_eaten == 5;
}