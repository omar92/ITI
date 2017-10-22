#include "UIManager.h"



UIManager::UIManager(int width, int height) :screenWidth(width, height)
{
	window.create(sf::VideoMode(screenWidth.x, screenWidth.y), "Grapher");
	window.display();
}

void UIManager::Update()
{
	window.clear();

	sf::Event ev;
	while (window.pollEvent(ev))
	{
	}
	for each (auto element in uiElements)
	{
		//processElement(item);

		if (element.isClickable() && element.isActive()) {
			element.excuteOnPress();
		}

		element.draw(window);
	}

}

bool UIManager::isOpen()
{
	return window.isOpen();
}


UIManager::~UIManager()
{

}

void UIManager::processElement(UIElement& element)
{
}

void UIManager::pullInputs()
{
	for each (auto item in uiElements)
	{

	}
}
