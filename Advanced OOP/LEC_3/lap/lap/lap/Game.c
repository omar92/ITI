#include "ITI.h"


#define mapDimention  10 
#define firstGame 0
#define edirLevel 1
#define Exit 2

struct point
{
	int x;
	int y;
};

struct menuItem {
	char name[20];
	void(*callBack)(int*);
};

//Variables --------------------------------------------------------------------------------------------------
int selected = 0;
char **map;
struct point playerinitPos;
struct point goal;



//functions  --------------------------------------------------------------------------------------------------
int getInput();
void drawMenu(struct menuItem *menu, int length);
void mainMenuProg();
void EditMenuProg();
void firstGameProg();
void newLevelProg();
void lvlEditorProg();
void initMap(int height, int width);
void initDefultMap();
struct menuItem* generateMainMenu(int *menuLength);
struct menuItem* generateEditorMenu(int *menuLength);
void drawMap(struct point playerPos);
int MenuProg(struct menuItem *menu, int length);
int isPointEqual(struct point a, struct point b);
void quitMenu(int* quitFlag);


void main() {
	initDefultMap();
	mainMenuProg();
}

void  mainMenuProg() {
	int quit = 0;
	do
	{
		int menuLength = 0;
		struct menuItem* menu = generateMainMenu(&menuLength);
		quit = MenuProg(menu, menuLength);
	} while (!quit);
}

void EditMenuProg() {
	int  quitFlag = 0;
	do
	{
		int menuLength = 0;
		struct menuItem* menu = generateEditorMenu(&menuLength);
		quitFlag = MenuProg(menu, menuLength);
	} while (!quitFlag);
}

int MenuProg(struct menuItem *menu, int length) {
	int quit = 0;
	drawMenu(menu, length);
	//handle input
	switch (getInput())
	{//"\t"

	case UP:
	{
		selected = (--selected >= 0 ? selected : length + selected) % length;
	}
	break;
	case DOWN:
	{
		selected = ++selected%length;
	}
	break;
	case HOME:
	{
		selected = 0;
	}
	break;
	case END:
	{
		selected = length - 1;
	}

	case ENTER: {
		clrscr();

		//handle selected
		//(selected);
		menu[selected].callBack(&quit);

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
		quit = 1;
	}
	break;
	default:
		break;
	}
	return quit;
}

int getInput() {
	char userInput = getch();

	if (userInput == EXTENDED)
	{
		userInput = getch();
	}
	return userInput;
}

struct menuItem* generateMainMenu(int *menuLength) {
	struct menuItem* menuPtr;
	struct menuItem* ptr;
	*menuLength = 3;
	menuPtr = (struct menuItem*) malloc(sizeof(struct menuItem)* (*menuLength));
	ptr = menuPtr;

	strcpy(&(ptr->name), "PLay");
	ptr->callBack = &firstGameProg;

	ptr++;
	strcpy(&(ptr->name), "Edit level");
	ptr->callBack = &EditMenuProg;

	ptr++;
	strcpy(&(ptr->name), "Exit");
	ptr->callBack = &quitMenu;


	return menuPtr;
}

struct menuItem* generateEditorMenu(int *menuLength) {
	struct menuItem* menuPtr;
	struct menuItem* ptr;
	*menuLength = 3;
	menuPtr = (struct menuItem*) malloc(sizeof(struct menuItem)* (*menuLength));
	ptr = menuPtr;

	strcpy(&(ptr->name), "New");
	ptr->callBack = &newLevelProg;

	ptr++;
	strcpy(&(ptr->name), "Edit");
	ptr->callBack = &lvlEditorProg;

	ptr++;
	strcpy(&(ptr->name), "return");
	ptr->callBack = &quitMenu;


	return menuPtr;
}
void drawMenu(struct menuItem *menu, int menuLength) {

	//draw menu 
	clrscr();
	for (int i = 0; i < menuLength; i++)
	{
		if (i == selected) {
			putsHighlighted(menu[i].name);
		}
		else
		{
			puts(menu[i].name);
		}
	}

}

void quitMenu(int* quitFlag) {
	*quitFlag = 1;
}


void initDefultMap() {

	int height = 10;
	int width = 10;

	initMap(height , width);

	map[0][1] = 1;
	map[2][0] = 1;
	map[4][4] = 1;
	map[3][9] = 1;
	map[6][6] = 1;
	map[7][5] = 1;
	map[9][8] = 1;
	goal.x = 0;
	goal.y = 0;

	playerinitPos.x = 7;
	playerinitPos.y = 6;
}

void initMap(int height,int width) {
	free(map);



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
}
void newLevelProg() {
	int height = 0;
	int width = 0;
	printf("Enter map width:\n");
	scanf("%d", &width);
	printf("Enter map height:\n");
	scanf("%d", &height);
	initMap(height,width);
	lvlEditorProg();
}

void lvlEditorProg() {
	int quitFlag = 0;
	do
	{

		drawMap(playerinitPos);
		printf("\n1: block 2: player 3:goal\n");


	} while (!quitFlag);
}

void drawMap(struct point playerPos) {
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
			else if (goal.x == x && goal.y == y) {
				printf("(W)");
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
				default:
					break;
				}
			}
		}
		printf("\n");
	}
}

void firstGameProg() {

	//	int gameMap[mapDimention][mapDimention] = { 0 };

	struct point playerPos = playerinitPos;
	int gameQuitFlag = 0;
	do
	{
		drawMap(playerPos);

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
		if (isPointEqual(playerPos, goal)) {
			clrscr();
			printf("!!!!!!!!!! Winner !!!!!!!!!!\n");
			printf("Press any key to play again \n");
			getch();
			playerPos = playerinitPos;
		}

	} while (!gameQuitFlag);
}

int isPointEqual(struct point a, struct point b) {
	return (a.x == b.x && a.y == b.y);
}

