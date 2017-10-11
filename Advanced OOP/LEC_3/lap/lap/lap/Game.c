#include "ITI.h"


//#define mapDimention  10 
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
	struct point size;
	char **map;
	struct point startPos;
	struct point goalPos;
};

//Variables --------------------------------------------------------------------------------------------------

struct gameMap savedMap;


//functions  --------------------------------------------------------------------------------------------------
int getInput();
void drawMenu(struct menuItem *menu, int selected, int length);
void mainMenuProg();
void EditMenuProg();
void firstGameProg();
void newLevelProg();
void lvlEditorProg();
void initMap(int height, int width);
void initDefultMap();
struct menuItem* generateMainMenu(int *menuLength);
struct menuItem* generateEditorMenu(int *menuLength);
void drawMap(struct point playerPos, char **map, struct point size);
int MenuProg(struct menuItem *menu, int length);
int isPointEqual(struct point a, struct point b);
void quitMenu(int* quitFlag);
struct gameMap *cloneLevel(struct gameMap level);
void freeLevel(struct gameMap *level);

void main() {
	initDefultMap();
	mainMenuProg();
}

void  mainMenuProg() {
	int menuLength = 0;
	struct menuItem* menu = generateMainMenu(&menuLength);
	MenuProg(menu, menuLength);
}

void EditMenuProg() {
	int menuLength = 0;
	struct menuItem* menu = generateEditorMenu(&menuLength);
	MenuProg(menu, menuLength);
}

int MenuProg(struct menuItem *menu, int length) {
	int selected = 0;
	int quit = 0;

	do
	{
		drawMenu(menu, selected, length);
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
				//	printf("\nPress any key to continue \n");
				//	getch();
			}
		}
					break;
		case ESC:
		{
			quit = 1;
		}
		break;
		default:
			break;
		}
	} while (!quit);
	return 0;
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
void drawMenu(struct menuItem *menu, int selected, int menuLength) {

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

	savedMap.map[1][0] = block;
	savedMap.map[0][2] = block;
	savedMap.map[4][4] = block;
	savedMap.map[9][3] = block;
	savedMap.map[6][6] = block;
	savedMap.map[5][7] = block;
	savedMap.map[8][9] = block;

	savedMap.startPos.x = 6;
	savedMap.startPos.y = 7;
	savedMap.map[savedMap.startPos.y][savedMap.startPos.x] = player;

	savedMap.goalPos.x = 0;
	savedMap.goalPos.y = 0;
	savedMap.map[savedMap.goalPos.y][savedMap.goalPos.x] = goal;

}

void initMap(int height, int width) {
	free(savedMap.map);

	savedMap.size.x = width;
	savedMap.size.y = height;

	savedMap.map = (char**)malloc(sizeof(char*)*savedMap.size.y);
	for (int i = 0; i < savedMap.size.y; i++)
	{
		*(savedMap.map + i) = (char*)malloc(sizeof(char)*savedMap.size.x);
	}

	//init savedMap
	for (int y = 0; y < savedMap.size.y; y++)
	{
		for (int x = 0; x < savedMap.size.x; x++)
		{
			savedMap.map[y][x] = 0;
		}
	}

	savedMap.startPos.x = 0;
	savedMap.startPos.y = 0;
	savedMap.map[savedMap.startPos.y][savedMap.startPos.x] = player;

	savedMap.goalPos.x = 0;
	savedMap.goalPos.y = 1;
	savedMap.map[savedMap.goalPos.y][savedMap.goalPos.x] = goal;
}

void freeMap(char** map, struct point size) {

	for (int i = 0; i < size.y; i++)
	{
		free(map[i]);
	}
	free(map);
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
	struct gameMap *level = cloneLevel(savedMap);
	struct point pointer;
	pointer.x = 0;
	pointer.y = 0;

	do
	{
		drawMap(pointer, level->map, level->size);
		printf("\n1: block 2: player 3:goal\n Enter: save");
		int s = getInput();
		switch (s)
		{
		case LEFT:
		{
			//	pointer.x = --pointer.x >= 0 ? pointer.x%mapDimention : mapDimention - pointer.x;
			pointer.x = (--pointer.x >= 0 ? pointer.x : level->size.x + pointer.x) % level->size.x;
		}
		break;
		case RIGHT:
		{
			pointer.x = ++pointer.x%level->size.x;
		}
		break;
		case UP:
		{
			//pointer.y = --pointer.y >= 0 ? pointer.y%mapDimention : mapDimention - pointer.y;
			pointer.y = (--pointer.y >= 0 ? pointer.y : level->size.y + pointer.y) % level->size.y;
		}
		break;
		case DOWN:
		{
			pointer.y = ++pointer.y%level->size.y;
		}
		break;
		case ENTER:
			//freeLevel(&savedMap);
			savedMap = *level;
		case ESC:
		{
			quitFlag = 1;
		}
		break;

		case BACK_SPACE:
			if (level->map[pointer.y][pointer.x] == block)
				level->map[pointer.y][pointer.x] = empty;
			break;
		case _1:
			if (level->map[pointer.y][pointer.x] == empty)
				level->map[pointer.y][pointer.x] = block;
			else
				level->map[pointer.y][pointer.x] = empty;
			break;
		case _2:
			level->map[level->startPos.y][level->startPos.x] = empty;
			level->startPos.x = pointer.x;
			level->startPos.y = pointer.y;
			level->map[level->startPos.y][level->startPos.x] = player;

			break;
		case _3:
			level->map[level->goalPos.y][level->goalPos.x] = empty;
			level->goalPos.x = pointer.x;
			level->goalPos.y = pointer.y;
			level->map[level->goalPos.y][level->goalPos.x] = goal;
			break;
		default:
			printf("%d", s);
			getInput();
			break;
		}

	} while (!quitFlag);
}

void drawMap(struct point pointer, char **map, struct point size) {
	//draw map
	int x, y;
	clrscr();
	for (y = 0; y < size.y; y++)
	{
		for (x = 0; x < size.x; x++)
		{
			switch (map[y][x])
			{
			case empty:
				if (x == pointer.x && y == pointer.y)
					printHighlighted(" * ");
				else
					printf(" * ");
				break;
			case block:
				if (x == pointer.x && y == pointer.y)
					printHighlighted("[#]");
				else
					printf("[#]");
				break;
			case goal:
				if (x == pointer.x && y == pointer.y)
					printHighlighted("(W)");
				else
					printf("(W)");
				break;
			case player:
				printHighlighted(":-)");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

struct gameMap *cloneLevel(struct gameMap level) {
	struct gameMap* lvlCpy = (struct gameMap*) malloc(sizeof(struct gameMap));
	*lvlCpy = level;

	char ** newMap = (char**)malloc(sizeof(char*)*lvlCpy->size.y);
	for (int i = 0; i < lvlCpy->size.y; i++)
	{
		*(newMap + i) = (char*)malloc(sizeof(char)*lvlCpy->size.x);
	}
	//copy to newMap
	for (int y = 0; y < lvlCpy->size.y; y++)
	{
		for (int x = 0; x < lvlCpy->size.x; x++)
		{
			newMap[y][x] = level.map[y][x];
		}
	}

	lvlCpy->map = newMap;
	return lvlCpy;
}

void freeLevel(struct gameMap *level) {
	freeMap(level->map, level->size);
	free(level);
}

void firstGameProg() {

	//	int gameMap[mapDimention][mapDimention] = { 0 };
	struct gameMap *level = cloneLevel(savedMap);
	char **map = level->map;
	struct point playerPos = level->startPos;
	int gameQuitFlag = 0;
	do
	{
		int won = 0;
		drawMap(playerPos, map, level->size);

		//handle input
		switch (getInput())
		{//"\t"
		case LEFT:
		{
			struct point start = playerPos;
			while ((playerPos.x - 1) >= 0 && map[playerPos.y][playerPos.x - 1] != block)
			{
				playerPos.x--;
			}
			won = map[playerPos.y][playerPos.x] == goal ? 1 : 0;
			map[start.y][start.x] = empty;
			map[playerPos.y][playerPos.x] = player;
		}
		break;
		case RIGHT:
		{
			struct point start = playerPos;
			while ((playerPos.x + 1) < level->size.x && map[playerPos.y][playerPos.x + 1] != block)
			{
				playerPos.x++;
			}
			won = map[playerPos.y][playerPos.x] == goal ? 1 : 0;
			map[start.y][start.x] = empty;
			map[playerPos.y][playerPos.x] = player;
		}
		break;
		case UP:
		{
			struct point start = playerPos;
			while ((playerPos.y - 1) >= 0 && map[playerPos.y - 1][playerPos.x] != block)
			{
				playerPos.y--;
			}
			won = map[playerPos.y][playerPos.x] == goal ? 1 : 0;
			map[start.y][start.x] = empty;
			map[playerPos.y][playerPos.x] = player;
		}
		break;
		case DOWN:
		{
			struct point start = playerPos;
			while ((playerPos.y + 1) < level->size.y && map[playerPos.y + 1][playerPos.x] != block)
			{
				playerPos.y++;
			}
			won = map[playerPos.y][playerPos.x] == goal ? 1 : 0;
			map[start.y][start.x] = empty;
			map[playerPos.y][playerPos.x] = player;
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

			freeLevel(level);
			level = cloneLevel(savedMap);
			map = level->map;
			playerPos = level->startPos;
		}

	} while (!gameQuitFlag);


}

int isPointEqual(struct point a, struct point b) {
	return (a.x == b.x && a.y == b.y);
}

