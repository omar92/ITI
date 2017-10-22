#include "Game.h"
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include"Empty.h"
#include"Player.h"
#include"Target.h"
#include"Block.h"
#include<stdlib.h>
#include<typeinfo>
namespace game {

	void Game::GoUp()
	{
		std::cout << (float)PlayerPosition.y;
		auto i = PlayerPosition.y - 1;
		while (i >= 0 && typeid(*map[i][PlayerPosition.x]) != typeid(Block))
		{
			float x;
			i--;
			std::cout << i;
		}
		if (i != PlayerPosition.y - 1) {
			steps.push(map);
			playerSteps.push(PlayerPosition);
			map[PlayerPosition.y][PlayerPosition.x] = new Empty(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
			PlayerPosition.y = i + 1;
			map[PlayerPosition.y][PlayerPosition.x] = new Player(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
		}
	}
	void Game::GoDown()
	{
		auto i = PlayerPosition.y + 1;
		auto size = map[0].size();
		while (i < size && typeid(*map[i][PlayerPosition.x]) != typeid(Block))
		{
			i++;
		}
		if (i != PlayerPosition.y + 1) {
			steps.push(map);
			playerSteps.push(PlayerPosition);
			map[PlayerPosition.y][PlayerPosition.x] = new Empty(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
			PlayerPosition.y = i - 1;
			map[PlayerPosition.y][PlayerPosition.x] = new Player(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
		}
	}
	void Game::GoLeft()
	{
		auto i = PlayerPosition.x - 1;

		while (i >= 0 && typeid(*map[PlayerPosition.y][i]) != typeid(Block))
		{
			i--;
		}
		if (i != PlayerPosition.x - 1) {
			steps.push(map);
			playerSteps.push(PlayerPosition);
			map[PlayerPosition.y][PlayerPosition.x] = new Empty(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
			PlayerPosition.x = i + 1;
			map[PlayerPosition.y][PlayerPosition.x] = new Player(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
		}
	}
	void Game::GoRight()
	{
		auto i = PlayerPosition.x + 1;
		auto size = map[0].size();

		while (i < size && typeid(*map[PlayerPosition.y][i]) != typeid(Block))
		{
			i++;
		}
		if (i != PlayerPosition.x + 1) {
			steps.push(map);
			playerSteps.push(PlayerPosition);
			map[PlayerPosition.y][PlayerPosition.x] = new Empty(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
			PlayerPosition.x = i - 1;
			map[PlayerPosition.y][PlayerPosition.x] = new Player(sf::Vector2f(PlayerPosition.x, PlayerPosition.y));
		}

	}
	void Game::Draw()
	{
		system("cls");
		std::shared_ptr<sf::Shape> obj;
		obj = std::make_shared<sf::CircleShape>(100);
		for (size_t i = 0; i < map.size(); i++)
		{
			for (size_t j = 0; j < map[i].size(); j++)
			{
				window.draw(*map[i][j]->draw(this->size, window));
			}
			std::cout << "\n";
		}
	}
	void Game::MoveObjectToDirection(sf::Vector2f objectPosition, sf::Vector2f direction) {
		///<summary>this can be used to either move a player or a box</summary>
		///<param name="objectPosition"> the location of the object to move </param>
		///<param name="direction"> the movement direction </param>
		sf::Vector2f initialPosition = objectPosition;
		auto steper = objectPosition + direction;
		sf::Vector2f mapSize(map.size(), map[0].size());
		bool inbound =
			steper.x >= 0 && steper.x < mapSize.x &&
			steper.y >= 0 && steper.y < mapSize.y;
		
		while (inbound) {
		};


	}
	void Game::GameLoop()
	{
		window.create(sf::VideoMode(400, 400), "First GUI Game");
		std::cout << "\n" << window.getSize().x << " " << map[0].size();
		this->size = sf::Vector2f(window.getSize().x / map[0].size(), window.getSize().y / map.size());

		bool left, right, up, down;
		left = right = up = down = false;

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
					// window closed
				case sf::Event::Closed:
					window.close();
					break;

					// key pressed
				case sf::Event::KeyPressed:
					switch (event.key.code)
					{
					case sf::Keyboard::R:
						LoadLevel();
						break;
					case sf::Keyboard::U:
						if (steps.size() > 0) {

							map = steps.top();
							PlayerPosition = playerSteps.top();
							playerSteps.pop();
							steps.pop();
						}
					case sf::Keyboard::Up:
						if (!up) {
							GoUp();
							up = true;

						}
						break;
					case sf::Keyboard::Down:
						if (!down) {
							down = true;
							GoDown();

						}
						break;
					case sf::Keyboard::Left:
						if (!left) {
							left = true;
							GoLeft();
						}
						break;
					case sf::Keyboard::Right:
						if (!right) {
							right = true;
							GoRight();
						}
						break;
					default:
						break;
					}
					if (PlayerPosition == TargetPosition) {
						currentLevel++;
						LoadLevel();
					}
					break;
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						up = false;
						break;
					case sf::Keyboard::Down:
						down = false;
						break;
					case sf::Keyboard::Left:
						left = false;
						break;
					case sf::Keyboard::Right:
						right = false;
						break;
					default:
						break;
					}

					break;
				case  sf::Event::Resized:
					this->size = sf::Vector2f(window.getSize().x / map[0].size(), window.getSize().y / map.size());
					break;

				default:
					break;
				}

			}
			window.clear(sf::Color(255, 255, 255));
			Draw();

			window.display();
		}

	}
	void Game::LoadLevel()
	{
		if (currentLevel >= levels.size())currentLevel = 0;;
		std::ifstream in;
		in = std::ifstream(levels[currentLevel]);
		steps = std::stack<std::vector<std::vector<GridObject*>>>();
		map.clear();
		std::string line;
		int i = 0;
		while (std::getline(in, line)) {
			std::stringstream ss;
			ss << line;
			int in;
			std::vector<GridObject*> row;
			int j = 0;
			while (ss.rdbuf()->in_avail())
			{
				ss >> in;
				//std::cout << in;
				GridObject *obj;
				switch (in)
				{
				case 0:
					obj = new Empty(sf::Vector2f(j, i));
					break;
				case 1:
					obj = new Block(sf::Vector2f(j, i));
					break;
				case 2:
					TargetPosition = sf::Vector2f(j, i);
					obj = new Target(TargetPosition);
					break;
				case 3:
					PlayerPosition = sf::Vector2f(j, i);
					obj = new Player(PlayerPosition);
					break;
				default:
					break;
				}
				row.push_back(obj);
				j++;

			}
			//std::cout << "\n";
			map.push_back(row);
			i++;
		}

	}
	Game::Game(std::vector<std::string> filenames)
	{
		currentLevel = 0;
		steps = std::stack<std::vector<std::vector<GridObject*>>>();
		map = std::vector<std::vector<GridObject*>>();
		this->levels = filenames;
		LoadLevel();

	}

	Game::~Game()
	{
	}
}

