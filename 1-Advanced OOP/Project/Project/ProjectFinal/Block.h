#pragma once
#include "GridObject.h"
namespace game {
	class Block :
		public GridObject
	{
	public:
		Block(sf::Vector2f  position);
		~Block();

		// Inherited via GridObject
		virtual std::shared_ptr<sf::Shape> draw(sf::Vector2f size, sf::RenderWindow &window) override;
		virtual void init() override;
		virtual void update(float time) override;
	};

}
