#include "person.h"
int main()
{
	person a("Bjarne Stroustrup", 60);
	person b(a);   // copy constructor
	b = a;         // copy assignment operator
}