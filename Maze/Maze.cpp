#include "Maze.h"
#include<iostream>

Maze::Maze(int mazeSize, int cellSize)
{
	this->mazeSize = mazeSize; 
	this->cellSize = cellSize;
	CreateCells(); 
	SetBeggingAndEnd();
	SetTraps();
	GenerateMaze(); 
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

bool Maze::GetCanMoveInDirection(int row, int column, int x, int y)
{
	int cellIndex = CalculateIndex(row, column); 
	bool canMove = cells[cellIndex].GetCanMoveInDirection(x, y);
	return canMove;
}

sf::Vector2i Maze::GetBegging()
{
	return sf::Vector2i(beggining->GetRow(), beggining->GetColumn()); 
}

sf::Vector2i Maze::GetEnd()
{
	return sf::Vector2i(end->GetRow(), end->GetColumn());
}

bool Maze::GetIsTrap(int row, int column)
{
	return cells[CalculateIndex(row, column)].GetIsTrap();
}

void Maze::GenerateMaze()
{
	while (true)
	{
		current->SetVisited(true); 
		Cell* next = GetNextCell(); 
		
		

		if (next != nullptr)
		{
			next->SetVisited(true); 
			backtrace.push(current); 
			current->RemoveWalls(*next);
			current = next;
		}
		else if (backtrace.size() > 0)
		{
			current = backtrace.top(); 
			backtrace.pop(); 
		}
		else if (backtrace.size() == 0)
		{
			break;
		}
	}
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

std::vector<Cell *> Maze::GetAvailableNeighbours()
{
	std::vector<Cell *> neighbours; 

	int currentRow = current->GetRow(); 
	int currentColumn = current->GetColumn();

	int neighboursIndexes[4]; 

	neighboursIndexes[0] = CalculateIndex(currentRow - 1, currentColumn); 
	neighboursIndexes[1] = CalculateIndex(currentRow, currentColumn -1);
	neighboursIndexes[2] = CalculateIndex(currentRow +1, currentColumn);
	neighboursIndexes[3] = CalculateIndex(currentRow, currentColumn +1);

	for (int i : neighboursIndexes)
	{
		if (i != -1 && cells[i].IsVisited() == false)
		{
			neighbours.push_back(&cells[i]); 
		}
	}

	return neighbours;
}

Cell * Maze::GetNextCell()
{
	std::vector<Cell *> availableNeighbors = GetAvailableNeighbours();
	if (availableNeighbors.size() > 0) {
		return availableNeighbors.at(rand() % availableNeighbors.size());
	}

	return nullptr;
}

int Maze::CalculateIndex(int row, int column)
{
	if (row < 0 || column < 0 || column > mazeSize - 1 || row > mazeSize - 1)
		return -1;
	else
		return column + row * mazeSize;
}

void Maze::SetBeggingAndEnd()
{
	beggining = &cells[rand() % cells.size()];
	beggining->SetIsBegging(); 
	end = &cells[rand() % cells.size()];
	end->SetIsEnd(); 
	current = beggining; 
}

void Maze::SetTraps()
{

	for (int i = 0; i < numberOfTraps; i++){

		int newTrapIndex = rand() % cells.size(); 
		while (cells[newTrapIndex].GetCanBeTrap() == false){

			newTrapIndex = rand() % cells.size();

		}
		cells[newTrapIndex].SetIsTrap(); 
	}
}
