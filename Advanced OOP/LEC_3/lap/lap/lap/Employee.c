#include "ITI.h"
#define dataLength 5
#define nameLength 20
#define null 0

struct employeeList
{
	struct employee *pHead;
	struct employee *pTail;
};

struct employee
{
	int code;
	char name[nameLength];
	int age;
	float salary;
	float something;
	float net;

	struct employee *pPrev;
	struct employee *pNext;
};

struct menuItem {
	char name[20];
	void(*callBack)(int*);
};

struct point
{
	int x;
	int y;
};


//Variables --------------------------------------------------------------------------------------------------

char data[][20] = { "Name:","Age:","salary:","deduction:","Net:" };
void drawEmpData(struct point pos, struct point padding);
struct point get_pos(int index, int coloums, struct point pos, struct point padding);
int getCharIndex(char character, char string[], int length);
void goToElement(int i, struct point pos, struct point padding);
void addEmployeeProg();
void addNodeToList(struct employee * pNode);
void displayEmployeeProg();
struct employee* searchList(int sCode);
struct menuItem* generateMainMenu(int *menuLength);
void quitMenu(int* quitFlag);
void  mainMenuProg();
void displayAll();
void deleteEmployeeProg();
int deleteNode(int sData);
struct employee* searchNodeAsc(int sCode);
struct employeeList empList;

void main() {
	empList.pHead = null;
	empList.pTail = null;
	mainMenuProg();
	//	free(empList.list);
}


void  mainMenuProg() {
	int menuLength = 0;
	struct menuItem* menu = generateMainMenu(&menuLength);
	MenuProg(menu, menuLength);
}

struct menuItem* generateMainMenu(int *menuLength) {
	struct menuItem* menuPtr;
	struct menuItem* ptr;
	*menuLength = 4;
	menuPtr = (struct menuItem*) malloc(sizeof(struct menuItem)* (*menuLength));
	ptr = menuPtr;

	strcpy(&(ptr->name), "Add");
	ptr->callBack = &addEmployeeProg;

	ptr++;
	strcpy(&(ptr->name), "Display");
	ptr->callBack = &displayEmployeeProg;

	ptr++;
	strcpy(&(ptr->name), "Delete");
	ptr->callBack = &deleteEmployeeProg;

	ptr++;
	strcpy(&(ptr->name), "Exit");
	ptr->callBack = &quitMenu;


	return menuPtr;
}

void quitMenu(int* quitFlag) {
	*quitFlag = 1;
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

			//if (selected != Exit)
			//{
			//	//	printf("\nPress any key to continue \n");
			//	//	getch();
			//}
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

struct employee *createNode() {
	struct employee *pNode;
	pNode = (struct employee*)   malloc(sizeof(struct employee));
	//fill data from user 
	printf("Enter Employee Code\n");
	scanf("%d", &pNode->code);
	pNode->pPrev = null;
	pNode->pNext = null;
	return pNode;
}



void addEmployeeProg() {
	int i = 0;

	struct employee *empData = createNode();

	struct point start;
	start.x = 5;
	start.y = 5;

	struct point padding;
	padding.x = 30;
	padding.y = 3;

	drawEmpData(start, padding);

	{
		goToElement(i, start, padding);
		char input[nameLength] = { 0 };
		scanf("%s", input);
		strcpy(empData->name, input);
		i++;
	}
	{
		goToElement(i, start, padding);
		int input = 0;
		scanf("%d", &input);
		empData->age = input;

		strcpy(&empData->age, &input);
		i++;
	}
	{
		goToElement(i, start, padding);
		float input = 0.0;
		scanf("%f", &input);
		empData->salary = input;
		i++;
	}
	{
		goToElement(i, start, padding);
		float input = 0.0;
		scanf("%f", &input);
		empData->something = input;
		i++;
	}
	{
		goToElement(i, start, padding);
		printf("%f\n", empData->salary - empData->something);
		i++;
	}

	int descision = -1;
	do
	{
		printf("\nEnter 1 to save \nEnter 0 to quit\n");
		scanf("%d", &descision);

		if (descision == 1) {

			insertNodeSorted(empData);
			descision = 0;
		}
		else {
			free(empData);
		}
	} while (descision);

}

int insertNodeSorted(struct employee *iNode) {
	int insertFlag = 0;
	struct employee *pInsert;
	pInsert = searchNodeAsc(iNode->code); //get node > pInser 
	if (!pInsert) {
		addNodeToList(iNode);//add to end of list
	}
	else {
		iNode->pPrev = pInsert->pPrev;
		iNode->pNext = pInsert;
		if (pInsert->pPrev) {
			pInsert->pPrev->pNext = iNode;
		}
		else {
			empList.pHead = iNode;
		}
		pInsert->pPrev = iNode;

	}
	return insertFlag;
}

void addNodeToList(struct employee * pNode) {
	if (empList.pHead == 0)
	{
		empList.pHead = pNode;
		empList.pTail = pNode;
		pNode->pPrev = null;
		pNode->pNext = null;
	}
	else {
		pNode->pPrev = empList.pTail;
		empList.pTail->pNext = pNode;
		pNode->pNext = null;
		empList.pTail = pNode;
	}
}
void displayAll(void) {
	struct employee *pCurr;
	pCurr = empList.pHead;
	while (pCurr) {
		printf("%d:\t%s\n", pCurr->code, pCurr->name);
		pCurr = pCurr->pNext;
	}
}

struct employee* searchList(int sCode) {
	struct employee *pSearch;
	pSearch = empList.pHead;
	while (pSearch && pSearch->code != sCode) {
		pSearch = pSearch->pNext;
	}
	return pSearch;
}

struct employee* searchNodeAsc(int sCode) {
	struct employee *pSearch;
	pSearch = empList.pHead;
	while (pSearch && pSearch->code < sCode) {
		pSearch = pSearch->pNext;
	}
	return pSearch;
}

void displayEmployeeProg() {
	int descision;
	do
	{
		clrscr();
		displayAll();
		printf("Enter employe code to view details\nEnter 0 to quit\n");
		scanf("%d", &descision);
		struct employee *empData = searchList(descision);
		if (descision > 0 && empData) {

			struct point start;
			start.x = 5;
			start.y = 5;

			struct point padding;
			padding.x = 30;
			padding.y = 3;

			drawEmpData(start, padding);
			int i = 0;
			{
				goToElement(i, start, padding);
				puts(empData->name);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%d\n", empData->age);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData->salary);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData->something);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData->salary - empData->something);
				i++;
			}

			printf("Press any key to continue ..\n");
			getInput();
		}

	} while (descision);
}

int deleteNode(int sData) {
	int deleteFlag = 0;
	struct employee *pDelete;
	pDelete = searchList(sData);
	if (pDelete) {
		if (empList.pHead == empList.pTail) {
			empList.pHead = null;
			empList.pTail = null;
		}
		else if (pDelete == empList.pHead) {
			empList.pHead = pDelete->pNext;
			pDelete->pPrev = null;
		}
		else if (pDelete == empList.pTail) {
			empList.pTail = pDelete->pPrev;
			pDelete->pNext = null;
			free(pDelete);
		}
		else {
			pDelete->pPrev->pNext = pDelete->pNext;
			pDelete->pNext->pPrev = pDelete->pPrev;
		}
		free(pDelete);
		deleteFlag = 1;
	}
	return deleteFlag;
}

void deleteEmployeeProg() {
	int descision;
	do
	{
		clrscr();
		displayAll();
		printf("Enter employe code to delete\nEnter 0 to quit\n");
		scanf("%d", &descision);
		if (descision > 0) {

			if (deleteNode(descision)) {
				printf("Deleted successfully  ..\n");
			}
			else
			{
				printf("Delete faild ..\n");
			}

			printf("Press any key to continue ..\n");
			getInput();
		}

	} while (descision);
}

struct point get_pos(int index, int coloums, struct point pos, struct point padding) {
	struct point element_pos;
	element_pos.x = pos.x + (index % coloums)* padding.x;
	element_pos.y = pos.y + (index / coloums)* padding.y;
	return element_pos;
}

void drawEmpData(struct point pos, struct point padding) {
	int i = 0;
	for (i = 0; i < dataLength; i++)
	{
		struct point element_pos = get_pos(i, 2, pos, padding);
		gotoxy(element_pos.x, element_pos.y);
		puts(data[i]);
	}
}

void goToElement(int i, struct point pos, struct point padding) {
	struct point element_pos = get_pos(i, 2, pos, padding);
	gotoxy(element_pos.x + getCharIndex('\0', data[i], nameLength) + 1, element_pos.y);
}

int getCharIndex(char character, char string[], int length) {
	int index = 0;
	while (index < length && string[index] != character)
	{
		index++;
	}
	return index != length ? index : -1;
}

int getInput() {
	char userInput = getch();

	if (userInput == EXTENDED)
	{
		userInput = getch();
	}
	return userInput;
}