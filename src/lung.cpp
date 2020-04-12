#include "lung.h"

Lung::Lung (double compliance, double resistance, double tidal_volume)	
	{
		compliance_=compliance;
		resistance_=resistance;
		tidal_volume_=tidal_volume;
		previous_volume_=0;
	};

double Lung::InspirationPressure()
{
	return (1/compliance_)*volume_+resistance_*delta_volume_;
}

double Lung::InspirationVolume(double timestamp){
	
	volume_ = tidal_volume_*(1-exp(-timestamp/(compliance_*resistance_*0.001)));
	delta_volume_=volume_-previous_volume_;
	previous_volume_=volume_;
	
	return volume_;
}

double Lung::InspirationFlow()
{
	return delta_volume_;
}
	