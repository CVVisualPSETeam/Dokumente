#ifndef CVVISUAL_UTIL_HPP
#define CVVISUAL_UTIL_HPP

//required for utilities
#include <memory>
#include <utility>

//included for convinience of others:
#include <cstddef> //size_t
#include <algorithm> // since some people like to forget that one

namespace cvv {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


} // namespace cvv

#endif
