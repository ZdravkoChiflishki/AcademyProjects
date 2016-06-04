
#include <iostream>
#include <exception>
using namespace std;

class Base {
public:
	int i;
	Base(int input) : i(input) {};
	virtual void dummy() {}
};
class Derived : public Base {
public:
	int a;
	Derived(int i) : Base(5), a(i) {};
	void print() {
		cout << "Derived - " << a << endl;
	}
};


class BaseStatic {};
class DerivedStatic : public BaseStatic {};

int main() {
	try {
		Base * pba = new Derived(13);
		Base * pbb = new Base(5);
		Derived * pd;

		pd = dynamic_cast<Derived*>(pba);
		if (pd == 0) cout << "Null pointer on first type-cast.\n";

		pd = dynamic_cast<Derived*>(pbb);
		if (pd == 0) cout << "Null pointer on second type-cast.\n";

	}
	catch (exception& e) { cout << "Exception: " << e.what(); }



	BaseStatic * a = new BaseStatic;
	DerivedStatic * b = static_cast<DerivedStatic*>(a);

	DerivedStatic *pb = b;


	class A { /* ... */ };
	class B { /* ... */ };
	/*
	A * a = new A;
	B * b = reinterpret_cast<B*>(a);
	*/
	return 0;
}