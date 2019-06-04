#pragma once

#include <SFML/Graphics.hpp>


class Maze :
	public sf::Drawable
{
public:
	Maze(sf::Vector2<int> mazeSize, sf::Vector2<int> cellSize);
	~Maze();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private: 

	sf::Vector2<int> mazeSize; 
	sf::Vector2<int> cellSize;



	void GenerateMaze();
};

