#ifndef CVVISUAL_CALL_DATA_HPP
#define CVVISUAL_CALL_DATA_HPP

#include <string>
#include <cstddef>
#include <utility>

struct CallData {
public:
	CallData() = default;
	CallData(const std::string file, size_t line, const std::string function) :
		file{std::move(file)}, line{line}, function{std::move(function)}, isKnown{true} {}
	operator bool() {
		return isKnown;
	}
	
	const std::string file = "";
	const size_t line = 0;
	const std::string function ="";
	bool isKnown = false;
};

#define CVVISUAL_LOCATION CallData{__FILE__, __LINE__, __func__, true}

#endif
