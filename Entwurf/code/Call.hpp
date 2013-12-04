#ifndef CVVISUAL_CALL_HPP
#define CVVISUAL_CALL_HPP

#include "CallData.hpp"

class Call {
public:
	
	virtual ~Call() = default;
protected:
	Call(CallData callData): callData{std::move(callData)} {}
	Call() = default;
	
	CallData callData;
private:
	
	
};


#endif
