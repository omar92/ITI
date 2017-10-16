////lec 6
//class Point {
//	float x, y;
//public:
//	Point(float x1 = 0, float y1 = 0) {
//		x = x1; y = y1;
//	}
//	Point(Point &p) {
//		x = p.x; y = p.y;
//	}
//
//	void setX(float x1) { x = x1; }
//	void setY(float y1) { x = y1; }
//	float getX() { return x; }
//	float getY() { return y; }
//
//};
//
//
//
//class Circle
//{
//	int radius;
//	Point center;
//public:
//	//Circle() :center(50,50) // : == empedded opeject  // center(50,50) initialise defult val in constructor //COMPOSITION
//	//{
//	//	radius = 25;
//	//};
//	//Circle(int x1 , int y1 , int r) :center(x1, y1) // to construct Point call before  the constructor of Circle
//	//{
//	//	radius = r;
//	//};
//	Circle(int x1 = 50, int y1 = 50, int r = 25) :center(x1, y1) // all in one
//	{
//		radius = r;
//	};
//
//	void draw() {
//		circle(center.getX(), center.getY(), radius);
//	}
//
//private:
//
//};
//
//class Rectangle
//{
//	Point ul;
//	Point lr;
//public:
//	Rectangle(int x1 = 50, int y1 = 50, int x2 = 50, int y2 = 50) :ul(x1, y1), lr(x1, y2)
//	{
//
//	};
//	Rectangle(Point p1, Point p2) :ul(p1), lr(p2) // all in one
//	{
//	};
//
//	void draw() {
//		rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
//	}
//};
//
//class Line
//{
//	Point p1;
//	Point p2;
//public:
//	Line(int x1 = 50, int y1 = 50, int x2 = 50, int y2 = 50) :p1(x1, y1), p2(x1, y2)
//	{
//
//	};
//	Line(Point p1, Point p2) :p1(p1), p2(p2) // all in one
//	{
//	};
//
//	void draw() {
//		line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
//	}
//};
//
//
//class Picture
//{
//	int cNum;
//	int lNum;
//	int rNum;
//
//	Circle *pCircles;
//	Rectangle *pRects;
//	Line *pLines;
//
//public:
//	Picture(int c = 0, int r = 0, int l = 0) {
//		cNum = c; rNum = r; lNum = l;
//		pCircles = 0; pRects = 0; pLines = 0;
//	}
//	Picture(int c, int r, int l, Circle *pc, Rectangle *pr, Line * pl) {
//		cNum = c; rNum = r; lNum = l;
//		pCircles = pc; pRects = pr; pLines = pl;
//	}
//
//	void setCircles(int c, Circle *pc) {
//		cNum = c;
//		pCircles = pc;
//	}
//
//	void paint() {
//		int i;
//		for ( i = 0; i < cNum; i++)
//		{
//			pCircles[i].draw();
//		}
//		for (i = 0; i < rNum; i++)
//		{
//			pRects[i].draw();
//		}
//		for (i = 0; i < lNum; i++)
//		{
//			pLines[i].draw();
//		}
//
//	}
//
//	~Picture() {
//
//	}
//
//private:
//
//};
//
//
//
//void circle(int, int, int);
//void rectangle(int, int, int, int);
//void line(int, int, int, int);
//
//void main() {
//	Circle c1(100, 100, 50);
//	c1.draw();
//
//	Circle c2[2] = {
//		Circle(100,100,10),
//		Circle(50,50,20)
//	};
//
//	Picture p1;
//	p1.setCircles(2, c2);
//	p1.paint();
//}