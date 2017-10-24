#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	pHead = 0;
	pTail = 0;
}

template <class T>
void LinkedList<T>::addNode(node<T> * pNode)
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
//
//template <class T>
//void LinkedList<T>::print(void) {
//	struct node<T> *pSearch;
//	pSearch = pHead;
//	while (pSearch) {
//		std::cout << pSearch->data << "\n";
//		pSearch = pSearch->pNext;
//	}
//}
//
//template <class T>
//int LinkedList::getLength(void)
//{
//	return length;
//}
//
//template <class T>
//node<T> * LinkedList<T>::getLastNode()
//{
//	return pTail;
//}
//
//template <class T>
//node<T> * LinkedList<T>::getFirstNode()
//{
//	return pHeads;
//}
//
template <class T>
node<T> * LinkedList<T>::createNode(T data)
{
	node<T> * pNode = new node<T>();
	//fill data from user 
	pNode->data = data;
	pNode->pPrev = 0;
	pNode->pNext = 0;

	return pNode;
}
//
//template <class T>
//int LinkedList<T>::deleteNode(T sData) {
//	int deleteFlag = 0;
//	node<T> *pDelete;
//	pDelete = searchNode(sData);
//	if (pDelete) {
//		if (pHead == pTail) {
//			pHead = 0;
//			pTail = 0;
//		}
//		else if (pDelete == pHead) {
//			pHead = pDelete->pNext;
//			pDelete->pPrev = 0;
//		}
//		else if (pDelete == pTail) {
//			pTail = pDelete->pPrev;
//			pDelete->pNext = 0;
//		}
//		else {
//			pDelete->pPrev->pNext = pDelete->pNext;
//			pDelete->pNext->pPrev = pDelete->pPrev;
//		}
//		delete pDelete;
//		deleteFlag = 1;
//	}
//	length--;
//	return deleteFlag;
//}
//
//template <class T>
//node<T> * LinkedList<T>::searchNode(T sData)
//{
//	struct node *pSearch;
//	pSearch = pHead;
//	while (pSearch->data != sData  &&    pSearch) {
//		pSearch = pSearch->pNext;
//	}
//	return pSearch;
//}
//
////template <class T>
////void LinkedList::freeAll(void)
////{
////	//struct node *pCurr;
////	//while (pHead) {
////	//	pCurr = pHead;
////	//	pHead = pHead->pNext;
////	//	free(pCurr);
////	//}
////	//pHead = 0;
////	//pTail = 0;
////}
//
//template <class T>
//LinkedList<T>::~LinkedList()
//{
//	freeAll();
//}
