#include "UIElement.h"



UIElement::UIElement(int x, int y, int width, int height) :pos(x, y), size(width, height)
{
	onPress = nullptr;
	_isActive = true;
}


UIElement::~UIElement()
{

}


void UIElement::setPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
}


void UIElement::setSize(int width, int height)
{
	size.x = width;
	size.y = height;
}

void UIElement::setOnPress(void(*callBack)())
{
	onPress = callBack;
}

bool UIElement::isClickable()
{	
	return onPress != nullptr;
}

void UIElement::excuteOnPress()
{
	if (onPress != nullptr && _isActive) {
		onPress();
	}
}

void UIElement::setActive(bool isActive)
{
	this->isActive = _isActive;
}

bool UIElement::isActive()
{
	return _isActive;
}

void UIElement::draw(sf::RenderWindow&)
{

}

void UIElement::scale(float scale)
{

}
