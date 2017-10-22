#pragma once
#include "GridObject.h"
namespace game {
	class Empty :
		public GridObject
	{
	public:
		Empty(sf::Vector2f  ); 
		~Empty();

		// Inherited via GridObject
		virtual std::shared_ptr<sf::Shape> draw(sf::Vector2f size, sf::RenderWindow &window) override;
		virtual void init() override;
		virtual void update(float time) override;
	};
}
