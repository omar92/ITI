#include "ITI.h"


#define MenuLength  2
#define mapDimention  10 
#define firstGame 0
#define Exit 1

struct point
{
	int x;
	int y;
};

//Variables --------------------------------------------------------------------------------------------------
char menu[MenuLength][20] = { "first game" ,"Exit" };
int selected = 0;
int QuitFlag = 0;
char **map;
struct point playerPos;


//functions  --------------------------------------------------------------------------------------------------
int getInput();
void drawMenu();
void handleSelected(int selected);
void firstGameProg();
void lvlEditorProg();
void initDefultMap();
void main() {
	initDefultMap();
	do
	{
		drawMenu();

		//handle input
		switch (getInput())
		{//"\t"

		case UP:
		{
			selected = (--selected >= 0 ? selected : MenuLength + selected) % MenuLength;
		}
		break;
		case DOWN:
		{
			selected = ++selected%MenuLength;
		}
		break;
		case HOME:
		{
			selected = 0;
		}
		break;
		case END:
		{
			selected = MenuLength - 1;
		}

		case ENTER: {
			clrscr();

			//handle selected
			handleSelected(selected);

			if (selected != Exit)
			{
				printf("Press any key to continue \n");
				getch();
			}
		}
					break;
		case ESC:
		{
			printf("ESC");
			QuitFlag = 1;
		}
		break;
		default:
			break;
		}

	} while (!QuitFlag);

}

int getInput() {
	char userInput = getch();

	if (userInput == EXTENDED)
	{
		userInput = getch();
	}
	return userInput;
}

void drawMenu() {

	//draw menu 
	clrscr();
	for (int i = 0; i < MenuLength; i++)
	{
		if (i == selected) {
			putsHighlighted(menu[i]);
		}
		else
		{
			puts(menu[i]);
		}
	}

}

void handleSelected(int selected) {
	switch (selected)
	{
	case firstGame:
	{
		firstGameProg();
	}
	break;
	case Exit:
	{
		QuitFlag = 1;

	}
	break;

	default:
		break;
	}

}

void initDefultMap() {
	int height = 10;
	int width = 10;
	map = (char**)malloc(sizeof(char*)*height);
	for (int i = 0; i < height; i++)
	{
		*(map + i) = (char*)malloc(sizeof(char)*width);
	}

	//init map
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			map[y][x] = 0;
		}
	}
	map[0][1] = 1;
	map[2][0] = 1;
	map[4][4] = 1;
	map[3][9] = 1;
	map[6][6] = 1;
	map[7][5] = 1;
	map[9][8] = 1;
	map[0][0] = 2;

	playerPos.x = 7;
	playerPos.y = 6;
}


void lvlEditorProg() {

}

void firstGameProg() {





//	int gameMap[mapDimention][mapDimention] = { 0 };

	int gameQuitFlag = 0;
	do
	{
		//draw map
		int x, y;
		clrscr();
		for (y = 0; y < mapDimention; y++)
		{
			for (x = 0; x < mapDimention; x++)
			{
				if (playerPos.x == x && playerPos.y == y) {
					printHighlighted(":-)");
				}
				else
				{
					switch (map[x][y])
					{
					case 0:
						printf("| |");
						break;
					case 1:
						printf("|X|");
						break;
					case 2:
						printf("(W)");
						break;
					default:
						break;
					}
				}
			}
			printf("\n");
		}

		//handle input
		switch (getInput())
		{//"\t"
		case LEFT:
		{
			while ((playerPos.x - 1) >= 0 && map[playerPos.x - 1][playerPos.y] != 1)
			{
				playerPos.x--;
			}
		}
		break;
		case RIGHT:
		{
			while ((playerPos.x + 1) < mapDimention && map[playerPos.x + 1][playerPos.y] != 1)
			{
				playerPos.x++;
			}
		}
		break;
		case UP:
		{
			while ((playerPos.y - 1) >= 0 && map[playerPos.x][playerPos.y - 1] != 1)
			{
				playerPos.y--;
			}
		}
		break;
		case DOWN:
		{
			while ((playerPos.y + 1) < mapDimention && map[playerPos.x][playerPos.y + 1] != 1)
			{
				playerPos.y++;
			}
		}
		break;
		case ESC:
		{
			gameQuitFlag = 1;
		}
		break;
		}

		//check winning 
		if (map[playerPos.x][playerPos.y] == 2) {
			clrscr();
			printf("!!!!!!!!!! Winner !!!!!!!!!!\n");
			printf("Press any key to play again \n");
			getch();
			playerPos.x = 7;
			playerPos.y = 6;
		}

	} while (!gameQuitFlag);
}