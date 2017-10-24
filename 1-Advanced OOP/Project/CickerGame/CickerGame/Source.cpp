#include <SFML\Graphics.hpp>
//#include <math.h>
//#include<algorithm>
#include<iostream>
//using namespace sf;
#include "UIManager.h"

//Vector2f transformedPoint(Vector2f p, float x, float y, float scalex = 1) {
//	p.x *= scalex;
//	p.x += x / 2;
//	p.y *= -1;
//	p.y += y / 2;
//	return p;
//}
//float square(float x) {
//	return (x*x*x);
//}

unsigned long long int clicksCount = 0;

void onPress(UIElement &element) {
	clicksCount++;
	std::cout << "clicksCount :" << clicksCount<< "\n";
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
	circleShape.setPosition(200,200);
	UIElement circleUI(circleShape);
	circleUI.setOnPress(onPress);
	circleUI.setOnRelease(onRelease);
	circleUI.setOnEnter(onHover);
	circleUI.setOnExit(onRelease);
	uiManager.add(circleUI);

	//auto circle  = uiManager.createCyrcle(50,50);


	//RenderWindow window;
	//window.create(VideoMode(400, 400), "Grapher");

	//window.display();
	//VertexArray xAxis;
	//VertexArray yAxis;
	//VertexArray graph;

	//xAxis.setPrimitiveType(LinesStrip);
	//yAxis.setPrimitiveType(LinesStrip);
	//graph.setPrimitiveType(LinesStrip);


	//xAxis.append(transformedPoint(Vector2f(-200, 0), 400, 400));
	//xAxis.append(transformedPoint(Vector2f(200, 0), 400, 400));

	//yAxis.append(transformedPoint(Vector2f(-0, -200), 400, 400));
	//yAxis.append(transformedPoint(Vector2f(0, 200), 400, 400));
	//float scale = 1;
	while (uiManager.isOpen())
	{
		uiManager.Update();
		//graph.clear();
		//window.clear();
		//for (int x = -100; x < 100; x++)
		//{
		//	float y = square(x);
		//	graph.append(transformedPoint(Vector2f(x, y), 400, 400, scale));
		//}

		//sf::Event ev;
		//while (window.pollEvent(ev))
		//{
		//	if (ev.type == Event::EventType::MouseWheelScrolled) {
		//		std::cout << ev.mouseWheel.delta;
		//		if (ev.mouseWheelScroll.delta > 0)scale *= 1.5;
		//		else if (ev.mouseWheelScroll.delta < 0) {
		//			scale /= 1.5;
		//		}
		//	}
		//}
		//window.draw(yAxis);
		//window.draw(xAxis);
		//window.draw(graph);

		//window.display();

	}
	return 0;
}