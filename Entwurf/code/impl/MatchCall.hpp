#ifndef CVVISUAL_MATCH_CALL_HPP
#define CVVISUAL_MATCH_CALL_HPP

#include <vector>
#include <utility>

#include "Call.hpp"

#include "../moc/ocv_moc.hpp"

namespace cvv {
namespace impl {

/**
 * Contains all the calldata (= location, images and their keypoints).
 */
class MatchCall: public Call {
public:
	MatchCall(std::vector<std::pair<ocv::InputArray, std::vector<ocv::KeyPoint>>> images,
			impl::CallData data, QString type):
		Call(data, type), images{std::move(images)} {}
	
	const ocv::InputArray& getImage(size_t index) const {return images.at(index).first;}
	const std::vector<ocv::KeyPoint>& getKeyPoints(size_t index) const {return images.at(index).second;}
private:
	std::vector<std::pair<ocv::InputArray, std::vector<ocv::KeyPoint>>> images;
};


}} //namespaces


#endif
