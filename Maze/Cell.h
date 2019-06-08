#pragma once

#include <SFML/Graphics.hpp>


class Cell : 
	public sf::Drawable
{
public:
	Cell(int cellSize, int row, int column);
	~Cell();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private: 

	int cellSize; 
	int row, column; 
	bool walls[4]; 
	bool visited; 
	enum direction {TOP,RIGHT,BOTTOM,LEFT};

	void SetWalls(); 

};

