#pragma once
#include <iostream>
#include "linkedList.h"
using namespace std;

class Stack {

	LinkedList ll;
public:

	Stack() {  //constructor
		//LinkedList ll;
		
	}

	void push(int);
	int pop();
	void print();
	~Stack() {    //distructor

	}

};

//class Stack {
//
//	struct stackElement {
//		int data;
//		stackElement *next;
//		stackElement *prev;
//	};
//
//
//	int *stk;
//	int tos;  //top of stack
//	static int  counter;
//	int size;
//public:
//	
//	Stack() {  //constructor
//		tos = 0;
//		size = 5;
//		stk = new int[size];
//		counter++;
//	}
//	Stack(int z) {   //constructor
//		tos = 0;
//		size = z;
//		stk = new int[size];
//		counter++;
//	}
//	Stack(Stack&);
//	static int  getCounter() { return counter; }
//	void push(int);
//	int pop();
//	int getTos() { return tos; }
//	// friend  viewContent ( Stack );  // friend means that the function can access class 	private variables 
//
//	//friend Stack operator = (Stack &y);
//
//	~Stack() {    //distructor
//		delete[] stk;
//		counter--;
//	}
//};

void  viewContent(Stack z);