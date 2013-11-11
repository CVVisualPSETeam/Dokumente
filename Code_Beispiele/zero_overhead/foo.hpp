#ifndef CVVISUAL_CODE_SAMPLES_ZERO_OVERHEAD_FOO_HPP
#define CVVISUAL_CODE_SAMPLES_ZERO_OVERHEAD_FOO_HPP

#include <string>
#include <atomic>

namespace foo {

namespace impl {
	void bar(const std::string str, int n);
}

#ifdef CVVISUAL_DEBUG

namespace impl {
	static std::atomic_bool debug_tu{true};
}

static inline void bar(const std::string& str, int n){
	if(impl::debug_tu.load()){
		impl::bar(str, n);
	}
}

static inline void set_debug_tu(bool b) {
	impl::debug_tu.store(b);
}
#else
static inline void bar(const std::string&, int){}
static inline void set_debug_tu(bool) {}
#endif
}

#endif
