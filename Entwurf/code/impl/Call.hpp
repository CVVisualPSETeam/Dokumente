#ifndef CVVISUAL_CALL_HPP
#define CVVISUAL_CALL_HPP

#include "util.hpp"

#include "../api/CallData.hpp"

namespace cvv {
namespace impl {

size_t newCallId() {
	thread_local size_t nextId = 0;
	return nextId++;
}

class Call {
public:
	virtual ~Call() = default;
	size_t getId() { return id; }
protected:
	Call() : callData{}, id{newCallId()} {}
	Call(impl::CallData callData): callData{std::move(callData)}, id{newCallId()} {}
	
	impl::CallData callData;
	size_t id;
};

}} //namespaces


#endif
