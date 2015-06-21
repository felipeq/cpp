class Complex
{
public:
	Complex(double r, double i) : re( r ), im{ i } {}
	Complex(double r) : re{ r }, im( 0 ) {}
	Complex() : re{ 0 }, im{ 0 } {}

	double real() const;
	double imag() const;
	void real(double r);
	void imag(double i);

	Complex& operator+=(Complex);
	Complex& operator-=(Complex);
	Complex& operator*=(Complex);
	Complex& operator/=(Complex);
private:
	double re, im;
};