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
};

Base* func2() {
};

Base& func3() {
};

int main()
{
	

	return 0;
}