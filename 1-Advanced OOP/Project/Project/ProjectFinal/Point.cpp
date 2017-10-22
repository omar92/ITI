#include "sf::vector2f.h"

namespace game {

	sf::vector2f::sf::vector2f(float x, float y):Vector2(x,y)
	{
		this->x = x;
		this->y = y;
	}
	sf::vector2f::sf::vector2f()
	{
		this->x = 0;
		this->y = 0;
	}


	sf::vector2f::~sf::vector2f()
	{
	}
}