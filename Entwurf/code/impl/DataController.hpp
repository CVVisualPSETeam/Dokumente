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
	void removeCall(size_t Id);
	const Call& getCall(size_t Id) const;
	Call& getCall(size_t Id);
	
	/**
	 * Passes control to the View-controller.
	 * 
	 * Returns when the ViewController signals that normal program-execution shall continue.
	 * 
	 */
	void callUI();
	
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
