#pragma once
#include <iostream>
class Complex
{
	float img;
	float real;
public:
	Complex();
	void set(float, float);
	void setReal(float);
	void setImg(float);
	float getReal();
	float getImg();
	void print();

	Complex operator = (Complex &c);
	Complex operator + (Complex &c);
	Complex operator + (int c);
	friend Complex operator + (float f, Complex &c);
	Complex operator - (Complex &c);
	Complex operator ++ ();
	Complex operator ++(int);
	Complex operator -- ();
	Complex operator -- (int);
	int operator == (Complex &c);
	int  operator > (Complex &c);
	int  operator < (Complex &c);

	friend std::ostream& operator<<(std::ostream& os, Complex &c)
	{
		os << c.real << (c.img < 0.0 ? "" : "+") << c.img << "i";
		return os;
	};

	friend std::istream& operator>>(std::istream& is, Complex &c)
	{	
		is >> c.real >> c.img;
		return is;
	};

};
