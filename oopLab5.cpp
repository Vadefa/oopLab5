#include <iostream>

using namespace std;
class Point {
public:
	virtual string classname() {
		return "Point";
	}

	virtual bool isA(string name) {
		return (name == classname());		// let's use the method classname() to not writing "Point" twice
	}

	Point() {
	}
	virtual ~Point() {
	}
};
class Line : public Point {
public:
	string classname() {
		return "Line";
	}

	bool isA(string name) {
		return (name == classname());
	}

	void eraseLine() {
		cout << "A line was erased\n";
	}

	Line(){
	}
	~Line() {
	}
};
class Section : public Point {
public:
	string classname() {
		return "Section";
	}

	bool isA(string name) {
		return (name == classname());
	}

	void eraseSection() {
		cout << "A section was erased\n";
	}
	Section() {
	}
	~Section() {
	}
};

int main()
{
	const int n = 10;
	Point* p[n];
	for (int i = 0; i < n; i++)
		if (i % 2 == 0)
			p[i] = new Line;
		else
			p[i] = new Section;

	for (int i = 0; i < n; i++)
		if (p[i]->classname() == "Line")					// this breaks the incapsulation rule
			((Line*)p[i])->eraseLine();						// and this is unsafe type conversion
	cout << "\n";

	for (int i = 0; i < n; i++)
		if (p[i]->isA("Section"))
			((Section*)p[i])->eraseSection();				// this is still not so safe, but better then before
	cout << "\n";

	for (int i = 0; i < n; i++) {
		if (dynamic_cast<Line*>(p[i]) != NULL)
			dynamic_cast<Line*>(p[i])->eraseLine();
		else if (dynamic_cast<Section*>(p[i]) != NULL)
			dynamic_cast<Section*>(p[i])->eraseSection();	// and this is the safe type conversion
	}
	cout << "\n";

	return 0;
}