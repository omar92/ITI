#include <SFML\Graphics.hpp>
#include"Game.h"

#pragma comment(lib,"sfml-window-s-d.lib" )
#pragma comment(lib,"sfml-system-s-d.lib" )
#pragma comment(lib,"sfml-graphics-s-d.lib" )

bool left, right, up, down;
int main()
{
	std::vector<std::string> levels;
	levels.push_back("Level1.txt");
	levels.push_back("Level2.txt");
	levels.push_back("Level3.txt");
	game::Game game(levels);
	game.GameLoop();



	return 0;
}