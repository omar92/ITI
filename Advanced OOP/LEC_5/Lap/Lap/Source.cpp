#include <iostream>
#include <math.h>
#include "oMath.h"
#include "oStack.h"
using namespace std;

void complexProg();
void main() {

	Stack s1;
	s1.push(7);
	s1.push(9);
	cout << s1.pop()<<"\n";
	cout << s1.pop() << "\n";
//	cout << Stack::getCounter() << "\n";
//	viewContent(s1);

	// complexProg();
}

void complexProg() {
	Complex complex;

	complex.set(5, 8);

	complex.print();

	complex++;

	complex.print();

	complex = complex + complex;

	complex.print();

	complex.setImg(-3);

	complex.print();

	complex = complex + 5;

	complex.print();

	complex = 2.3 + complex;

	complex.print();

	//complex << "5 6i";
	//string x;
	//complex >>x;
}