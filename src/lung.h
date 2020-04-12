#ifndef _Lung_H__
#define _Lung_H__

#include <cmath>

class Lung
{

public:
	
	Lung (
		double compliance, 
		double resistance, 
		double tidal_volume);

	// Methods
	double	InspirationPressure();
	double 	InspirationVolume(double timestamp);
	double	InspirationFlow();

private:
	
	// Attributes
	double compliance_; 
	double resistance_;
	double tidal_volume_;
	double volume_;
	double previous_volume_;
	double delta_volume_;


}; // End of Class definition

#endif