#ifndef CVVISUAL_CALL_HPP
#define CVVISUAL_CALL_HPP

#include "CallData.hpp"

namespace cvv {
namespace pub_util {


class Call {
public:
	virtual ~Call() = default;
protected:
	Call() : callData() {}
	
	
#if _cplusplus >= 201103L
	Call(CallData callData): callData{std::move(callData)} {}
#else
	Call(const CallData& callData): callData{callData} {}
#endif
	
	CallData callData;
};

}} //namespaces


#endif
