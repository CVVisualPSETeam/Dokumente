#ifndef CVVISUAL_CALL_HPP
#define CVVISUAL_CALL_HPP

#include <utility>

class QString{};

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
	
	const QString& type() const {return calltype;}
protected:
	Call() : callData{}, id{newCallId()}, calltype{} {}
	Call(impl::CallData callData, QString type):
		callData{std::move(callData)}, id{newCallId()}, calltype{type} {}
	
	impl::CallData callData;
	size_t id;
	QString calltype;
};

}} //namespaces


#endif
