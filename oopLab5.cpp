﻿#include <iostream>

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

Base func1();
Base* func2();
Base& func3();
Base& better_func3(Base& obj);


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

	
	func1();
	func2();
	Base* pBase = &func3();
	//delete pBase;			// this thing will delete uninitialized memory and will cause an error
	pBase = &better_func3(obj);
	pBase = &better_func3(descObj);
	cout << "\n";

	return 0;
}



Base func1() {
	cout << "Base func()\n";
	Base obj;
	return obj; // here the compiler creates a copy of an obj and returns it

	//This way of return allows to work easily with static variabels and simple objects.
	//But when we need to return arrays, pointers or complex objects we'd better use functions,..
	//..that will return adresses or pointers.
};

Base* func2() {
	cout << "Base* func()\n";
	Base* obj = nullptr;
	return obj;

	/*
	Base obj;			If we create a static object here and will try to return it we'll face the problem.
	return &obj;		Our obj will be deleted after the work of a function so we'll get a pointer to uninitialized memory.
						Pointer that will get this adress will be called a hanging pointer (висячий указатель).
	*/

	//This way of returning allows to return an adress on the dynamically initialized memory.
	//But if we want to work with static objects and return some of them, we need to be careful..
	//..and avoid the creating of hanging pointers.
};

Base& func3() {
	cout << "Base& func()\n";
	Base obj;
	return obj;			// obj returns by an adress.
						// But by the end of a field of view of this function object obj will be deleted..
						// And the pointer that will get this adress will be the hanging pointer.
};
Base& better_func3(Base& obj) {
	cout << "Base& func(Base& obj)\n";
	return obj;			// And here we won't get in the result any hanging pointers.

	//This way of return also allows to return an adress on the dynamically initialized memory.
	//It also have the same problems with hanging pointers.
	//Better use this way of return with getting some parameters as adresses.
}