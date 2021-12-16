#include <iostream>

using namespace std;
class Base {
public:
	int b = 3;
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
	cout << "Base func1()\n";
	Base obj;
	return obj; // here the compiler creates a copy of an obj and returns it.
				// An object that was created at the start will be deleted at the "}"

	//This way of return allows to work easily with static variabels and simple objects.
	//But when we need to return arrays, pointers or complex objects we'd better use functions,..
	//..that will return adresses or pointers.
};

Base* func2() {
	cout << "Base* func2()\n";
	Base obj;
	return &obj;		// func3 returns an adress of the created object.
						// But by the end of a field of the view of this function the object will be deleted..
						// And the pointer that will get this adress will be the hanging pointer.
};

Base& func3() {
	cout << "Base& func3()\n";
	Base obj;
	return obj;			// The same problem that was with func2.
};



Base func4() {
	cout << "Base foo4() - pointer\n";
	Base* obj = new Base;
	return *obj;					// It will create a copy of the object and return it.
									// But previous object won't be deleted. That will cause a memory leak.
}

Base* func5() {
	cout << "Base* foo5() - pointer\n";
	Base* obj = new Base;
	return obj;						// It will return an adress of the created object. But it doesn't care about its deleting.

	//This way of return allows to work with large classes and the dynamic memory faster than func1 becouse it doesn't creating many objects.
}

Base& func6() {
	cout << "Base& foo6() - pointer\n";
	Base* obj = new Base;
	return *obj;					// Almost the same. Returning a reference on the created object. Doesn't care about its deleting.
}


int main()
{	
	Base obj;
	obj = func1();					// This will work correctly.

	//Base* pBase = &func1();		// That is incorrect way of using this function. That even does not compile.
									// An object that was returned will be deleted on the next string after initialization/assignment.
									// And pTempObj now adresses to released memory.

	
	Base* pBase2 = func2();			// We got the adress of the already released memory here.
									// It will cause an error if we will work with this pointer somewhere.
	//delete pBase2;


	Base* pBase3 = &func3()	;		// The same problem that was above.
	//delete pBase3;

	//Base* tempobj = &func4();			// That does not compile.
	Base obj4;
	obj4 = func4();

	Base* pObj5 = func5();
	delete pObj5;

	Base* pObj6 = &func6();
	delete pObj6;
	return 0;
}
