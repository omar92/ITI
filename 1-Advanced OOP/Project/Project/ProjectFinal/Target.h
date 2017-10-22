#pragma once
#include "GridObject.h"
namespace game {
	class Target :
		public GridObject
	{
	public:
		Target(sf::Vector2f  );
		~Target();

		// Inherited via GridObject
		virtual std::shared_ptr<sf::Shape> draw(sf::Vector2f size, sf::RenderWindow &window) override;
		virtual void init() override;
		virtual void update(float time) override;
	};

}