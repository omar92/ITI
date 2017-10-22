#include "Player.h"
#include<iostream>

namespace game {
	


	Player::Player(sf::Vector2f   position):GridObject(position)
	{
	}

	Player::~Player()
	{
	}

	std::shared_ptr<sf::Shape> game::Player::draw(sf::Vector2f   size,sf::RenderWindow & window)
	{
		std::cout << "P";
		std::shared_ptr<sf::Shape> shape= std::make_shared<sf::CircleShape>(size.x/2);
		
		shape->setFillColor(sf::Color::Red);
		shape->setPosition(position.x*size.x, position.y*size.y);


		return shape;
	}

	void game::Player::init()
	{
	}

	void game::Player::update(float time)
	{
	}
}