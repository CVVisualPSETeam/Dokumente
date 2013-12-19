#ifndef CVVISUAL_UTILITY_HPP
#define CVVISUAL_UTILITY_HPP

#include <stdexcept>
#include <type_traits>
#include <utility>

namespace cvv {
namespace util {

// This really is work in progress:
template <typename T>
class optional {
public:
	optional() : is_set{false} {}
	optional(T value) : is_set(true) {
		new(&storage) T{std::move(value)};
	}
	
	~optional() {
		if(is_set) {
			//call the destructor explicitly:
			reinterpret_cast<T*>(&storage)->~T();
		}
	}
	
	T& operator*() {
		if(is_set) {
			return *reinterpret_cast<T*>(&storage);
		}
		else {
			throw std::logic_error{"optional does not contain a value"};
		}
	}
	
	const T& operator*() const {
		if(is_set) {
			return *reinterpret_cast<T*>(&storage);
		}
		else {
			throw std::logic_error{"optional does not contain a value"};
		}
	}
	
	explicit operator bool() {
		return is_set;
	}
	
	
private:
	using storage_t = typename std::aligned_storage<sizeof(T), alignof(T)>::type;
	
	storage_t storage;
	bool is_set;
};

}} // namespaces



#endif
