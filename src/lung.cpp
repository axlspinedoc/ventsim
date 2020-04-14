//------------------------------------------------------------------------------
// @file: lung.cpp
// @created on: April 8th, 2020
// @author: Axel Sandoval 
// @email: axel.sandoval@protexa.com.mx
//
// @brief: Class definition of a Human Respiratory System for simulation
//				 and control
// 
// This file is subject to the terms and conditions defined in the file 'LICENSE'
// found at: 
//------------------------------------------------------------------------------

#include "lung.h"

Lung::Lung (double compliance, double resistance, double tidal_volume)	
	{
		compliance_=compliance;
		resistance_=resistance;
		tidal_volume_=tidal_volume;
		previous_volume_=0;
	};

void Lung::inhale(double timestamp)
{	
	volume_ = tidal_volume_*(1-exp(-timestamp*ml_to_l/(compliance_ * resistance_)));
	flow_=volume_-previous_volume_;
	previous_volume_=volume_;
	pressure_=((1/compliance_)*volume_)+(volume_*resistance_*0.001);
}

void Lung::exhale(double timestamp)
{
	volume_ = previous_volume_*exp(-timestamp*ml_to_l/(compliance_ * resistance_));
	flow_=volume_-previous_volume_;
	previous_volume_=volume_;
	pressure_=((1/compliance_)*volume_)+(volume_*resistance_*0.001);
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

	