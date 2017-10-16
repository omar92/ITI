#pragma once
#include <iostream>

struct node {
	int data;
	struct node *pPrev;
	struct node *pNext;
}; 

class LinkedList
{
	struct node *pHead ;
	struct node *pTail ;
	int length;
	void freeAll(void);
public:
	struct node *createNode(int data);
	LinkedList();
	void addNode(struct node * Pnode);
	int deleteNode(int sData);
	struct node* searchNode(int sData);
	void print(void);
	int getLength(void);
	struct node* getLastNode();
	~LinkedList();
};

