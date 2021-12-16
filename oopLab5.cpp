#include <iostream>

using namespace std;
class Base {
public:
	int x = 3;
	Base() {
		cout << "Base: Base()\n";
	}
	Base(Base* obj) {
		x = obj->x;
		cout << "Base: Base(Base* obj)\n";
	}
	Base(Base& obj) {
		x = obj.x;
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
	cout << "We got an object and created its copy by using copying by adress\n";
};
void func2(Base* obj) {
	cout << "We got a pointer of an object\n";
};
void func3(Base& obj) {
	cout << "We got an adress of an object\n";
};


int main()
{
	Base obj;
	func1(obj);
	func2(&obj);
	func3(obj);
	cout << "\n";

	Base obj2(&obj);
	Base obj3(obj2);
	cout << "\n";


	Desc descObj;
	descObj.x = 5;
	func1(descObj);			// this function gets a Base object and works with it like with the object of a Base, not Desc class
	func2(&descObj);
	func3(descObj);
	cout << "\n";

	Desc descObj2(&descObj);
	Desc descObj3(descObj2);
	cout << "\n";


	return 0;
}