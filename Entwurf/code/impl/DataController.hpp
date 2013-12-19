#ifndef CVVISUAL_DATA_CONTROLLER_HPP
#define CVVISUAL_DATA_CONTROLLER_HPP

#include <memory>
#include <vector>

#include "Call.hpp"

namespace cvv {

// 'forward declaration':
class WindowController{};

class DataController {
public:
	DataController() { /* implement */ }
	
	void addCall(std::unique_ptr<Call> call) {calls.push_back(std::move(call));}
	
private:
	WindowController windowController;
	std::vector<std::unique_ptr<Call>> calls;
};


//singleton:
DataController& dataController() {
	thread_local static DataController controller{};
	return controller;
}

} // namespace cvv

#endif
