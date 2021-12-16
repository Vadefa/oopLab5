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

Base func1() {
	cout << "Base func()\n";
	Base obj;


	return obj; // here the compiler creates a copy of an obj and returns it.
				// An object that was created at the start will be deleted at the "}"

	//This way of return allows to work easily with static variabels and simple objects.
	//But when we need to return arrays, pointers or complex objects we'd better use functions,..
	//..that will return adresses or pointers.
};

Base* func2() {
	cout << "Base* func()\n";
	Base obj;
	return &obj;		// func3 returns an adress of the created object.
						// But by the end of a field of the view of this function the object will be deleted..
						// And the pointer that will get this adress will be the hanging pointer.
};


Base& func3() {
	cout << "Base& func()\n";
	Base obj;
	return obj;			// The same problem that was with func2.
};

Base foo4();
Base* foo5();
Base& foo6();

int main()
{	
	Base obj;
	obj = func1()	;				// This will be work.

	
	//Base* pBase = &func1();		// That is incorrect way of using this function. That even does not compile.
									// An object that was returned will be deleted on the next string after initialization/assignment.
									// And pTempObj now adresses to released memory.

	
	Base* pBase2 = func2();			// We got the adress of the already released memory here.
									// It will cause an error if we will work with this pointer somewhere.


	Base* pBase3 = &func3()	;		// The same problem that was above.


	//Base* pObj = &foo4();
	Base* pObj2 = foo5();
	delete pObj2;
	Base* pObj3 = &foo6();
	delete pObj3;
	return 0;
}

Base foo4() {
	cout << "Base foo4() - pointer\n";
	Base* obj = new Base;
	return obj;
}

Base* foo5() {
	cout << "Base* foo5() - pointer\n";
	Base* obj = new Base;
	return obj;
}

Base& foo6() {
	cout << "Base& foo6() - pointer\n";
	Base* obj = new Base;
	return *obj;
}