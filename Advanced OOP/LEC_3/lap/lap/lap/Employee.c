#include "ITI.h"
#define dataLength 5
#define nameLength 20
struct employee
{
	int code;
	char name[nameLength];
	int age;
	float salary;
	float something;
	float net;
};

struct point
{
	int x;
	int y;
};




//Variables --------------------------------------------------------------------------------------------------
#define MenuLength  3
char menu[MenuLength][20] = { "New","Display","Exit" };
int selected = 0;
#define New 0
#define Display 1
#define Exit 2

int QuitFlag = 0;
char data[][20] = { "Name:","Age:","salary:","deduction:","Net:" };
void drawEmpData(struct point pos, struct point padding);
struct point get_pos(int index, int coloums, struct point pos, struct point padding);
int getCharIndex(char character, char string[], int length);
void goToElement(int i, struct point pos, struct point padding);
void addEmployeeProg(struct employee *employeeList, int length);
void displayEmployeeProg(struct employee *employeeList, int length);

struct employee *employeeList;
void main() {
	int employeeNum = 0;

	printf("-- Employees -- \n\n");
	printf("Enter employee number\n");
	scanf("%d", &employeeNum);


	employeeList = (struct employee*) malloc(sizeof(struct employee)*employeeNum);
	struct employee *employeePtr = employeeList;
	printf("%d slots created \nPress any key to continue\n", employeeNum);

	getInput();
	do
	{
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
		break;
		case ENTER:
		{
			clrscr();
			switch (selected)
			{
			case New:

				addEmployeeProg(employeeList, employeeNum);

				break;
			case Display:
				displayEmployeeProg(employeeList, employeeNum);
				break;
			case Exit:
				QuitFlag = 1;
				break;
			}

			if (!QuitFlag) {
				printf("Press any key to continue \n");
				getch();
			}
		}
		break;
		case ESC:
		{
			QuitFlag = 1;
		}
		}

	} while (!QuitFlag);

	free(employeeList);
}



void addEmployeeProg(struct employee *employeeList, int length) {
	int i = 0;

	struct employee empData;

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
		strcpy(empData.name, input);
		i++;
	}
	{
		goToElement(i, start, padding);
		int input = 0;
		scanf("%d", &input);
		empData.age = input;

		strcpy(&empData.age, &input);
		i++;
	}
	{
		goToElement(i, start, padding);
		float input = 0.0;
		scanf("%f", &input);
		empData.salary = input;
		i++;
	}
	{
		goToElement(i, start, padding);
		float input = 0.0;
		scanf("%f", &input);
		empData.something = input;
		i++;
	}
	{
		goToElement(i, start, padding);
		printf("%f\n", empData.salary - empData.something);
		i++;
	}

	int descision = -1;
	do
	{
		printf("\nEnter save slot (1 -> %d)\nEnter 0 to quit\n", length);
		scanf("%d", &descision);

		if (descision <= length) {
			employeeList[descision - 1] = empData;
			descision = 0;
		}
	} while (descision);


}

void displayEmployeeProg(struct employee *employeeList, int length) {
	int descision;
	do
	{
		printf("\nEnter slot number (1 -> %d)\nEnter 0 to quit\n", length);
		scanf("%d", &descision);

		if (descision <= length) {
			struct employee empData= employeeList[descision - 1];
			descision = 0;


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
				puts(empData.name);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%d\n", empData.age);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData.salary);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData.something);
				i++;
			}
			{
				goToElement(i, start, padding);
				printf("%f\n", empData.salary - empData.something);
				i++;
			}
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