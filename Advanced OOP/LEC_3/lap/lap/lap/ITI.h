#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

#ifdef __GNUG__
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#else
#include <windows.h>
#include <conio.h>
#endif


#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define HOME 71
#define END 79
#define ENTER 13 
#define ESC 27
#define EXTENDED -32

void gotoxy(int x, int y) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos;
	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(hConsole, pos);
}

void printHighlighted(char*str) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;

	///* Save current attributes */
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY); \
		printf("%s", str);
	consoleInfo.wAttributes = saved_attributes;
	SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_INTENSITY);
}

void putsHighlighted(char*str) {
	printHighlighted(str);
	printf("\n");
}
unsigned char getKey() {
	return _getch();
}

void clrscr() {
	system("cls");
}
