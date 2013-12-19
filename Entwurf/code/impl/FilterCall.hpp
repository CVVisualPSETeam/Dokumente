#ifndef CVVISUAL_FILTER_CALL_HPP
#define CVVISUAL_FILTER_CALL_HPP

#include "Call.hpp"

#include "../moc/ocv_moc.hpp"

namespace cvv {

class FilterCall: public Call {
public:
	FilterCall(ocv::InputArray in, ocv::OutputArray out, impl::CallData data):
		Call(data), input(in), output(out) {}
	
private:
	ocv::InputArray input;
	ocv::OutputArray output;
};


} //namespace

#endif
