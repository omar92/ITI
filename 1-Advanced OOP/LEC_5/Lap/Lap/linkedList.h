#pragma once
#include <iostream>
template <class T>
struct node {
	T data;
	struct node<T> *pPrev;
	struct node<T> *pNext;
}; 

template <class T>
class LinkedList
{
	struct node<T> *pHead ;
	struct node<T> *pTail ;
	int length;
	//void freeAll(void);
public:
	LinkedList();
	void addNode(struct node<T> * Pnode);
	struct node<T> *createNode(T data);

	//template <class T>
	//int deleteNode(T data);

	//template <class T>
	//struct node<T>* searchNode(T sData);

	//template <class T>
	//void print(void);

	//template <class T>
	//int getLength(void);

	//template <class T>
	//struct node<T>* getLastNode();

	//template <class T>
	//node<T> * getFirstNode();

	~LinkedList();
};

