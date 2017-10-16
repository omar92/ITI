//class  GeoShape
//{
//protected:
//	float dim1, dim2;
//public:
//	GeoShape(float f1, float f2) {
//		dim1 = f1; dim2 = f2;
//	}
//
//	void setDim1(float f1) {
//		dim1 = f1;
//	}
//
//	void setDim2(float f2) {
//		dim2 = f2;
//	}
//
//	float getDim1() { return dim1; }
//	float getDim2() { return dim2; }
//
//	float calculatedArea() {
//		return 0.0;
//	}
//
//private:
//
//};
//
//
//class Rectangle : public  GeoShape
//{
//public:
//	Rectangle(int l, int w) :GeoShape(l, w) {
//
//	}
//
//	float calculatedArea() {
//		return dim1*dim2;
//	}
//
//	void setRadius(int r) {
//		dim1 = r; dim2 = r;
//	}
//};
//
//class Circle : protected  GeoShape
//{
//public:
//	Circle(int r) :GeoShape(r, r) {
//
//	}
//
//	float calculatedArea() {
//		return (22 / 7)*dim1*dim2;
//	}
//
//	void setRadius(int r) {
//		dim1 = r; dim2 = r;
//	}
//};
//
//
//
//class Square : protected  Rectangle
//{
//public:
//	Square(int l) :Rectangle(l, l) {
//
//	}
//
//	void setLength(int l) {
//		dim1 = l; dim2 = l;
//	}
//
//	float calculatedArea() {
//		return Rectangle::calculatedArea();
//	}
//};
//
//void main() {
//	Circle c1(5);
//	c1.calculatedArea();
//
//	//c1.setDim1() // is worng -- so in circle  we changed inheretence of GeoShape to protected
//	//  even if we will override setDim functions original function can still b accessed throught 
//	// c1.GeoShape::setDim1(2);
//	//so we must add the inheretence access level to protected to prevent this 
//	c1.setRadius(20);
//
//
//}