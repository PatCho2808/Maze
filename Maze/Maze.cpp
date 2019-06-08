#include "Maze.h"



Maze::Maze(int mazeSize, int cellSize)
{
	this->mazeSize = mazeSize; 
	this->cellSize = cellSize;

	CreateCells(); 
}


Maze::~Maze()
{
}

void Maze::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto cell : cells)
	{
		target.draw(cell); 
	}
}



void Maze::GenerateMaze()
{

}

void Maze::CreateCells()
{
	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
			cells.push_back(Cell(cellSize, i, j));
		}
	}

}
