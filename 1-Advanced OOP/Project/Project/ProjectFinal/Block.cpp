#include "Block.h"
#include<iostream>

namespace game {

	Block::Block(sf::Vector2f position):GridObject(position)
	{
	}


	Block::~Block()
	{
	}

	std::shared_ptr<sf::Shape> Block::draw(sf::Vector2f  size,sf::RenderWindow &window)
	{
		std::cout << "B";
		std::shared_ptr<sf::Shape> shape = std::make_shared<sf::RectangleShape> (size);
		shape->setFillColor(sf::Color::Blue);
		shape->setPosition(position.x*size.x,position.y*size.y);
		return shape;
	}

	void Block::init()
	{
	}
	void Block::update(float time)
	{
	}
}
