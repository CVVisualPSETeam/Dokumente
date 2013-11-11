#include "foo.hpp"

#include <iostream>

namespace foo { namespace impl {

void bar(const std::string str, int n) {
	for(int i=0; i < n; ++i) {
		std::cout << str << '\n';
	}
}

}}
