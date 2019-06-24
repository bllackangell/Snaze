#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <sstream>
#include "Snake.h"
#include "Player.h"
#include "Level.h"

class SnakeGame
{
private:

	int height, width; //!< Height and width of the map
	std::string score; //!< Score
	std::string input; //!< User input to continue the game
	std::vector<Level> current_level; //!< Array of levels
	bool over = false;
	//Player IA; TODO
	Snake cobra;

public:
//=== CONSTRUCTORS ===\\



	SnakeGame();



//=== DESTRUCTOR ===\\


	
	~SnakeGame(){/*EMPTY*/};



//=== METHODS ===\\



    //!< Render Welcome message
	void render_welcome_msg();


	//!< Initialize the game
	void initialize_game(int argc, char **argv);


	void update(); //TODO


	void process_events(); //TODO


	void render();


	//!< Returns if game is over or not
	bool game_over();
};

#include "SnakeGame.inl"

#endif //SNAKEGAME_H