//#include "ITI.h"
//#define UP 72
//#define DOWN 80
//#define RIGHT 77
//#define LEFT 75
//#define HOME 71
//#define END 79
//#define ENTER 13 
//#define ESC 27
//#define EXTENDED -32
//#define MenuLength  5
//
////Variables --------------------------------------------------------------------------------------------------
//char menu[MenuLength][20] = { "factorial(loop)","factorial(recursive)","employee","first game" ,"Exit" };
//#define Array 0
//#define Olympics 1
//#define firstGame 2
//#define Exit 3
//
//int selected = 0;
//int QuitFlag = 0;
////GAME DATA
//#define mapDimention  10 
//
////functions  --------------------------------------------------------------------------------------------------
//int getInput();
//
//void main() {
//
//	do
//	{
//		//draw menu 
//		clrscr();
//		for (int i = 0; i < MenuLength; i++)
//		{
//			if (i == selected) {
//				putsHighlighted(menu[i]);
//			}
//			else
//			{
//				puts(menu[i]);
//			}
//		}
//
//		//handle input
//		switch (getInput())
//		{//"\t"
//
//		case UP:
//		{
//			selected = (--selected >= 0 ? selected : MenuLength + selected) % MenuLength;
//		}
//		break;
//		case DOWN:
//		{
//			selected = ++selected%MenuLength;
//		}
//		break;
//		case HOME:
//		{
//			selected = 0;
//		}
//		break;
//		case END:
//		{
//			selected = MenuLength - 1;
//		}
//
//		case ENTER: {
//			clrscr();
//			//handle selected
//			switch (selected)
//			{
//			case Array:
//			{
//				int arr[10] = { 0 };
//				int  i = 0;
//				printf("PLease Enter array elements\n");
//				for (i = 0; i < 10; i++)
//				{
//					printf("element %d = \n", i + 1);
//					scanf("%d", &arr[i]);
//				}
//				printf("array elements\n");
//				for (i = 0; i < 10; i++)
//				{
//					printf("element %d = %d \n", i + 1, arr[i]);
//				}
//			}
//			break;
//			case Olympics:
//			{
//				printf("Olympics");
//			}
//			break;
//			case firstGame:
//			{
//				int gameMap[mapDimention][mapDimention] = { 0 };
//				gameMap[0][1] = 1;
//				gameMap[2][0] = 1;
//				gameMap[4][4] = 1;
//				gameMap[3][9] = 1;
//				gameMap[6][6] = 1;
//				gameMap[7][5] = 1;
//				gameMap[9][8] = 1;
//				gameMap[0][0] = 2;
//
//				int playerPos[2] = { 7,6 };
//
//				int gameQuitFlag = 0;
//				do
//				{
//					//draw map
//					int x, y;
//					clrscr();
//					for (y = 0; y < mapDimention; y++)
//					{
//						for (x = 0; x < mapDimention; x++)
//						{
//							if (playerPos[0] == x && playerPos[1] == y) {
//								printHighlighted(":-)");
//							}
//							else
//							{
//								switch (gameMap[x][y])
//								{
//								case 0:
//									printf("| |");
//									break;
//								case 1:
//									printf("|X|");
//									break;
//								case 2:
//									printf("(W)");
//									break;
//								default:
//									break;
//								}
//							}
//						}
//						printf("\n");
//					}
//
//					//handle input
//					switch (getInput())
//					{//"\t"
//					case LEFT:
//					{
//						while ((playerPos[0] - 1) >= 0 && gameMap[playerPos[0] - 1][playerPos[1]] != 1)
//						{
//							playerPos[0]--;
//						}
//					}
//					break;
//					case RIGHT:
//					{
//						while ((playerPos[0] + 1) < mapDimention && gameMap[playerPos[0] + 1][playerPos[1]] != 1)
//						{
//							playerPos[0]++;
//						}
//					}
//					break;
//					case UP:
//					{
//						while ((playerPos[1] - 1) >= 0 && gameMap[playerPos[0]][playerPos[1] - 1] != 1)
//						{
//							playerPos[1]--;
//						}
//					}
//					break;
//					case DOWN:
//					{
//						while ((playerPos[1] + 1) < mapDimention && gameMap[playerPos[0]][playerPos[1] + 1] != 1)
//						{
//							playerPos[1]++;
//						}
//					}
//					break;
//					case ESC:
//					{
//						gameQuitFlag = 1;
//					}
//					break;
//					}
//
//					//check winning 
//					if (gameMap[playerPos[0]][playerPos[1]] == 2) {
//						clrscr();
//						printf("!!!!!!!!!! Winner !!!!!!!!!!\n");
//						printf("Press any key to play again \n");
//						getch();
//						playerPos[0] = 7;
//						playerPos[1] = 6;
//					}
//
//				} while (!gameQuitFlag);
//			}
//			break;
//			case Exit:
//			{
//				QuitFlag = 1;
//
//			}
//			break;
//
//			default:
//				break;
//			}
//			if (selected != Exit)
//			{
//				printf("Press any key to continue \n");
//				getch();
//			}
//		}
//					break;
//		case ESC:
//		{
//			printf("ESC");
//			QuitFlag = 1;
//		}
//		break;
//		default:
//			break;
//		}
//
//	} while (!QuitFlag);
//
//}
//
//int getInput() {
//	char userInput = getch();
//
//	if (userInput == EXTENDED)	
//	{
//		userInput = getch();
//	}
//	return userInput;
//}