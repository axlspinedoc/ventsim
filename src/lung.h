//------------------------------------------------------------------------------
// @file: lung.h
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

#ifndef _Lung_H__
#define _Lung_H__

#include <cmath>

const double ml_to_l = 1000;

class Lung
{

public:
	
	// Constructor
	Lung (
		double compliance, 
		double resistance, 
		double tidal_volume);

	// Methods
	void		inhale(double timestamp);
	void		exhale(double timestamp);
	double	GetPressure();
	double 	GetVolume();
	double	GetFlow();

private:
	
	// Attributes
	double compliance_; 
	double resistance_;
	double tidal_volume_;
	
	double volume_;
	double previous_volume_;
	double flow_;
	double pressure_;


}; // End of Class definition

#endif