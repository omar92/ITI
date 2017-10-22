#pragma once
#include <vector>;
#include "UIElement.h"
#include <SFML\Graphics.hpp>

class UIManager
{
	sf::Vector2f screenWidth;
	sf::RenderWindow window;
	std::vector<UIElement> uiElements;

public:
	UIManager(int width, int height);

	void Update();
	bool isOpen();
	~UIManager();

private:
	void processElement(UIElement&);

};

