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
	if (walls[LEFT])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(column* cellSize, row * cellSize);
		line.setRotation(90);
		target.draw(line);
	}
	if (walls[TOP])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(column* cellSize, row * cellSize);
		target.draw(line);
	}
	if (walls[RIGHT])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(column* cellSize + cellSize, row * cellSize);
		line.setRotation(90);
		target.draw(line);
	}
	if (walls[BOTTOM])
	{
		sf::RectangleShape line(sf::Vector2f(cellSize, 0.5));
		line.setPosition(column* cellSize, row * cellSize + cellSize);
		target.draw(line);
	}

	if (isBegginging || isEnd)
	{
		sf::RectangleShape rect(sf::Vector2f(cellSize, cellSize));
		rect.setPosition(column* cellSize, row * cellSize);
		rect.setFillColor(sf::Color(65, 244, 77,125));
		target.draw(rect);
	}

	if (isTrap)
	{
		sf::RectangleShape rect(sf::Vector2f(cellSize, cellSize));
		rect.setPosition(column* cellSize, row * cellSize);
		rect.setFillColor(sf::Color(244, 66, 66, 125));
		target.draw(rect);
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

void Cell::SetIsBegging()
{
	isBegginging = true; 
}

void Cell::SetIsEnd()
{
	isEnd = true; 
}

bool Cell::GetCanMoveInDirection(int x, int y)
{
	if (x == 1)
	{
		if (walls[RIGHT] == true)
			return false;
	}
	if (x == -1)
	{
		if (walls[LEFT] == true)
			return false;
	}
	if (y == 1)
	{
		if (walls[TOP] == true)
			return false;
	}
	if (y == -1)
	{
		if (walls[BOTTOM] == true)
			return false;
	}

	return true; 
}

bool Cell::GetCanBeTrap()
{
	return isBegginging == false && isEnd == false; 
}

void Cell::SetIsTrap()
{
	isTrap = true; 
}

bool Cell::GetIsTrap()
{
	return isTrap; 
}

void Cell::SetWalls()
{
	for (int i = 0; i < 4; i++)
	{
		walls[i] = true; 
	}
}
