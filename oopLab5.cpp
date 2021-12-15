#include <iostream>

using namespace std;
class Point {
public:
	string overrided() {
		return "(overrided): Point";
	}
	virtual string overlappedBase() {
		return "(overlapped in Point): Point";
	}
	string overlappedDesc() {
		return "(overlapped in Point2D): Point";
	}
	Point() {
	}
	virtual ~Point() {
	}
};
class Point2D : Point {
public:
	string overrided() {
		return "(overrided): Point2D";
	}
	string overlappedBase() {
		return "(overlapped in Point): Point2D";
	}
	virtual string overlappedDesc() {
		return "(overlapped in Point2D): Point2D";
	}
	Point2D(){
	}
	~Point2D() {
	}
};
class Point3D : Point2D {
public:
	string overrided() {
		return "(overrided): Point3D";
	}
	string overlappedBase() {
		return "(overlapped in Point): Point3D";
	}
	virtual string overlappedDesc() {
		return "(overlapped in Point2D): Point3D";
	}
	Point3D() {
	}
	~Point3D() {
	}
};

int main()
{


	return 0;
}