#include "Target.h"
#include<iostream>

namespace game {
	Target::Target(sf::Vector2f   position):GridObject(position)
	{
	}
	Target::~Target()
	{
	}
	std::shared_ptr<sf::Shape> Target::draw(sf::Vector2f  size,sf::RenderWindow &window)
	{
		std::cout << "T";
		std::shared_ptr<sf::Shape> shape = std::make_shared<sf::CircleShape>(size.x/2);
		shape->setFillColor(sf::Color(150,10,120));
		shape->setPosition(position.x*size.x, position.y*size.y);
		
		return shape;
	}
	void Target::init()
	{
	}
	void Target::update(float time)
	{
	}
}