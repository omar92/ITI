#include "ITI.h"
#define defult_choice -1
//#include <stdio.h>

int choice = defult_choice, close_app = 0;

void main() {

	do
	{
		//system("CLS");

		printf("\nselect app");
		printf("\n1- Hellow world");
		printf("\n2- show ascii");
		printf("\n3- dec to hex");
		printf("\n4- sum to 100");
		printf("\n5- size of");
		printf("\n6- choice menu -- not implemented");
		printf("\n7- magic squares");
		printf("\n0- EXIT");
		printf("\n\n");

		scanf("%d", &choice);
		char t = getchar();
		printf("\n\n");

		switch (choice)
		{
		case 1:
		{
			printf("Hellow world");

		}break;
		case 2:
		{
			char input_char = ' ';
			printf("enter character ");
			scanf("%C", &input_char);
			printf("Character: %C  --> ASCII: %d ", input_char, input_char);

		}break;
		case 3:
		{
			int input_decimal = ' ';
			printf("enter decimal num ");
			scanf("%d", &input_decimal);
			printf("decimal: %d  --> hex: %x ", input_decimal, input_decimal);

		}break;
		case 4:
		{
			int i = 0, sum = 0;
			while (sum <100)
			{
				sum += i++;
			}
			printf("sum: %d  ", sum);

		}break;
		case 5:
		{
			printf("size of char : %d \n", sizeof(char));
			printf("size of int : %d \n", sizeof(int));
			printf("size of long int : %d \n", sizeof(long long int));
			printf("size of short int : %d \n", sizeof(short int));
			printf("size of float : %d \n", sizeof(float));
			printf("size of byte : %d \n", sizeof(byte));


		}break;
		case 7: //magic box
		{
			//initial values
			int col = 0, row = 0;
			int padding = 4;
			//get box size
			int width = 0;

			do
			{
				printf("Enter box width Odd num and num must be > 3\n");
				scanf("%d", &width);
			} while (!(width%2) && width>3);



			//set starting col and row
			col = width - 1;
			row = width / 2;
			system("CLS");

			//write first square
			gotoxy(col * padding, row * padding);
			printf("%d", 1);
			//	printf("-%d", 0 % width);
			//printf("%d,%d", col, row);


			//write next squars
			for (int i = 1; i < width*width; i++)
			{
				if (i % width) {
					col = (col + 1) % width;
					row = (row + 1) % width;
				}
				else {
					int n_row = row - 1;
					row = n_row >= 0 ? n_row   % width : width + n_row;
				}

				gotoxy(col*padding, row*padding);
				printf("%d", i + 1);
			}

			gotoxy(0, width*padding + 1);

		}break;
		case 0:
		{
			close_app = 1;
		}break;
		default:
			break;
		}


		choice = defult_choice;
	} while (!close_app);
}
