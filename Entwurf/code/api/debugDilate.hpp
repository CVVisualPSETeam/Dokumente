#ifndef CVVISUAL_DEBUG_DILATE_HPP
#define CVVISUAL_DEBUG_DILATE_HPP

#include <string>

#include "../moc/ocv_moc.hpp"

#include "CallData.hpp"
#include "debugMode.hpp"


namespace cvv {


namespace impl {
	//implementation outside API
	void debugDilate(ocv::InputArray in, ocv::OutputArray out, CallData data);
} // namespace impl

#ifdef CVVISUAL_DEBUGMODE
static inline void debugDilate(ocv::InputArray in, ocv::OutputArray out,
		impl::CallData data = impl::CallData()){
	if(debugMode()) {
		impl::debugDilate(in, out, data);
	}
}
#else
static inline void debugDilate(ocv::InputArray, ocv::OutputArray,
		impl::CallData = impl::CallData()){}
#endif

} // namespace cvv


#endif
