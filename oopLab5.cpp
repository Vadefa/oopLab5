#include <iostream>

using namespace std;
class Point {
public:
	
	void method1() {
		cout << "Point: Method1()\n";
		method2();
	}
	/*virtual */void method2() {
		cout << "Point: Method2()\n";
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
	void method2() {
		cout << "Point2d: Method2();\n";
	}

	Point2D(){
		cout << "Point2d()\n";
	}
	~Point2D() {
		cout << "~Point2D\n";
	}
};

int main()
{
	Point2D pointer2d;
	pointer2d.method1();

	return 0;
}