
#include "DataController.hpp"
#include "FilterCall.hpp"
#include "util.hpp"

#include "../api/debugDilate.hpp"
#include "../api/CallData.hpp"


namespace cvv {
namespace impl {

void debugDilate(ocv::InputArray in, ocv::OutputArray out, CallData data) {
	dataController().addCall(make_unique<FilterCall>(in, out, data, QString{ /* dilate */}));
}

}} //namespaces
