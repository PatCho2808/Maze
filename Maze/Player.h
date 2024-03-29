#pragma once

#include <SFML/Graphics.hpp>


class Player : 
	public sf::Drawable
{
public:
	Player(int row, int column, int size);
	~Player();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void SetPosition();
	void Move(int x, int y); 
	sf::Vector2i GetPosition(); 

private: 

	int row, column; 
	int size; 
	sf::RectangleShape rect; 
	sf::Color color = sf::Color(66, 244, 220, 125);

	void InitRectangle(); 
	
};

