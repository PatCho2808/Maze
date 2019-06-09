#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Maze.h"
#include "Player.h"



class Game
{


public:
	Game(int windowSize, std::string windowTitle, int mazeSize);
	~Game();

private:  

	int mazeSize; 
	enum state {PLAY,WIN,LOSE};
	state gameState; 
	sf::Text endGameText;
	sf::Font font; 
	sf::Vector2i endCoordinates; 
	void Play(sf::RenderWindow& window, Maze maze, Player player);
	void InitGame(int windowSize, sf::RenderWindow& window);
	void SetEndGameText(int windowSize);
	void CheckEndGameConditions(Player player);

};

