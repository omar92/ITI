#include<SFML\Graphics.hpp>
#include<iostream>
#include<math.h>
#define SCREEN_W (1360)
#define SCREEN_H (768)

using namespace sf;
Clock c;
float f(float x, float t, float fre, float mag, float shift) {
	return 0;
}

Vector2f shiftToCenter(float x, float y, float width, float height, float scale = 1) {
	Vector2f point;
	//width *= scale;
	//height *= scale;
	point.x = (width / 2 + x*scale);
	point.y = (height - (height / 2 + y*scale));
	return point;
}
Vector2f centerToOrigin(float x, float y, float width, float height, float scale = 1) {
	Vector2f point;
	//width *= scale;
	//height *= scale;
	point.x = (x - (width / 2)) / scale;
	point.y = (height + (height / 2 - y))/scale;
	return point;
}
int main() {
	RenderWindow window;
	float scale = 32;
	c.restart();
	window.create(VideoMode(SCREEN_W, SCREEN_H), "Grapher");
	VertexArray  xAxis;
	VertexArray  yAxis;
	VertexArray  graph;

	xAxis.setPrimitiveType(LinesStrip);
	yAxis.setPrimitiveType(LinesStrip);
	graph.setPrimitiveType(LinesStrip);
	xAxis.append(shiftToCenter(-SCREEN_W / 2, 0, SCREEN_W, SCREEN_H));
	xAxis.append(shiftToCenter(SCREEN_W / 2, 0, SCREEN_W, SCREEN_H));

	yAxis.append(shiftToCenter(0, SCREEN_H / 2, SCREEN_W, SCREEN_H));
	yAxis.append(shiftToCenter(0, -SCREEN_H / 2, SCREEN_W, SCREEN_H));




	while (window.isOpen())
	{
		graph.clear();
		window.clear();

		graph.append(Vector2f(0, 2));
		graph.append(Vector2f(1, 2));
		graph.append(Vector2f(1.5, 3));
		graph.append(Vector2f(2, 1));

		for (float x = 2.0; x <= 4; x += 0.1) {
			float y = (11.0 / 10.0)*(x*x) - (57.0 / 10.0)*x + (8.0);
			graph.append(Vector2f(x, y));
		}
		for (float x = 4; x <=7; x+=0.1)
		{
			float y = (-26.0 / 45.0)*(x*x) + (244.0 / 45.0)*x -(434.0/45.0);
			graph.append(Vector2f(x, y));
		}

		for (float x = 7; x >=4; x -= 0.1)
		{
			float y = (-26.0 / 45.0)*(x*x) + (244.0 / 45.0)*x - (434.0 / 45.0);
			graph.append(Vector2f(x, -y));
		}

		//graph.append(Vector2f(7, 0));
		//graph.append(Vector2f(4, -3.5));
		graph.append(Vector2f(2, -3));
		graph.append(Vector2f(0, -4));




		int length = graph.getVertexCount();
		//mirror
		for (int i = length - 1; i >= 0; i--)
		{
			auto v = graph[i];
			printf("%f,%f\n", v.position.x, v.position.y);
			v.position.x *= -1;
			printf("%f,%f\n", v.position.x, v.position.y);
			graph.append(v);
		}
		//shift to center
		length = graph.getVertexCount();
		for (int i = 0; i < length; i++)
		{
			auto v = graph[i];
			graph[i].position = shiftToCenter(v.position.x, v.position.y, SCREEN_W, SCREEN_H, scale);
		}


		window.draw(xAxis);
		window.draw(yAxis);
		window.draw(graph);

		Event ev;
		while (window.pollEvent(ev)) {
			if (ev.type == Event::MouseWheelScrolled) {
				if (ev.mouseWheelScroll.delta > 0) {
					scale *= 2;
					std::cout << scale;
				}
				else if (ev.mouseWheelScroll.delta < 0) {
					scale /= 2;
				}
			}

			if (ev.type == Event::Closed) {
				return 0;
			}

		}
		window.display();
	}
	return 0;
}