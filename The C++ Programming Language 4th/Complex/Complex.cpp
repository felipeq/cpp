#include "Complex.h"

double Complex::real() const
{
	return re;
}

double Complex::imag() const
{
	return im;
}

void Complex::real(double r)
{
	re = r;
}

void Complex::imag(double i)
{
	im = i;
}
Complex& Complex::operator+=(Complex z)
{
	re += z.re;
	im += z.im;
	return *this;
}

Complex & Complex::operator-=(Complex z)
{
	re -= z.re;
	im -= z.im;
	return *this;
}

Complex & Complex::operator*=(Complex z)
{
	re *= z.re;
	im *= z.im;
	return *this;
}

Complex & Complex::operator/=(Complex z)
{
	re /= z.re;
	im /= z.im;
	return *this;
}
Complex operator+(Complex a, Complex b)
{
	return a += b;
}
Complex operator-(Complex a, Complex b)
{
	return a -= b;
}
Complex operator-(Complex a)
{
	return{ -a.real(),-a.imag() };
}
