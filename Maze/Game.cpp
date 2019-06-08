#include "Game.h"





Game::Game(int windowSize, std::string windowTitle)
{
	sf::RenderWindow window(sf::VideoMode(windowSize,windowSize), windowTitle);
	Maze maze(mazeSize, windowSize / mazeSize);
	Play(window,maze);

	
	
}


Game::~Game()
{
}

void Game::Play(sf::RenderWindow& window, Maze maze)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(maze); 
		window.display();
	}
}
