#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <type_traits>
#include <cstddef>


// sadly this is not part of C++11 but only of C++14:
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

template<typename T>
using my_decay = typename std::decay<T>::type;

class printers {
public:
	class printer_interface {
	public:
		
		virtual void print() const = 0;
		virtual void print(std::ostream&) const = 0;
		virtual std::unique_ptr<printer_interface> clone() const = 0;
		virtual ~printer_interface() = default;
	};
	
private:
	
	template<typename Printable>
	class printer: public printer_interface {
	public:
		printer(const Printable& value) : value{value} {}
		printer(Printable&& value) : value{std::move(value)} {}
		void print() const override final {
			std::cout << value << ", " ;
		}
		void print(std::ostream& stream) const override final {
			stream << value << ", ";
		}
		std::unique_ptr<printer_interface> clone() const override final {
			return make_unique<printer>(value);
		}
	private:
		Printable value;
	};
	
public:
	printers() = default;
	printers(printers&&) = default;
	printers& operator=(printers&&) = default;
	printers(const printers& other) {
		printer_list.reserve(other.printer_list.size());
		for(auto& x: other.printer_list) {
			printer_list.push_back(x->clone());
		}
	}
	printers& operator=(const printers& other) {
		printer_list.clear();
		printer_list.reserve(other.printer_list.size());
		for(auto& x: other.printer_list) {
			printer_list.push_back(x->clone());
		}
		return *this;
	}
	
	template<typename Printable>
	void add(Printable&& printable) {
		printer_list.emplace_back(make_unique<printer<my_decay<Printable>>>(
				std::forward<Printable>(printable)));
	}
	
	printer_interface& operator[](size_t index) {
		return *printer_list[index];
	}
	
	const printer_interface& operator[](size_t index) const {
		return *printer_list[index];
	}
	
	printer_interface& at(size_t index) {
		return *printer_list.at(index);
	}
	
	const printer_interface& at(size_t index) const {
		return *printer_list.at(index);
	}
	
	void print_all() const {
		std::cout << "[";
		for(const auto& x: printer_list) {
			x->print();
		}
		std::cout << "]";
	}
	
	void print_all(std::ostream& stream) const {
		stream << "[";
		for(const auto& x: printer_list) {
			x->print(stream);
		}
		stream << "]";
	}
	
	friend std::ostream& operator<<(std::ostream& stream, const printers& p) {
		p.print_all(stream);
		return stream;
	}
	
private:
	std::vector<std::unique_ptr<printer_interface>> printer_list;
	
};

int main() {
	printers p1, p2;
	p1.add(2);
	p2.add("foobar");
	p2.add(false);
	p1.add(std::move(p2));
	p1.add(3.141);
	p1.add(std::string("std::string"));
	p1.print_all();
	std::cout << '\n';
}
