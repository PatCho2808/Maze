#pragma once

#include <SFML/Graphics.hpp>
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

	void GenerateMaze();
	void CreateCells(); 
};

