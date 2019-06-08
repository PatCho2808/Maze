#include "Player.h"



Player::Player(int row, int column, int size)
{
	this->row = row; 
	this->column = column; 
	this->size = size; 
	InitRectangle(); 

}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect); 
}

void Player::SetPosition()
{
	rect.setPosition(size*column, size*row);
}

void Player::Move(int x, int y)
{
	column = column + x; 
	row = row - y; 
	SetPosition(); 
}

sf::Vector2i Player::GetPosition()
{
	return sf::Vector2i(row,column);
}

void Player::InitRectangle()
{
	rect.setSize(sf::Vector2f(size, size));
	SetPosition(); 
	rect.setFillColor(color); 

}
