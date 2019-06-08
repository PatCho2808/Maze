#include "Game.h"






Game::Game(int windowSize, std::string windowTitle)
{
	sf::RenderWindow window(sf::VideoMode(windowSize,windowSize), windowTitle);
	Maze maze(mazeSize, windowSize / mazeSize);
	Player player(maze.GetBegging().x, maze.GetBegging().y, windowSize / mazeSize);
	Play(window,maze, player);

}


Game::~Game()
{
}

void Game::Play(sf::RenderWindow& window, Maze maze, Player player)
{
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Right)
				{
					if (maze.GetCanMoveInDirection(player.GetPosition().x, player.GetPosition().y, 1, 0))
					{
						player.Move(1, 0);
					}
						
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					if (maze.GetCanMoveInDirection(player.GetPosition().x,player.GetPosition().y,-1, 0))
					{
						player.Move(-1, 0);
					}
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					if (maze.GetCanMoveInDirection(player.GetPosition().x, player.GetPosition().y, 0, 1))
					{
						player.Move(0,1);
					}
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					if (maze.GetCanMoveInDirection(player.GetPosition().x, player.GetPosition().y, 0, -1))
					{
						player.Move(0,-1);
					}
				}
			}
		}

		window.clear();
		window.draw(maze); 
		window.draw(player); 
		window.display();
	}
}
