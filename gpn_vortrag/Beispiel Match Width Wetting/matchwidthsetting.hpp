#ifndef CVVISUAL_MATCH_WIDTH_SETTING
#define CVVISUAL_MATCH_WIDTH_SETTING

#include <QSpinBox>

#include "opencv2/features2d/features2d.hpp"
#include "matchsettings.hpp"
#include "cvvmatch.hpp"

namespace cvv{ namespace qtutil{

class MatchWidthSetting:public MatchSettings{

	Q_OBJECT

public:
	/**
	 * @brief the constructor
	 * std::vector<cv::DMatch> this argument is for the MatchSettingSelector and will be ignored.
	 * @param parent
	 */
	MatchWidthSetting(std::vector<cv::DMatch>,QWidget* parent=nullptr);

	/**
	 * @brief set the Settings of the given match
	 * @param match a cvvmatch
	 */
	virtual void setSettings(CVVMatch &match) override;

private:
	QSpinBox* spin_;

};

}}

#endif
