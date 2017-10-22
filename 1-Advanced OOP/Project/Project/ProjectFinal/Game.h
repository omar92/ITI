#pragma once
#pragma comment(lib,"sfml-window-s-d.lib" )
#include<vector>
#include"GridObject.h"
#include<stack>
#include<string>
#include <SFML\Window.hpp>

namespace game {
	class Game
	{
	private:
		sf::Vector2f PlayerPosition;
		sf::Vector2f TargetPosition;
		sf::Vector2f size;
		std::vector<std::vector<GridObject*>> map;
		std::stack<std::vector<std::vector<GridObject*>>> steps;
		std::stack<sf::Vector2f> playerSteps;
		sf::RenderWindow window;
		int currentLevel = 0;
		std::vector<std::string> levels;
		void GoUp();
		void GoDown();
		void GoLeft();
		void GoRight();
		void Draw();
		void MoveObjectToDirection(sf::Vector2f objectPosition, sf::Vector2f direction);
	public:

		void GameLoop();
		void LoadLevel();
		Game(std::vector<std::string> filename);
		
		~Game();
	};

}

