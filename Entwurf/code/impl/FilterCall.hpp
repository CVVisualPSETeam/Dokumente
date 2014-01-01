#ifndef CVVISUAL_FILTER_CALL_HPP
#define CVVISUAL_FILTER_CALL_HPP

#include "Call.hpp"

#include "../moc/ocv_moc.hpp"

namespace cvv {
namespace impl {

class FilterCall: public Call {
public:
	FilterCall(const ocv::InputArray& in, const ocv::OutputArray& out, impl::CallData data):
		Call(data), input_(in), output_(out) {}
	
	const ocv::InputArray& input() const {return input_;}
	const ocv::OutputArray& output() const {return output_;}
	
private:
	ocv::InputArray input_;
	ocv::OutputArray output_;
};


}} //namespaces

#endif
