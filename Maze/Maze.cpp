#include "Maze.h"



Maze::Maze(int mazeSize, int cellSize)
{
	this->mazeSize = mazeSize; 
	this->cellSize = cellSize;
}


Maze::~Maze()
{
}

void Maze::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
			sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
			line.setPosition(cellSize*j, cellSize*i);
			line.setRotation(90); 
			target.draw(line); 
		}

		sf::RectangleShape line(sf::Vector2f(mazeSize * cellSize, 0.5));
		line.setPosition(0, cellSize*i);
		target.draw(line);
	}
}



void Maze::GenerateMaze()
{

}
