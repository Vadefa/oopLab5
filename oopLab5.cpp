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

int main()
{	
	Base obj;
	cout << "\n";
	{
		unique_ptr<Base> up1(new Base);
		unique_ptr<Base> up2(new Base(obj));
		unique_ptr<Base> up3(new Base(&obj));
		//unique_ptr<Base> up4(up1);			- unique pointers can't copy yourself

		unique_ptr<Base> up4;
		cout << "up1 = " << up1 << "\nup4 = " << up4 << ", making move:\n";
		up4 = move(up1);
		cout << "up1 = " << up1 << "\nup4 = " << up4 << "\n";
	}
	cout << "\n";

	{
		shared_ptr<Base> sp1(new Base);
		shared_ptr<Base> sp2(new Base(obj));
		shared_ptr<Base> sp3(new Base(&obj));

		shared_ptr<Base> sp4(sp1);
		cout << "sp1 = " << sp1 << "\nsp4 = " << sp4 << "\n";
	}
	cout << "\n";

	return 0;
}
