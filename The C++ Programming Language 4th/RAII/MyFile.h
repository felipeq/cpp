#pragma once
#include <string>
#include <fstream>

class MyFile {
public:
	MyFile() {}

	~MyFile() {
		if (_file.is_open()) {
			_file.close();
		}
	}

	void open(const char* filename) {
		_file.open(filename);
	}

	bool isOpen() const {
		return _file.is_open();
	}

	void close() {
		if (_file.is_open()) {
			_file.close();
		}
	}

	std::string readLine()
	{
		std::string line;
		getline(_file, line);
		return line;
	}

private:
	std::ifstream _file;
};
