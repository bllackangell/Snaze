#include<iostream>
#include<string>

class SnakeGame
{
private:

	int levels;
	int height, width;
	std::string score;
	std::string input;
	Level current_level();
	Player IA();
	Snake cobra('>');

public:
//=== CONSTRUCTORS ===\\



	SnakeGame();



//=== DESTRUCTOR ===\\


	
	~SnakeGame(){/*EMPTY*/};



//=== METHODS ===\\



	render_welcome_msg();


	initialize_game(const int argc, const char **argv);


	update();


	process_events();


	render();


	game_over();
};

#include "SnakeGame.inl"