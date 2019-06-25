# Snaze

This project is a simulation of the classic snake game.

# Include

Where the Level.h, Player.h, Snake.h, SnakeGame.h and it's respectives inl files are located.

# Src

Where the snaze.cpp(the game) file is located.

# Limitations

* This program is still in it's early stage. Doesn't even have the player class made, and the snaze is not functional

# Build

To build this project you can compile via terminal going to the folder where the project is located, then compile the project using: `g++ -Wall -std=c++11 -I include src/snaze.cpp`

Or you can use cmake. 

Supposing you put Snaze in the directory `${SNAZE_DIR}`:

    mkdir mybuild     # Create a directory to hold the build output.
    cd mybuild
    cmake ${SNAZE_DIR}  # Generate native build scripts
    
# Authors

* Victor Ângelo Graça Morais

* Heitor Pereira Paiva
