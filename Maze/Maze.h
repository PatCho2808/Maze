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
	bool GetCanMoveInDirection(int row, int column, int x, int y);
	sf::Vector2i GetBegging(); 
	sf::Vector2i GetEnd();

private: 

	int mazeSize; 
	int cellSize;
	std::vector<Cell> cells; 
	std::stack<Cell *> backtrace;
	Cell *current; 
	Cell *beggining; 
	Cell *end; 

	void GenerateMaze();
	void CreateCells(); 
	std::vector<Cell *> GetAvailableNeighbours(); 
	Cell* GetNextCell(); 
	int CalculateIndex(int row, int column); 
	void SetBeggingAndEnd(); 
};

