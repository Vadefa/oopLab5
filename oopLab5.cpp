#include <iostream>

using namespace std;
class Point {
public:
	
	Point() {
	}
	virtual ~Point() {
		cout << "~Point\n";
	}
};
class Point2D : public Point {
public:
	
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