#ifndef CVVISUAL_FILTER_CALL_HPP
#define CVVISUAL_FILTER_CALL_HPP

#include "Call.hpp"

#include "../moc/ocv_moc.hpp"

namespace cvv {
namespace impl {

/**
 * All data of a filter-call: Location, original image and result.
 */
class FilterCall: public Call {
public:
	FilterCall(const ocv::InputArray& in, const ocv::OutputArray& out, impl::CallData data, QString type):
		Call(data, type), input_(in), output_(out) {}
	
	/**
	 * @returns the original image
	 */
	const ocv::InputArray& input() const {return input_;}
	/**
	 * @returns the filtered image
	 */
	const ocv::OutputArray& output() const {return output_;}
	
private:
	ocv::InputArray input_;
	ocv::OutputArray output_;
};


}} //namespaces

#endif
