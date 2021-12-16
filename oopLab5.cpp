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
	cout << "func1(Base obj): we got an object and created its copy by using copying by adress constructor\n";
};
void func2(Base* obj) {
	cout << "func2(Base* obj): we got an adress of an object\n";
};
void func3(Base& obj) {
	cout << "func3(Base* obj): we got a reference of an object\n";
};

void descFunc(Desc obj) {
	cout << "descFunc: we got a descendant object and created its copy\n";
}

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
	descFunc(descObj);		// and this function gets a Desc object and works with it correctly
	cout << "\n";

	Desc descObj2(&descObj);
	Desc descObj3(descObj2);
	cout << "\n";


	return 0;
}