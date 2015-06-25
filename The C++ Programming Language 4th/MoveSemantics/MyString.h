#pragma once
#include <cstring>

class MyString
{
public:
	MyString();
	MyString(const char* data)
	{
		size_t size = strlen(data) + 1;
		this->data = new char[size];
		memcpy(this->data, data, size);
	}
	MyString(const MyString& that)
	{
		size_t size = strlen(that.data) + 1;
		data = new char[size];
		memcpy(this->data, that.data, size);

	}
	MyString(MyString&& that)
	{
		this->data = that.data;
		that.data = nullptr;
	}
	~MyString()
	{
		delete[] data;
	};
private:
	char* data;
};

