#include "Empty.h"
#include<iostream>

namespace game {
	Empty::Empty(sf::Vector2f  position):GridObject(position)
	{
	}


	Empty::~Empty()
	{
	}
	std::shared_ptr<sf::Shape> Empty::draw(sf::Vector2f size, sf::RenderWindow &window)
	{
		std::cout << "E";
		
		std::shared_ptr <sf::Shape> shape = std::make_shared<sf::RectangleShape>(size);
		shape->setFillColor(sf::Color::White);
		shape->setPosition(position.x*size.x, position.y*size.y);
		return shape;
	}
	void Empty::init()
	{
	}
	void Empty::update(float time)
	{
	}
}
