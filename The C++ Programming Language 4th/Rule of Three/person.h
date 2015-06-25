#include <string>

class person
{


public:

	person(const char* name, int age) : _age(age)
	{
		_name = new char[strlen(name) + 1];
		strcpy(_name, name);
	}
	// copy construct
	person(const person& that) : _age(that._age)
	{
		_name = new char[strlen(that._name) + 1];
		strcpy(_name, that._name);
	}
	// copy assignment operator
	person& operator=(const person& that)
	{
		char* copied_name = new char[strlen(that._name) + 1];
		strcpy(copied_name, that._name);
		delete[] _name;
		_name = copied_name;
		_age = that._age;
		return *this;
	}
	~person()
	{
		delete[] _name;
	}
private:
	char* _name;
	int _age;
	// Some resources cannot or should not be copied, such as file handles or mutexes.
//private:
//
//	person(const person& that);
//	person& operator=(const person& that);
};