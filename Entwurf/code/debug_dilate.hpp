#ifndef CVVISUAL_DEBUG_DILATE_HPP
#define CVVISUAL_DEBUG_DILATE_HPP

#include "ocv_moc.hpp"

#include "CallData.hpp"
#include "FilterCall.hpp"

#include "debug_mode.hpp"


namespace cvv {


namespace impl {
	void debugDilate(pub_util::FilterCall data); //implementation outside API
}

#ifdef CVVISUAL_DEBUGMODE
static inline void debugDilate(ocv::InputArray in, ocv::OutputArray out,
		pub_util::CallData data = pub_util::CallData()){
	if(debugMode()) {
		impl::debugDilate(pub_util::FilterCall(in, out, data));
	}
}
#else
static inline void debugDilate(ocv::InputArray, ocv::OutputArray,
		pub_util::CallData = pub_util::CallData()){}
#endif

} // namespace cvv


#endif
