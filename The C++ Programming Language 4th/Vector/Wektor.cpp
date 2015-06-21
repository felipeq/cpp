#include "Wektor.h"
#include <stdexcept>
#include <iostream>

Wektor::Wektor(int s)
{
	if (s < 0)
		throw std::length_error("Ujemny rozmiar tablicy!\nWektor::Wektor(int s)");
	elements = new double[s] {0};
	Wektor::s = s;
}

int Wektor::size()
{
	return s;
}

double& Wektor::operator[](int i)
{
	if (i < 0 || size() <= i)
		throw std::out_of_range("Out of range ziomek! \nVector::operator[]");
	return elements[i];
}

void Wektor::show(int i)
{
	std::cout << i << ":" << elements[i] << std::endl;
}