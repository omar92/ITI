#include "ITI.h"


#define mapDimention  10 
#define firstGame 0
#define edirLevel 1
#define Exit 2


#define empty 0 
#define block 1
#define goal 2 
#define player 3 

struct point
{
	int x;
	int y;
};

struct menuItem {
	char name[20];
	void(*callBack)(int*);
};

struct gameMap
{
	char name[20];
	struct point size;
	char **map;
	struct point startPos;
	struct point goalPos;
};

//Variables --------------------------------------------------------------------------------------------------
int selected = 0;
struct gameMap savedMap;


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
void getPLayerGoalPos(struct point *playerPos, struct point *goalPos);

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

	savedMap.size.y = 10;
	savedMap.size.x = 10;

	initMap(savedMap.size.y, savedMap.size.x);

	savedMap.map[0][1] = block;
	savedMap.map[2][0] = block;
	savedMap.map[4][4] = block;
	savedMap.map[3][9] = block;
	savedMap.map[6][6] = block;
	savedMap.map[7][5] = block;
	savedMap.map[9][8] = block;
	savedMap.map[0][0] = goal;
	savedMap.map[7][6] = player;
	savedMap.startPos.x = 7;
	savedMap.startPos.y = 6;
}

void initMap(int height, int width) {
	free(savedMap.map);



	savedMap.map = (char**)malloc(sizeof(char*)*height);
	for (int i = 0; i < height; i++)
	{
		*(savedMap.map + i) = (char*)malloc(sizeof(char)*width);
	}

	//init savedMap
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			savedMap.map[y][x] = 0;
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
	initMap(height, width);
	lvlEditorProg();
}

void lvlEditorProg() {
	int quitFlag = 0;

	struct point pointer;
	pointer.x = 0;
	pointer.y = 0;

	do
	{
		drawMap(pointer);
		printf("\n1: block 2: player 3:goal\n Enter: save");
		int s = getInput();
		switch (s)
		{
		case LEFT:
		{
			//	pointer.x = --pointer.x >= 0 ? pointer.x%mapDimention : mapDimention - pointer.x;
			pointer.x = (--pointer.x >= 0 ? pointer.x : mapDimention + pointer.x) % mapDimention;
		}
		break;
		case RIGHT:
		{
			pointer.x = ++pointer.x%mapDimention;
		}
		break;
		case UP:
		{
			//pointer.y = --pointer.y >= 0 ? pointer.y%mapDimention : mapDimention - pointer.y;
			pointer.y = (--pointer.y >= 0 ? pointer.y : mapDimention + pointer.y) % mapDimention;
		}
		break;
		case DOWN:
		{
			pointer.y = ++pointer.y%mapDimention;
		}
		break;
		case ESC:
		{
			quitFlag = 1;
		}
		break;

		case BACK_SPACE:
			savedMap.map[pointer.x][pointer.y] = empty;
			break;
		case _1:
			savedMap.map[pointer.x][pointer.y] = block;
			break;
		case _2:
			savedMap.map[pointer.x][pointer.y] = player;
			break;
		case _3:
			savedMap.map[pointer.x][pointer.y] = goal;
			break;
		default:
			printf("%d", s);
			getInput();
			break;
		}

	} while (!quitFlag);
}

void drawMap(struct point pointer) {
	//draw map
	int x, y;
	clrscr();
	for (y = 0; y < mapDimention; y++)
	{
		for (x = 0; x < mapDimention; x++)
		{
			//else if (goal.x == x && goal.y == y) {
			//	printf("(W)");
			//}
			//else
			{
				switch (savedMap.map[x][y])
				{
				case 0:
					if (x == pointer.x && y == pointer.y)
						printHighlighted(" * ");
					else
						printf(" * ");
					break;
				case 1:
					if (x == pointer.x && y == pointer.y)
						printHighlighted("[#]");
					else
						printf("[#]");
					break;
				case 2:
					if (x == pointer.x && y == pointer.y)
						printHighlighted("(W)");
					else
						printf("(W)");
					break;
				case 3:
					printHighlighted(":-)");
					break;
				default:
					break;
				}
			}
		}
		printf("\n");
	}
}

void getPLayerGoalPos(struct point *playerPos, struct point *goalPos) {

	int x = 0;
	int y = 0;



}


char **cloneMap(char **map) {
	return map;
}

void firstGameProg() {

	//	int gameMap[mapDimention][mapDimention] = { 0 };
	char **map = cloneMap(savedMap.map);
	struct point playerPos = savedMap.startPos;
	map[playerPos.x][playerPos.y] = player;
	int gameQuitFlag = 0;
	do
	{
		int won = 0;
		drawMap(playerPos);

		//handle input
		switch (getInput())
		{//"\t"
		case LEFT:
		{
			while ((playerPos.x - 1) >= 0 && map[playerPos.x - 1][playerPos.y] == empty)
			{
				map[playerPos.x][playerPos.y] = empty;
				playerPos.x--;
				map[playerPos.x][playerPos.y] = player;
			}
			if ((playerPos.x - 1) >= 0)
				won = map[playerPos.x - 1][playerPos.y] == goal ? 1 : 0;
		}
		break;
		case RIGHT:
		{
			while ((playerPos.x + 1) < mapDimention && map[playerPos.x + 1][playerPos.y] == empty)
			{
				map[playerPos.x][playerPos.y] = empty;
				playerPos.x++;
				map[playerPos.x][playerPos.y] = player;
			}
			if ((playerPos.x + 1) < mapDimention)
				won = map[playerPos.x + 1][playerPos.y] == goal ? 1 : 0;
		}
		break;
		case UP:
		{
			while ((playerPos.y - 1) >= 0 && map[playerPos.x][playerPos.y - 1] == empty)
			{
				map[playerPos.x][playerPos.y] = empty;
				playerPos.y--;
				map[playerPos.x][playerPos.y] = player;
			}
			if ((playerPos.y - 1) >= 0)
				won = map[playerPos.x][playerPos.y - 1] == goal ? 1 : 0;
		}
		break;
		case DOWN:
		{
			while ((playerPos.y + 1) < mapDimention && map[playerPos.x][playerPos.y + 1] == empty)
			{
				map[playerPos.x][playerPos.y] = empty;
				playerPos.y++;
				map[playerPos.x][playerPos.y] = player;
			}
			if ((playerPos.y + 1) < mapDimention)
				won = map[playerPos.x][playerPos.y + 1] == goal ? 1 : 0;
		}
		break;
		case ESC:
		{
			gameQuitFlag = 1;
		}
		break;
		}

		//check winning 
		if (won) {
			clrscr();
			printf("!!!!!!!!!! Winner !!!!!!!!!!\n");
			printf("Press any key to play again \n");
			getch();
			map[playerPos.x][playerPos.y] = empty;
			playerPos = savedMap.startPos;
		}
		//else {
		//	printf("map[%d][%d]=%d\n", playerPos.y, playerPos.x, map[playerPos.y][playerPos.x]);
		//	getch();
		//}

	} while (!gameQuitFlag);
}

int isPointEqual(struct point a, struct point b) {
	return (a.x == b.x && a.y == b.y);
}

