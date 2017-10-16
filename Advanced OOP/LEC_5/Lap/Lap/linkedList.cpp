#include "LinkedList.h"

LinkedList::LinkedList()
{
	pHead = 0;
	pTail = 0;
}

void LinkedList::addNode(node * pNode)
{
	if (pHead == 0)
	{
		pHead = pNode;
		pTail = pNode;
		pNode->pPrev = 0;
		pNode->pNext = 0;
	}
	else {
		pNode->pPrev = pTail;
		pTail->pNext = pNode;
		pNode->pNext = 0;
		pTail = pNode;
	}
	length++;
}

void LinkedList::print(void) {
	struct node *pSearch;
	pSearch = pHead;
	while (pSearch) {
		std::cout << pSearch->data << "\n";
		pSearch = pSearch->pNext;
	}
}

int LinkedList::getLength(void)
{
	return length;
}

node * LinkedList::getLastNode()
{
	return pTail;
}

node * LinkedList::createNode(int data)
{
	node *pNode = new node();
	//fill data from user 
	pNode->data = data;
	pNode->pPrev = 0;
	pNode->pNext = 0;

	return pNode;
}

int LinkedList::deleteNode(int sData) {
	int deleteFlag = 0;
	node *pDelete;
	pDelete = searchNode(sData);
	if (pDelete) {
		if (pHead == pTail) {
			pHead = 0;
			pTail = 0;
		}
		else if (pDelete == pHead) {
			pHead = pDelete->pNext;
			pDelete->pPrev = 0;
		}
		else if (pDelete == pTail) {
			pTail = pDelete->pPrev;
			pDelete->pNext = 0;
		}
		else {
			pDelete->pPrev->pNext = pDelete->pNext;
			pDelete->pNext->pPrev = pDelete->pPrev;
		}
		delete pDelete;
		deleteFlag = 1;
	}
	length--;
	return deleteFlag;
}

node * LinkedList::searchNode(int sData)
{
	struct node *pSearch;
	pSearch = pHead;
	while (pSearch->data != sData  &&    pSearch) {
		pSearch = pSearch->pNext;
	}
	return pSearch;
}

void LinkedList::freeAll(void)
{
	//struct node *pCurr;
	//while (pHead) {
	//	pCurr = pHead;
	//	pHead = pHead->pNext;
	//	free(pCurr);
	//}
	//pHead = 0;
	//pTail = 0;
}

LinkedList::~LinkedList()
{
	freeAll();
}
