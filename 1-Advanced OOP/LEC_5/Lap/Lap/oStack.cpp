//
//#include "oStack.h"
//template <class T>
//void Stack::push(T val)
//{
//	ll.addNode(ll.createNode(val));
//}
//template <class T>
//int Stack::pop()
//{
//	int lastNodeData = ll.getLastNode()->data;
//	ll.deleteNode(lastNodeData);
//	return lastNodeData;
//}
//template <class T>
//void Stack::print()
//{
//	ll.print();
//}
//template <class T>
//void  viewContent(Stack<T> z)
//{
//	z.print();
//}
//
////int Stack::counter = 0; // to init  the static variable inside the class 
////
//////Stack Stack:: operator = (Stack &z) {
//////	// use &z as i wont change any thing in z 
//////	//so i dont call create constructor and delete consturtor 					//to create copy at z 
//////	int i;
//////	delete[]stk;
//////	tos = z.tos;
//////	size = z.size;
//////	stk = new int[size];
//////	for (i = 0; o < tos; i++) {
//////		stk[i] = z.stk[i];
//////	}
//////	return *this;
//////}
////
////Stack::Stack(Stack &h) { // h is the original object that a new coppy is made from 
////	int i = 0;
////	this->tos = h.tos; //how to use this is like this line 
////	size = h.size;
////	counter++;
////	this->stk = new int[size];
////	for (i = 0; i < tos; i++) {
////		stk[i] = h.stk[i];
////	}
////}
////void Stack::push(int n) {
////	if (tos == size) {
////		cout << "stack full";
////	}
////	else {
////		stk[tos] = n;
////		tos++;
////	}
////}
////int Stack::pop() {
////	int ret = -1;
////	if (tos < 0) {
////		cout << "stack empty";
////	}
////	else {
////		tos--;
////		ret = stk[tos];
////	}
////	return ret;
////}
////
////void  viewContent(Stack);
//////void main(void)
//////{
//////	Stack s1;
//////	s1.push(7);
//////	s1.push(9);
//////	cout << s1.pop();
//////	cout << Stack::getCounter();
//////	viewContent(s1);
//////}
////
////void  viewContent(Stack z)
////{
////	int n = z.getTos();
////	int i = 0;
////	for (i = 0; i < n; i++) {
////		cout << z.pop();
////	}
////}