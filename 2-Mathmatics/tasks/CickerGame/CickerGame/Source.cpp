#include <SFML\Graphics.hpp>
//#include <math.h>
//#include<algorithm>
#include<iostream>
//using namespace sf;
#include "UIManager.h"


unsigned long long int clicksCount = 0;

void onPress(UIElement &element) {
	clicksCount++;
	std::cout << "clicksCount :" << clicksCount << "\n";
	element.getShape().setFillColor(sf::Color::Red);
}
void onRelease(UIElement &element) {
	element.getShape().setFillColor(sf::Color::Blue);
}
void onHover(UIElement &element) {
	element.getShape().setFillColor(sf::Color::Yellow);
}
int main()
{
	sf::RenderWindow window;
	window.create(sf::VideoMode(400, 400), "Grapher");
	UIManager uiManager(window);

	auto circleShape = sf::CircleShape(50.0f);
	circleShape.setFillColor(sf::Color::Blue);
	circleShape.setPosition(200, 200);
	UIElement circleUI(circleShape);
	circleUI.setOnPress(onPress);
	circleUI.setOnRelease(onRelease);
	uiManager.add(circleUI);

	while (uiManager.isOpen())
	{
		uiManager.Update();


	}
	return 0;
}