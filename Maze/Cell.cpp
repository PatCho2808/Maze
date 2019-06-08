#include "Cell.h"



Cell::Cell(int cellSize, int row, int column)
{
	visited = false; 
	this->cellSize = cellSize;
	this->row = row; 
	this->column = column; 
	SetWalls(); 
	
}


Cell::~Cell()
{
}

void Cell::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (walls[0])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(row* cellSize, column * cellSize);
		target.draw(line);
	}
	if (walls[1])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(row* cellSize, column * cellSize);
		line.setRotation(90); 
		target.draw(line);
	}
	if (walls[2])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(row* cellSize + cellSize, column * cellSize);
		target.draw(line);
	}
	if (walls[3])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(row* cellSize, column * cellSize + cellSize);
		line.setRotation(90); 
		target.draw(line);
	}
}

int Cell::GetRow()
{
	return row;
}

int Cell::GetColumn()
{
	return column;
}

bool Cell::IsVisited()
{
	return visited; 
}

void Cell::SetVisited(bool newVisited)
{
	visited = newVisited; 
}

void Cell::RemoveWalls(Cell & next)
{
	int x = column - next.column;
	int y = row - next.row;

	if (x == 1) {
		walls[LEFT] = false;
		next.walls[RIGHT] = false;
	}
	else if (x == -1) {
		walls[RIGHT] = false;
		next.walls[LEFT] = false;
	}
	else if (y == 1) {
		walls[TOP] = false;
		next.walls[BOTTOM] = false;
	}
	else if (y == -1) {
		walls[BOTTOM] = false;
		next.walls[TOP] = false;
	}

}

void Cell::SetWalls()
{
	for (int i = 0; i < 4; i++)
	{
		walls[i] = true; 
	}
}
