#include "Maze.h"



Maze::Maze(sf::Vector2<int> mazeSize, sf::Vector2<int> cellSize)
{
	this->mazeSize = mazeSize; 
	this->cellSize = cellSize;

	
}


Maze::~Maze()
{
}

void Maze::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	for (int i = 0; i < mazeSize.x; i++)
	{
		for (int j = 0; j < mazeSize.y; j++)
		{
			sf::RectangleShape line(sf::Vector2f(cellSize.x, 0.5));
			line.setPosition(cellSize.x*j, cellSize.y*i);
			line.setRotation(90); 
			target.draw(line); 
		}

		sf::RectangleShape line(sf::Vector2f(mazeSize.x * cellSize.x, 0.5));
		line.setPosition(0, cellSize.y*i);
		target.draw(line);
	}
}



void Maze::GenerateMaze()
{

}
