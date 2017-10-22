///*
//
//TopCoder -- usaco
//
//
//*/
//
//
//#include "ITI.h"
//
//#define  size 5
//
//struct menuItem {
//	char name[20];
//	void(*callBack)(int*);
//};
//
//void  mainMenuProg();
//struct menuItem* generateMainMenu(int *menuLength);
//void quitMenu(int* quitFlag);
//void drawMenu(struct menuItem *menu, int selected, int menuLength);
//int MenuProg(struct menuItem *menu, int length);
//int getInput();
//
//void bubbleSort(int arr[], int arrSize);
//void bubbleSortProg();
//
//void insertionSort(int numbers[], int arrSize);
//void insertionSortProg();
//
//void quickSortProg();
//void quickSort(int a[], int l, int r);
//int partition(int a[], int l, int r);
//
//void printArrayInt(int arr[], int length);
//
//void main() {
//	mainMenuProg();
//}
//
//void  mainMenuProg() {
//	int menuLength = 0;
//	struct menuItem* menu = generateMainMenu(&menuLength);
//	MenuProg(menu, menuLength);
//}
//
//struct menuItem* generateMainMenu(int *menuLength) {
//	struct menuItem* menuPtr;
//	struct menuItem* ptr;
//	*menuLength = 4;
//	menuPtr = (struct menuItem*) malloc(sizeof(struct menuItem)* (*menuLength));
//	ptr = menuPtr;
//
//	strcpy(&(ptr->name), "Bubble Sort");
//	ptr->callBack = &bubbleSortProg;
//
//	ptr++;
//	strcpy(&(ptr->name), "Insertion Sort");
//	ptr->callBack = &insertionSortProg;
//
//	ptr++;
//	strcpy(&(ptr->name), "quick Sort");
//	ptr->callBack = &quickSortProg;
//
//	ptr++;
//	strcpy(&(ptr->name), "Exit");
//	ptr->callBack = &quitMenu;
//
//
//	return menuPtr;
//}
//
//void quitMenu(int* quitFlag) {
//	*quitFlag = 1;
//}
//
//void drawMenu(struct menuItem *menu, int selected, int menuLength) {
//
//	//draw menu 
//	clrscr();
//	for (int i = 0; i < menuLength; i++)
//	{
//		if (i == selected) {
//			putsHighlighted(menu[i].name);
//		}
//		else
//		{
//			puts(menu[i].name);
//		}
//	}
//
//}
//
//int MenuProg(struct menuItem *menu, int length) {
//	int selected = 0;
//	int quit = 0;
//
//	do
//	{
//		drawMenu(menu, selected, length);
//		//handle input
//		switch (getInput())
//		{//"\t"
//
//		case UP:
//		{
//			selected = (--selected >= 0 ? selected : length + selected) % length;
//		}
//		break;
//		case DOWN:
//		{
//			selected = ++selected%length;
//		}
//		break;
//		case HOME:
//		{
//			selected = 0;
//		}
//		break;
//		case END:
//		{
//			selected = length - 1;
//		}
//		break;
//		case ENTER: {
//			clrscr();
//
//			//handle selected
//			//(selected);
//			menu[selected].callBack(&quit);
//
//			if (quit != 1)
//			{
//				printf("\npress any key to continue \n");
//				getch();
//			}
//		}
//					break;
//		case ESC:
//		{
//			quit = 1;
//		}
//		break;
//		default:
//			break;
//		}
//	} while (!quit);
//
//	free(menu);
//	return 0;
//}
//
//void bubbleSortProg() {
//	int arr[5] = { 36,35,48,97,25 };
//	printArrayInt(arr, 5);
//	bubbleSort(arr, 5);
//	printArrayInt(arr, 5);
//}
//
//void bubbleSort(int arr[], int arrSize) {
//	int i = 0; int run = 1;
//	int sorted = 0;
//	while (!sorted) {
//		sorted = 1;
//		for (i = 0; i < arrSize - run; i++) {
//			if (arr[i] > arr[i + 1]) {
//				swapInt(&arr[i], &arr[i + 1]);
//				sorted = 0;
//			}
//		}
//		run++;
//	}
//}
//
//void insertionSortProg() {
//	int arr[5] = { 36,35,48,97,25 };
//	printArrayInt(arr, 5);
//	insertionSort(arr, 5);
//	printArrayInt(arr, 5);
//}
//
//void insertionSort(int numbers[], int arrSize) {
//	int i, j, index;
//	for (i = 0; i < arrSize; i++) {
//		index = numbers[i];
//		j = i - 1;
//		while ((j >= 0) && (numbers[j] > index))
//		{
//			numbers[j + 1] = numbers[j];
//			j = j - 1;
//		}
//		numbers[j + 1] = index;
//	}//end of for loop
//}//end of func
//
//
//void quickSortProg() {
//	int arr[9] = { 7, 12, 1, -2, 0, 15, 4, 11, 9 };
//	printArrayInt(arr, 9);
//	quickSort(arr, 0, 8);
//	printArrayInt(arr, 9);
//}//end of func
//
//void quickSort(int a[], int l, int r) {
//	int j;
//
//	if (l < r)
//	{
//		// divide and conquer
//		j = partition(a, l, r);
//		quickSort(a, l, j - 1);
//		quickSort(a, j + 1, r);
//	}
//}
//
//int partition(int a[], int l, int r) {
//	int pivot, i, j;
//	pivot = a[l];
//	i = l; j = r + 1;
//	while (1)
//	{
//		do ++i; while (a[i] <= pivot && i <= r);
//		do --j; while (a[j] > pivot);
//		if (i >= j) break;
//		swapInt(&a[i], &a[j]);
//	}
//	swapInt(&a[l], &a[j]);
//	return j;
//}
//
//
//void printArrayInt(int arr[], int length) {
//	int i = 0;
//	printf("[");
//	for (i = 0; i < length; i++) {
//		if (i != 0)
//			printf(",");
//		printf(" %d", arr[i]);
//	}
//	printf("]\n");
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