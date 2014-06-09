
#include <QVBoxLayout>

#include "matchwidthsetting.hpp"

namespace cvv{ namespace qtutil{

MatchWidthSetting::MatchWidthSetting(std::vector<cv::DMatch>, QWidget *parent):
	MatchSettings{parent},
	spin_{nullptr}
{
	auto layout=util::make_unique<QVBoxLayout>();
	auto spin= util::make_unique<QSpinBox>();

	spin_=spin.get();

	spin_->setMinimum(1);

	connect(spin_,SIGNAL(valueChanged(int)),this,SLOT(updateAll()));

	layout->addWidget(spin.release());
	setLayout(layout.release());

}

void MatchWidthSetting::setSettings(CVVMatch &match)
{
	QPen pen = match.getPen();
	pen.setWidth(spin_->value());
	match.setPen(pen);
}
}}
