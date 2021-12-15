#include <iostream>

using namespace std;
class Base {
public:
	
	Base() {
		cout << "Base: Base()\n";
	}
	Base(Base* obj) {
		cout << "Base: Base(Base* obj)\n";
	}
	Base(Base& obj) {
		cout << "Base: Base(Base& obj)\n";
	}
	virtual ~Base() {
		cout << "Base: ~Base()\n";
	}
};
class Desc: public Base{
public:

	Desc() {
		cout << "Desc: Desc()\n";
	}
	Desc(Desc* obj) {
		cout << "Desc: Desc(Desc* obj)\n";
	}
	Desc(Desc& obj) {
		cout << "Desc: Desc(Desc& obj)\n";
	}
	~Desc() {
		cout << "Desc: ~Desc()\n";
	}
};

void func1(Base obj) {
	cout << "We got an object and created its copy\n";
};
void func2(Base* obj) {
	cout << "We got a pointer of an object\n";
};
void func3(Base& obj) {
	cout << "We got an adress of an object\n";
};

Base func1() {
	cout << "Base func()\n";
	Base obj;
	return obj; // &obj;
};

Base* func2() {
	cout << "Base* func()\n";
	Base* obj;
	return obj;

	/*
	Base obj;
	return &obj;		- our obj will be deleted after the work of a function so we'll get a pointer to uninitialized memory
						Pointer that will get this adress will be called a hanging pointer (висячий указатель)
	*/
};

Base& func3() {
	cout << "Base& func()\n";
	Base obj;
	return obj;					
};								

int main()
{
	

	return 0;
}