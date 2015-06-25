#include <string>
#include <fstream>

class OpenFile {
public:
	OpenFile(const char* filename) {
		//throws an exception on failure
		_file.open(filename);
	}

	~OpenFile() {
		_file.close();
	}

	std::string readLine() {
		std::string line;
		getline(_file, line);
		return line;
	}

private:
	std::ifstream _file;
};