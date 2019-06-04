#include "Game.h"





Game::Game(sf::Vector2<int> windowSize, std::string windowTitle)
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), windowTitle);
	Maze maze(sf::Vector2<int>(mazeSize,mazeSize), sf::Vector2<int>(windowSize.x / mazeSize, windowSize.y / mazeSize));
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
