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
	MatchCall(ocv::InputArray img1, std::vector<ocv::KeyPoint> keypoints1, ocv::InputArray img2,
			std::vector<ocv::KeyPoint> keypoints2, std::vector<ocv::DMatch> matches,
			impl::CallData data, QString type ) :
		Call(data, type), img1_{img1}, keypoints1_{std::move(keypoints1)}, img2_{img2},
			keypoints2_{std::move(keypoints2)}, matches_{std::move(matches)} {}
	
	//const ocv::InputArray& getImage(size_t index) const {return images.at(index).first;}
	//const std::vector<ocv::KeyPoint>& getKeyPoints(size_t index) const {return images.at(index).second;}
private:
	ocv::InputArray img1_;
	std::vector<ocv::KeyPoint> keypoints1_;
	ocv::InputArray img2_;
	std::vector<ocv::KeyPoint> keypoints2_;
	std::vector<ocv::DMatch> matches_;
};


}} //namespaces


#endif
