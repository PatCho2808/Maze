#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include "Cell.h"


class Maze :
	public sf::Drawable
{
public:
	Maze(int mazeSize, int cellSize);
	~Maze();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private: 

	int mazeSize; 
	int cellSize;
	std::vector<Cell> cells; 
	std::stack<Cell *> backtrace;
	Cell *current; 

	void GenerateMaze();
	void CreateCells(); 
	std::vector<Cell *> GetAvailableNeighbours(); 
	Cell* GetNextCell(); 
	int CalculateIndex(int row, int column); 
};

