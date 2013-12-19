#ifndef CVVISUAL_CALL_HPP
#define CVVISUAL_CALL_HPP

#include "../api/CallData.hpp"

namespace cvv {


class Call {
public:
	virtual ~Call() = default;
protected:
	Call() : callData() {}
	Call(impl::CallData callData): callData{std::move(callData)} {}
	
	impl::CallData callData;
};

} //namespace


#endif
