#ifndef CVVISUAL_CODE_SAMPLES_ZERO_OVERHEAD_FOO_HPP
#define CVVISUAL_CODE_SAMPLES_ZERO_OVERHEAD_FOO_HPP

#include <string>

namespace foo {

namespace impl {
	void bar(const std::string str, int n);
}

#ifdef CVVISUAL_DEBUG
inline void bar(const std::string& str, int n){
	impl::bar(str, n);
}
#else
inline void bar(const std::string&, int){}
#endif
}

#endif
