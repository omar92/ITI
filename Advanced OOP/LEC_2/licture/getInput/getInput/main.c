#include <stdio.h>;
#include <conio.h>;
#include <string.h>

void main() {

	while (1)
	{
		char ch;
		ch = getch();
		if (ch == -32) {
			printf("extended");
			ch = getch();
			printf("key = %d", ch);
		}
		else
		{
			printf("normal key= %d", ch);
		}

		printf("\n");
		//getch();
	}

}
