//#include "ITI.h"
//#define null 0;
//
//struct node {
//	int data;
//	struct node *pPrev;
//	struct node *pNext;
//};
//
//struct node *pHead = null;
//struct node *pTail = null;
//
//struct node *createNode();
//void displayAll(void);
//
//
//void addNodeToList(struct node * Pnode);
////struct node* searchList(int data);
////int deleteNode(int sData);
////void freeAll(void);
////int insertNodeSorted(struct node *iNode);
//
//void main(void) {
//
//	struct node * emp = createNode();
//	addNodeToList(emp);
//	displayAll();
//
//	
//}
//
//struct node *createNode() {
//	struct node *pNode;
//	pNode = (struct node*)   malloc(sizeof(struct node));
//	//fill data from user 
//	printf("Enter node data\n");
//	scanf("%d", &pNode->data);
//	pNode->pPrev = 0;
//	pNode->pNext = 0;
//	return pNode;
//}
//
//void displayAll(void) {
//	struct node *pCurr;
//	pCurr = pHead;
//	while (pCurr) {
//		printf("%d", pCurr->data);
//		pCurr = pCurr->pNext;
//	}
//}
//
//void addNodeToList(struct node * pNode) {
//	if (pHead == 0)
//	{
//		pHead = pNode;
//		pTail = pNode;
//		pNode->pPrev = null;
//		pNode->pNext = null;
//	}
//	else {
//		pNode->pPrev = pTail;
//		pTail->pNext = pNode;
//		pNode->pNext = null;
//		pTail = pNode;
//	}
//}
////
////struct node* searchList(int sData) {
////	struct node *pSearch;
////	pSearch = pHead;
////	while (pSearch->data != sData  &&    pSearch) {
////		pSearch = pSearch->pNext;
////	}
////	return pSearch;
////}
////
//
////
////void freeAll(void) {
////	struct node *pCurr;
////	while (pHead) {
////		pCurr = pHead;
////		pHead = pHead->pNext;
////		free(pCurr);
////	}
////	pHead = null;
////	pTail = null;
////}
////
////int deleteNode(int sData) {
////	int deleteFlag = 0;
////	struct node *pDelete;
////	pDelete = searchNode(sData);
////	if (pDelete) {
////		if (pHead == pTail) {
////			pHead = null;
////			pTail = null;
////		}
////		else if (pDelete == pHead) {
////			pHead = pDelete->pNext;
////			pDelete->pPrev = null;
////		}
////		else if (pDelete == pTail) {
////			pTail = pDelete->pPrev;
////			pDelete->pNext = null;
////			free(pDelete);
////		}
////		else {
////			pDelete->pPrev->pNext = pDelete->pNext;
////			pDelete->pNext->pPrev = pDelete->pPrev;
////		}
////		free(pDelete);
////		deleteFlag = 1;
////	}
////	return deleteFlag;
////}

////int insertNodeSorted(struct node *iNode) {
////	int insertFlag = 0;
////	struct node *pInsert;
////	pInsert = searchNodeAsc(iNode->data); //get node > pInser 
////	if (!pInsert) {
////		addNodeToList(pInsert);//add to end of list
////	}
////	else {
////		iNode->pPrev = pInsert->pPrev;
////		iNode->pNext = pInsert;
////		iNode->pPrev->pNext = iNode;
////		iNode->pNext->pPrev = iNode;
////	}
////	return insertFlag;
////}
////
////void freeAll(void) {
////	struct node *pCurr;
////	while (pHead) {
////		pCurr = pHead;
////		pHead = pHead->pNext;
////		free(pCurr);
////	}
////	pHead = null;
////	pTail = null;
////}
////
////int deleteNode(int sData) {
////	int deleteFlag = 0;
////	struct node *pDelete;
////	pDelete = searchNode(sData);
////	if (pDelete) {
////		if (pHead == pTail) {
////			pHead = null;
////			pTail = null;
////		}
////		else if (pDelete == pHead) {
////			pHead = pDelete->pNext;
////			pDelete->pPrev = null;
////		}
////		else if (pDelete == pTail) {
////			pTail = pDelete->pPrev;
////			pDelete->pNext = null;
////			free(pDelete);
////		}
////		else {
////			pDelete->pPrev->pNext = pDelete->pNext;
////			pDelete->pNext->pPrev = pDelete->pPrev;
////		}
////		free(pDelete);
////		deleteFlag = 1;
////	}
////	return deleteFlag;
////}
////int insertNodeSorted(struct node *iNode) {
////	int insertFlag = 0;
////	struct node *pInsert;
////	pInsert = searchNodeAsc(iNode->data); //get node > pInser 
////	if (!pInsert) {
////		addNodeToList(pInsert);//add to end of list
////	}
////	else {
////		iNode->pPrev = pInsert->pPrev;
////		iNode->pNext = pInsert;
////		iNode->pPrev->pNext = iNode;
////		iNode->pNext->pPrev = iNode;
////	}
////	return insertFlag;
////}
