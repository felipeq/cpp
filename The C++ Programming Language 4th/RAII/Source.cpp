#include <iostream>
#include <fstream>
#include "Jamnik.h"
#include "Lock.h"
#include "MyFile.h"
#include "OpenFile.h"
void loadFromFile(std::ofstream&);
void loadFromFile(MyFile&);
void loadFromFile(OpenFile&);
void goToThePark(Pies*);
Lock getLock();
void doSomething();

std::string firstLineOf_Stack(const char* filename) {
	OpenFile f("boo.txt"); //stack allocated
	return f.readLine();
	//File closed here. `f` goes out of scope and destructor is run.
}

std::string firstLineOf_Heap(const char* filename) {
	OpenFile* f = new OpenFile("boo.txt"); //heap allocated
	return f->readLine();
	//DANGER WILL ROBINSON! Destructor is never run, because `f` is never
	//deleted
}

int main()
{
	std::ofstream  f;
	f.open("boo.txt");
	//UNSAFE - an exception here means the file is never closed
	loadFromFile(f);
	f.close();

	Pies* dog = new Jamnik();
	//UNSAFE - an exception here means the dog is never deleted
	goToThePark(dog);
	delete dog;

	Lock lock = getLock();
	lock.aquire();
	//UNSAFE - an exception here means the lock is never released
	doSomething();
	lock.release();

	MyFile f2;
	f2.open("boo.txt");
	//SAFE - The MyFile destructor is guaranteed to run
	loadFromFile(f2);

	OpenFile f3("boo.txt");
	//SAFE - exception safe, and no closing necessary
	loadFromFile(f3);
}