#include "lung.h"

Lung::Lung (double compliance, double resistance, double tidal_volume)	
	{
		compliance_=compliance;
		resistance_=resistance;
		tidal_volume_=tidal_volume;
		previous_volume_=0;
	};

void Lung::Inspiration(double timestamp)
{	
	volume_ = tidal_volume_*(1-exp(-timestamp/(compliance_*resistance_*0.001)));
	flow_=volume_-previous_volume_;
	previous_volume_=volume_;
	pressure_=((1/compliance_)*volume_)+(resistance_*flow_*0.001);
}

void Lung::Espiration(double timestamp)
{
}

double Lung::GetVolume()
{
	return volume_;
}

double Lung::GetFlow()
{
	return flow_;
}

double Lung::GetPressure()
{
	return pressure_;
}

	