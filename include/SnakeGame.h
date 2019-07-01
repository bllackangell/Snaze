#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include <locale.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "Snake.h"
#include "Player.h"
#include "Level.h"

class SnakeGame
{
private:

	int height, width;          //!< Height and width of the map
	std::string score;          //!< Score
	std::string input;          //!< User input to continue the game
	std::vector<Level> levels;  //!< Array of levels
    std::vector<Level> buffer;  //!< Array of levels
	int current_level;          //!< Current level on levels array
	bool over = false;
	Player IA;
	Snake cobra;

public:
//=== CONSTRUCTORS ===\\



	SnakeGame();



//=== DESTRUCTOR ===\\


	
	~SnakeGame(){/*EMPTY*/};



//=== METHODS ===\\



	//!< Initialize the game
	void initialize_game(int argc, char **argv);


    //!< Render Welcome message
    void render_welcome_msg();



	void update();



	void process_events();



	void render();


	//!< Returns if game is over or not
	bool game_over();
};

#include "SnakeGame.inl"

#endif //SNAKEGAME_H