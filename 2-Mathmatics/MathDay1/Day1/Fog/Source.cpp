#include <SFML\Graphics.hpp>
#include <math.h>
#include<algorithm>
#include<iostream>
using namespace sf;
float LinearFog(float d, float start, float end) {
	if (d < start)return 0;
	else if (d > end)return 1;
	else return (d - start) / (end - start);
}
float expFog(float d,float p) {
	
	return 1-exp(-d*p);
}
float exp2Fog(float d, float p) {
	return 1 - exp2(-d*p);

}

int main() {
	RenderWindow window;
	window.create(VideoMode(400, 400), "hamada");
	Texture tex;
	
	tex.loadFromFile("background.png");
	Sprite sprite(tex, IntRect(0, 0, 400, 400));
	window.display();
	Vector2f playerPosition(200, 200);
	float scale = 1;
	bool a = false;
	float p = .1;
	float start = 50;
	float end = 100;
	
	while (window.isOpen())
	{
		window.clear();
		window.draw(sprite);
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::EventType::MouseButtonPressed) {
				a = !a;
			}
			if (ev.type == Event::EventType::KeyPressed) {
				if (ev.key.code == Keyboard::A) {
					start += 20;;
					p *= 1.2;
				}
				if (ev.key.code == Keyboard::D) {
					start -= 20;
					p /= 1.2;
				}
				if (ev.key.code == Keyboard::W) {
					end += 20;;
				}
				if (ev.key.code == Keyboard::S) {
					end -= 20;;
				}

				if (ev.key.code == Keyboard::Up) {
					playerPosition.y -= 10;;
				}

				if (ev.key.code == Keyboard::Down) {
					playerPosition.y += 10;;

				}
				if (ev.key.code == Keyboard::Left) {
					playerPosition.x -= 10;
				}

				if (ev.key.code == Keyboard::Right) {
					playerPosition.x += 10;

				}

			}
			if (ev.type == Event::EventType::MouseWheelScrolled) {
				if (ev.mouseWheelScroll.delta > 0)scale *= 2;
				else if (ev.mouseWheelScroll.delta < 0) {
					scale /= 2.0;
					scale = fmax(scale, 1);
				}
				std::cout << scale;

			}
		}
		RectangleShape rect(Vector2f(scale, scale));
		for (size_t i = 0; i < 400; i += scale)
		{
			for (size_t j = 0; j < 400; j += scale)
			{
				rect.setPosition(i,j);
				float dx = i - playerPosition.x;
				float dy = j - playerPosition.y;
				float d=sqrt(dx*dx+dy*dy);
				float fog = 255* exp2Fog(d,p);
				rect.setFillColor(Color(0,0,0,fog));
				window.draw(rect);
			}
		}
		window.display();

	}

}
