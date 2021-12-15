#include <iostream>

using namespace std;
class Point {
public:
	void overrided() {
		cout << "(overrided): Point";
	}
	virtual void overlappedBase() {
		cout << "(overlapped in Point): Point";
	}
	void overlappedDesc() {
		cout << "(overlapped in Point2D): Point";
	}

	Point() {
	}
	virtual ~Point() {
		cout << "~Point\n";
	}
};
class Point2D : Point {
public:
	void overrided() {
		cout << "(overrided): Point2D";
	}
	void overlappedBase() {
		cout << "(overlapped in Point): Point2D";
	}
	void overlappedDesc() {
		cout << "(overlapped in Point2D): Point2D";
	}

	Point2D(){
	}
	~Point2D() {
		cout << "~Point2D\n";
	}
};

int main()
{


	return 0;
}