#include "Game.h"





Game::Game(sf::Vector2<int> windowSize, std::string windowTitle)
{
	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), windowTitle);
	Play(window);
}


Game::~Game()
{
}

void Game::Play(sf::RenderWindow& window)
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
		window.display();
	}
}
