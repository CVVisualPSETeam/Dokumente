#include <iostream>

class base {
public:
	// If a method doesn't change anything make it const:
	void fun() const {
		std::cout << "base::fun()\n";
	}
};

// the public is required, since there is also private inheritance (though it is of small use)
class derived: public base {
public:
	void fun() const {
		std::cout << "derived::fun()\n";
	}
};

class virt_base {
public:
	// if a method should be virtual say so explicitly:
	virtual void fun() const {
		std::cout << "virt_base::fun()\n";
	}
	
	// if you have one virtual function always make the destructor virtual:
	virtual ~virt_base() = default;
};

class virt_derived: public virt_base {
public:
	// if you use virtual inheritance: say so by using override
	void fun() const override {
		std::cout << "virt_derived::fun()\n";
	}
};

void caller(const base& var) {
	var.fun();
}

void caller(const virt_base& var) {
	var.fun();
}


int main() {
	derived d;
	d.fun(); //prints: derived::fun()
	caller(d); //prints base::fun()
	caller(base{}); // prints base::fun()
	
	virt_derived vd;
	vd.fun(); // prints: virt_derived::fun()
	caller(vd); // prints: virt_derived::fun()
	caller(virt_base{}); // virt_base::fun()
}

