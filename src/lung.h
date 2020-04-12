#ifndef _Lung_H__
#define _Lung_H__

class Lung
{

public:
	
	Lung (double compliance, double resistance, double tidal_volume)
	{
		compliance_=compliance;
		resistance_=resistance;
		tidal_volume_=tidal_volume;
		previous_volume_=0;
	};

	std::vector<double> pressure, volume, flow;

private:
	
	// Attributes
	double compliance_; 
	double resistance_;
	double tidal_volume_;
	double previous_volume_;

	// Methods
	void inspiration_pressure();
	void inspiration_volume();
	void inspiration_flow();

}; // End of Class definition

#endif