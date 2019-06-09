#include "Player.h"



Player::Player(int row, int column, int size){
	this->row = row; 
	this->column = column; 
	this->size = size; 
	initRectangle(); 

}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const{
	target.draw(rect); 
}

void Player::setPosition(){
	rect.setPosition(size*column, size*row);
}

void Player::move(int x, int y){
	column = column + x; 
	row = row - y; 
	setPosition(); 
}

sf::Vector2i Player::getPosition(){
	return sf::Vector2i(row,column);
}

void Player::initRectangle(){
	rect.setSize(sf::Vector2f(size, size));
	setPosition(); 
	rect.setFillColor(color); 
}
