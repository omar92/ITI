//class Base
//{
//protected:
//	int a, b;
//
//public:
//	Base(int x = 0, int y = 0) {
//		a = x; b = y;
//	}
//	
//	void setA(int x) { a = x; }
//	void setA(int y) { b = x; }
//	int getA() { return a; }
//	int getB() { return b; }
//
//	int calculateSum() {
//		return a + b;
//	}
//};
//
//class Derived : public Base
//{
//	int c;
//public:
//	Derived(int c1 = 0):Base(0,0) {
//		c = c1;
//	}
//
//	Derived(int x1, int y1, int c1) :Base(x1, y1)
//	{
//		c = c1;
//	}
//	int calculateSum() {
//	//	return a + b + c;
//		//return getA() + getB() + c;
//		return Base::calculateSum() + c;
//	}
//
//private:
//
//};
//
//
//
//void main() {
//	int x, y, z;
//	Base b1(3, 5);
//	b1.calculateSum();
//
//	Derived obj(2, 3, 5);
//	obj.calculateSum();
//}