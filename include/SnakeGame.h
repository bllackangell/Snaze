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

	int levels;
	int height, width;
	std::string head = ">";
	std::string score;
	std::string input;
	Level current_level;
	//Player IA; TODO
	Snake cobra;

public:
//=== CONSTRUCTORS ===\\



	SnakeGame();



//=== DESTRUCTOR ===\\


	
	~SnakeGame(){/*EMPTY*/};



//=== METHODS ===\\



	void render_welcome_msg();


	void initialize_game(int argc, char **argv); //TODO


	void update(); //TODO


	void process_events(); //TODO


	void render();


	bool game_over();
};

#include "SnakeGame.inl"

#endif //SNAKEGAME_H