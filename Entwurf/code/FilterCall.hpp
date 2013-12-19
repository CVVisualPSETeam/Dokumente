#ifndef CVVISUAL_FILTER_CALL_HPP
#define CVVISUAL_FILTER_CALL_HPP

#include "Call.hpp"

#include "ocv_moc.hpp"

namespace cvv {
namespace pub_util {

class FilterCall: public Call {
	FilterCall(ocv::InputArray in, ocv::OutputArray out, CallData data):
		Call(data), input(in), output(out) {}
// Filterdata
	ocv::InputArray input;
	ocv::OutputArray output;
};


}} //namespaces

#endif
