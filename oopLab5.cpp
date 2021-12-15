#include <iostream>

using namespace std;
class Point {
public:
	void overrided() {
		cout << "(overrided): Point\n";
	}
	virtual void overlappedBase() {
		cout << "(overlapped in Point): Point\n";
	}
	void overlappedDesc() {
		cout << "(overlapped in Point2D): Point\n";
	}

	Point() {
		cout << "Point()\n";
	}
	virtual ~Point() {
		cout << "~Point\n";
	}
};
class Point2D : public Point {
public:
	void overrided() {
		cout << "(overrided): Point2D\n";
	}
	void overlappedBase() {
		cout << "(overlapped in Point): Point2D\n";
	}
	void overlappedDesc() {
		cout << "(overlapped in Point2D): Point2D\n";
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
	cout << "The first case: creating a pointer of a Base class, object of a Base class:\n";
	Point* pointer = new Point;
	pointer->overrided();
	pointer->overlappedBase();
	pointer->overlappedDesc();
	delete pointer;

	cout << "The second case: creating a pointer of a Descendant class, object of a Descendant class:\n";
	Point2D* pointer2D = new Point2D;
	pointer2D->overrided();
	pointer2D->overlappedBase();
	pointer2D->overlappedDesc();
	delete pointer2D;

	cout << "The second case: creating a pointer of a Base class, object of a Descendant class:\n";
	Point* p = new Point2D;
	p->overrided();
	p->overlappedBase();
	p->overlappedDesc();
	delete p;

	return 0;
}