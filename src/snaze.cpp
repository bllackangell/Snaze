#include "SnakeGame.h"

int main( int argc, char **argv )
{
    char *locale;

    locale = setlocale(LC_ALL, "");

	SnakeGame state;

	state.initialize_game(argc, argv);

	state.render_welcome_msg();

	while(!state.game_over())
	{
		state.process_events();
		state.update();
		state.render();
	}

	return 0;
}