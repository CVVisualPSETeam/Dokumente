#ifndef CVVISUAL_MATCH_CALL_HPP
#define CVVISUAL_MATCH_CALL_HPP

#include "Call.hpp"

#include "../moc/ocv_moc.hpp"

namespace cvv {
namespace impl {

class MatchCall: public Call {
public:
	MatchCall(const ocv::InputArray& in1, const ocv::InputArray& in2, impl::CallData data):
		Call(data), pic1_(in1), pic2_(in2) {}
	
	const ocv::InputArray& pic1() const {return pic1_;}
	const ocv::InputArray& pic2() const {return pic2_;}
private:
	ocv::InputArray pic1_;
	ocv::InputArray pic2_;
};


}} //namespaces


#endif
