#include "Game.h"






Game::Game(int windowSize, std::string windowTitle, int mazeSize)
{
	this->mazeSize = mazeSize; 
	sf::RenderWindow window(sf::VideoMode(windowSize,windowSize), windowTitle);
	if (!font.loadFromFile("../Materials/Roboto-Black.ttf"))
	{
		// error...
	}
	InitGame(windowSize, window); 
}


Game::~Game()
{
}

void Game::Play(sf::RenderWindow& window, Maze maze, Player player)
{
	
	while (gameState == PLAY)
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

		CheckEndGameConditions(player); 
		window.clear();
		window.draw(maze); 
		window.draw(player); 
		window.display();
	}

	SetEndGameText(window.getSize().x); 

	while (gameState == WIN || gameState == LOSE)
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					InitGame(window.getSize().x, window);

				}
			}
		}
		window.clear();
		window.draw(endGameText); 
		window.display();
	}
}

void Game::InitGame(int windowSize, sf::RenderWindow& window)
{
	gameState = PLAY;
	Maze maze(mazeSize, windowSize / mazeSize);
	endCoordinates = maze.GetEnd(); 
	Player player(maze.GetBegging().x, maze.GetBegging().y, windowSize / mazeSize);
	Play(window, maze, player);
}

void Game::SetEndGameText(int windowSize)
{
	if (gameState == WIN)
	{
		endGameText.setString("YOU WON! \n PRESS ENTER TO RESTART");
	}
	else if (gameState == LOSE)
	{
		endGameText.setString("YOU LOSE! \n PRESS ENTER TO RESTART");
	}

	endGameText.setFont(font);
	endGameText.setPosition(windowSize / 2 - endGameText.getLocalBounds().width/2, windowSize / 2 - endGameText.getLocalBounds().height/2);
	
}

void Game::CheckEndGameConditions(Player player)
{
	if (player.GetPosition().x == endCoordinates.x &&  player.GetPosition().y == endCoordinates.y)
	{
		gameState = WIN; 
	}
}
