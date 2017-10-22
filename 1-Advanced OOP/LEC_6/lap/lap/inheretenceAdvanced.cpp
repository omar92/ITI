#include <iostream>

class  GeoShape
{
protected:
	float dim1, dim2;
public:
	GeoShape(float f1, float f2) {
		dim1 = f1; dim2 = f2;
	}

	virtual void setDim1(float f1) {
		dim1 = f1;
	}

	virtual void setDim2(float f2) {
		dim2 = f2;
	}

	float getDim1() { return dim1; }
	float getDim2() { return dim2; }

	virtual float calculatedArea() {
		return 0.0;
	}

private:

};


class Rectangle : public  GeoShape
{
public:
	Rectangle(int l, int w) :GeoShape(l, w) {

	}

	virtual float calculatedArea() {
		return dim1*dim2;
	}

};

class Circle : public  GeoShape
{
public:
	Circle(int r) :GeoShape(r, r) {

	}

	virtual float calculatedArea() {
		return (22 / 7)*dim1*dim2;
	}

	void setRadius(int r) {
		dim1 = r; dim2 = r;
	}

	void setDim1(float f1) {
		dim1 = f1; dim2 = f1;
	}

	void setDim2(float f2) {
		dim1 = f2; dim2 = f2;
	}
};



class Square : public  Rectangle
{
public:
	Square(int l) :Rectangle(l, l) {

	}

	void setLength(int l) {
		dim1 = l; dim2 = l;
	}

	void setDim1(float f1) {
		dim1 = f1; dim2 = f1;
	}

	void setDim2(float f2) {
		dim1 = f2; dim2 = f2;
	}

	virtual float calculatedArea() {
		return Rectangle::calculatedArea();
	}
};


float sumAreas(GeoShape* s1, GeoShape* s2, GeoShape* s3) {
	printf("%f\n", s1->calculatedArea());
	printf("%f\n", s2->calculatedArea());
	printf("%f\n", s3->calculatedArea());
	return s1->calculatedArea() + s2->calculatedArea() + s3->calculatedArea();

}

float sumAreas(GeoShape** shapes, int length) {
	float sum=0;
	int i = 0;
	for (i = 0; i < length; i++)
	{
		sum += shapes[i]->calculatedArea();
	}
	return sum;

}

void main() {


	Circle c1(5);
	printf("%f\n", c1.calculatedArea());

	//c1.setDim1() // is worng -- so in circle  we changed inheretence of GeoShape to protected
	//  even if we will override setDim functions original function can still b accessed throught 
	// c1.GeoShape::setDim1(2);
	//so we must add the inheretence access level to protected to prevent this 
	c1.setRadius(20);
	printf("%f\n", c1.calculatedArea());

	Rectangle r1(5, 6);

	Square s3(5);

	printf("%f\n", sumAreas(&c1, &r1, &s3));

	GeoShape** shapes = new (GeoShape*[3]);
	shapes[0] = new Circle(20);
	shapes[1] = new Rectangle (5, 6);
	shapes[2] = new Square (5);
	
	printf("%f\n", sumAreas(shapes,3));
	//getchar();
}