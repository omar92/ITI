#include "oMath.h"


Complex::Complex()
{
	img = 0;
	real = 0;
}

void Complex::set(float real, float img)
{
	this->real = real;
	this->img = img;
}

void Complex::setReal(float real)
{
	this->real = real;
}

void Complex::setImg(float img)
{
	this->img = img;
}
float Complex::getImg() {
	return img;
}

void Complex::print()
{
	if (img >= 0)
		std::cout << real << "+" << img << "i\n";
	else
		std::cout << real << "-" << std::abs(img) << "i\n";
}

Complex Complex::operator=(Complex &c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex Complex::operator+(Complex &c)
{
	Complex ret;

	ret.real = real + c.real;
	ret.img = img + c.img;
	return ret;
}
Complex Complex::operator+(int c)
{
	Complex ret;

	ret.real = real + c;
	ret.img = img;
	return ret;
}
Complex Complex::operator-(Complex &c)
{
	Complex ret;

	ret.real = real - c.real;
	ret.img = img - c.img;
	if (ret.img < 0) {
		ret.img = 0;
	};
	return ret;
}
Complex Complex::operator++()
{
	real++;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex  r = *this;
	real++;
	return r;
}
Complex Complex::operator--()
{
	return Complex();
}
Complex Complex::operator--(int)
{
	Complex  r = *this;
	real--;
	return r;
}
int Complex::operator==(Complex &c)
{
	return ((real == c.real) && (img = c.img));
}
int Complex::operator>(Complex &c)
{
	return ((real >= c.real) && (img > c.img));
}
int Complex::operator<(Complex &c)
{
	return ((real <= c.real) && (img < c.img));
}
float Complex::getReal() {
	return real;
}

Complex operator+(float f, Complex &c)
{
	Complex ret;
	ret.real = f + c.real;
	ret.img = c.img;
	return ret;
}
