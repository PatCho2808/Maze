#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Maze.h"
#include "Player.h"



class Game
{


public:
	Game(int windowSize, std::string windowTitle);
	~Game();

private:  

	int mazeSize = 10; 
	void Play(sf::RenderWindow& window, Maze maze, Player player);

};

