#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
class PolyLine : public sf::Shape
{
private:
	std::vector<sf::Vertex> points;
public:
	auto  getVertices() {
		return points;
	}
	PolyLine() {
		
	}
	void append(sf::Vector2f &p) {
		points.push_back(p);
	}
	void append(sf::Vertex &p) {
		points.push_back(p);
	}

	std::size_t getPointCount()const override {
		 return points.size();
	}
	sf::Vector2f getPoint(std::size_t index)const {
		return points[index].position;
	}

};

