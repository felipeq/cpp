#include "Wektor.h"
#include <cmath>
#include <filesystem>
#include <iostream>

namespace Math
{
	double sqrt_sum(Wektor&);
}

void show(Wektor&, int);

int main()
{
	try
	{
		Wektor w(INT_MAX);
		for (int i = 0; i < 6; i++)
			show(w, i);
	}
	catch (std::bad_alloc& ex)
	{
		std::cout << "Za duzy rozmiar kolekcji!\n" << ex.what() << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	system("pause");
}
double Math::sqrt_sum(Wektor& w)
{
	double sum = 0;
	for (auto i = 0; i < w.size(); ++i)
	{
		sum += sqrt(w[i]);
	}
	return sum;
}

void show(Wektor& wektor, int i)
{
	std::cout << i << ":" << wektor[i] << std::endl;
}