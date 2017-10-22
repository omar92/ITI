#pragma once
#include <SFML\Graphics.hpp>
class UIElement
{
	sf::Vector2f pos;
	sf::Vector2f size;
	bool _isActive ;
	void(*onPress)();
public:
	UIElement(int x, int y, int width, int height);
	~UIElement();
	void setPos(int x, int y);
	void setSize(int width, int height);
	void setOnPress(void(*callBack)());
	bool isClickable();
	void excuteOnPress();
	void setActive(bool isActive);
	bool isActive();
	void draw(sf::RenderWindow&);
	void scale(float scale);
};

