#pragma once

#include <SFML/Graphics.hpp>
#include <string>


class Game
{


public:
	Game(sf::Vector2<int> windowSize, std::string windowTitle);
	~Game();

private: 

	void Play(sf::RenderWindow& window);

};

