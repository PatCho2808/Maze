#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Maze.h"



class Game
{


public:
	Game(sf::Vector2<int> windowSize, std::string windowTitle);
	~Game();

private:  

	int mazeSize = 10; 
	void Play(sf::RenderWindow& window, Maze maze);

};

