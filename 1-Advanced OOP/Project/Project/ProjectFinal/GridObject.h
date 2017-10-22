#pragma once
#include<SFML\Graphics.hpp>
#include <memory>

namespace game {
	class GridObject
	{
	public:
		std::shared_ptr<sf::Shape>shape;
		sf::Vector2f position;
		virtual std::shared_ptr<sf::Shape> draw(sf::Vector2f size,sf::RenderWindow &window) = 0;
		virtual void init() = 0;
		virtual void update(float time) = 0;
		GridObject(sf::Vector2f   position);
		~GridObject();
	};
}
