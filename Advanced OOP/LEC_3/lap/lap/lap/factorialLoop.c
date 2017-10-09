//#include "ITI.h"
//
//int getFactorial(int);
//void main() {
//	int num;
//
//	printf("-- Factorial (loop) --\n");
//	printf("Enter number: ");
//	scanf("%d", &num);
//
//	printf("Factroial   -loop-    of %d = %d\n", num, getFactorial(num));
//	printf("Factroial -Recursion- of %d = %d\n", num, getFactorialR(num));
//
//	getch();
//}
//int getFactorial(int num) {
//	int fact = num;
//
//	for (num--; num > 0; num--)
//	{
//		fact *= num;
//	}
//
//	return fact;
//}
//int getFactorialR(int num) {
//
//	if (num > 1)
//		return num*getFactorialR(num-1);
//	else
//		return 1;
//}