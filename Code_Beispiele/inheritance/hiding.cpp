#include <iostream>

class base {
public:
	virtual void fun(int) const {
		std::cout<< "base::fun(int)\n";
	}
};

class derived: public base {
public:
	// overload that hides fun(int); creates warning in clang, silent in gcc
	void fun(double) const {
		std::cout << "derived::fun(double)\n";
	}
};

void caller(const base& arg) {
	arg.fun(3); // calls base::fun(int), always
}

int main() {
	derived d;
	d.fun(3); // calls derived::fun(double)
	caller(d);
}
