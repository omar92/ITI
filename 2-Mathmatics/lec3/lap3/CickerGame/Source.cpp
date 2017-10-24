#include <SFML\Graphics.hpp>
#include <math.h>
#include<algorithm>
#include<iostream>
using namespace sf;
Vector2f transformedPoint(Vector2f p, float x, float y, float scalex = 1) {
	p.x *= scalex;
	p.x += x / 2;
	p.y *= -1;
	p.y += y / 2;
	return p;
}


float square(float x, float scale) {
	if (x < 0) {
		return 0;
	}
	else if (x > scale) {
		return scale*scale;
	}
	else
	{
		return pow(x, 2);
	}
}

Vector2f sPos;
Vector2f cPos;
Vector2f ePos;


float getPosAsc(float t, float s, float c, float e) {

	float a = (e - s);
	return -a * t*(t - 2) + s;
}

float square(float t, float s, float c, float e) {
	float a = (e - s);
	// = e - s;
	return a*(t*t) + s;
}

float jumpingTween(float t, float s, float c, float e) {
	return ((3 * s + e)*(t*t)) - (4 * s*t) + s;
}

int main()
{
	Clock clock;
	RenderWindow window;
	window.create(VideoMode(800, 800), "Grapher");
	sPos.x = 0;
	sPos.y = 0;
	cPos.x = sPos.x;
	cPos.y = sPos.y;
	ePos.x = 600;
	ePos.y = 200;
	sf::CircleShape circle(5.0, 30);
	circle.setFillColor(Color::Green);
	float t = 0;
	while (window.isOpen())
	{
		window.clear();
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			if (ev.type == Event::EventType::MouseButtonPressed) {
				sPos = cPos;
				ePos.x = Mouse::getPosition(window).x;
				ePos.y = Mouse::getPosition(window).y;
				printf("click\n");
				clock.restart();
				t = 0;
			}
		}
		t += .005;

		if (t < 1.0f) {
			//std::cout <<"\n" <<t;
			printf("cPos (%f,%f)\n", cPos.x, cPos.y);

			cPos.x = getPosAsc(t, sPos.x, cPos.x, ePos.x);
			cPos.y = getPosAsc(t, sPos.y, cPos.y, ePos.y);
		}
		//printf("sPos (%f,%f)\n", sPos.x, sPos.y);
		//printf("ePos (%f,%f)\n", ePos.x, ePos.y);
		//printf("\n");
		circle.setPosition(cPos.x, cPos.y);

		window.draw(circle);
		window.display();

	}
	return 0;
}