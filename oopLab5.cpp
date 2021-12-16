#include <iostream>

using namespace std;
class Point {
public:
	void method1() {
		cout << "Point: method1()\n";
		method2();
	}
	/*virtual */void method2() {
		cout << "Point: method2()\n";
	}

	void overrided() {
		cout << "Point: overrided()\n";
	}
	virtual void overlappedBase() {
		cout << "Point: overrided()\n";
	}
	void overlappedDesc() {
		cout << "Point: overlappedDesc()\n";
	}

	Point() {
		cout << "Point()\n";
	}
	/*virtual */~Point() {
		cout << "~Point\n";
	}
};
class Point2D : public Point {
public:
	void method2() {
		cout << "Point2D: method2()\n";
	}
	void method3() {
		cout << "Point2D: method3()\n";
		method2();
	}
	void overrided() {
		cout << "Point2D: overrided()\n";
	}
	void overlappedBase() {
		cout << "Point2D: overlappedBase()\n";
	}
	void overlappedDesc() {
		cout << "Point2D: overridedDesc()\n";
	}

	Point2D(){
		cout << "Point2D()\n";
	}
	~Point2D() {
		cout << "~Point2D\n";
	}
};

int main()
{
	{
		cout << "Method 1 and method 2 are defined in the Base class. Method 2 is also overrided in the Descendant class." << endl
			<< "Let's check what method will be called if we create a descendant object and call method1:\n";
		Point2D p2d;
		p2d.method1();
		p2d.method3();
	}
	cout << "\n";

	cout << "The first case: creating a pointer of a Base class, object of a Base class:\n";
	Point* pointer = new Point;
	pointer->overrided();
	pointer->overlappedBase();
	pointer->overlappedDesc();
	delete pointer;
	cout << "\n";

	cout << "The second case: creating a pointer of a Descendant class, object of a Descendant class:\n";
	Point2D* pointer2D = new Point2D;
	pointer2D->overrided();
	pointer2D->overlappedBase();
	pointer2D->overlappedDesc();
	delete pointer2D;
	cout << "\n";

	cout << "The third case: creating a pointer of a Base class, object of a Descendant class:\n";
	Point* p = new Point2D;
	p->overrided();
	p->overlappedBase();
	p->overlappedDesc();
	delete p;

	return 0;
}