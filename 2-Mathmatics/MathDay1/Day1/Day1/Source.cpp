#include <SFML\Graphics.hpp>
#include <math.h>
#include<algorithm>
#include"PolyLine.h"
#include<iostream>
using namespace sf;
Vector2f transformedPoint(Vector2f p, float x, float y, float scalex = 1) {
	p.x *= scalex;
	p.x += x/2;
	p.y *= -1;
	p.y += y / 2;
	return p;
}
float square(float x) {
	return (x*x);
}
int main() {
	RenderWindow window;
	window.create(VideoMode(400, 400),"hamada");

	window.display();
	VertexArray xAxis;
	VertexArray yAxis;
	VertexArray graph;

	xAxis.setPrimitiveType(LinesStrip);
	yAxis.setPrimitiveType(LinesStrip);
	graph.setPrimitiveType(LinesStrip);


	xAxis.append(transformedPoint( Vector2f(-200, 0),400,400));
	xAxis.append(transformedPoint(Vector2f(200, 0), 400, 400));




	yAxis.append(transformedPoint(Vector2f(-0, -200), 400, 400));
	yAxis.append(transformedPoint(Vector2f(0, 200), 400, 400));
	float scale = 1;
	while (window.isOpen())
	{
		graph.clear();
		window.clear();
		for (int x = -100; x < 100; x++)
		{
			float y = square(x);
			graph.append(transformedPoint(Vector2f(x, y), 400, 400,scale));
		}

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::EventType::MouseWheelScrolled) {
				std::cout << ev.mouseWheel.delta;
				if (ev.mouseWheelScroll.delta > 0)scale *= 1.5;
				else if (ev.mouseWheelScroll.delta < 0){
					scale /= 1.5;
				}
			}
		}
		window.draw(yAxis);
		window.draw(xAxis);
		window.draw(graph);

		window.display();

	}

}

