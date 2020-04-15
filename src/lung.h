//------------------------------------------------------------------------------
// @file: 			lung.h
// @created on: April 8th, 2020
// @author: 		Axel Sandoval 
// @email: 			axel.sandoval@protexa.com.mx
//
// @brief: Class definition of a Human Respiratory System for simulation
//				 and control
// 
// This file is subject to the terms and conditions defined in the file 'LICENSE'
// found at: 
//------------------------------------------------------------------------------

#ifndef _Lung_H__
#define _Lung_H__

// Libraries
#include <cmath>

// Class that simulates a respiratory system based on compliance and resistance
// parameters. To instantiate, compliance and resistance must be defined. 
// Ranges for C & R are as follows:
// Compliance (mL/cmH20)----------80-120 	in a healthy patient
// Resistance (cmH2O/ (L/s) )-----1 - 3 	in a healthy patient
//
// 2 Modes of operation are defined:
//
// *** Natural respiration ***
// Define Tidal volume using the appropriate function. use Inhale function to
// simulate normal operation of a lung.
//
// *** Ventilated patient ***
// Use InyectFlow to simulate incoming flow of air into the lungs, given as
// L/s.
//
// *** Exhalation ***	
// Exhale function is the same for both modes as the lungs expel air naturally.
//
// Use the different GetVolume/Pressure/Flow functions to plot the mechanics of
// the lungs in given times.
//
// All timestamps MUST be given in MILLISECONDS

class Lung
{

public:
	
	// Constructor
	Lung (double compliance, double resistance);

	// Ventilated mode
	void		InjectFlow(double instant_flow, double timestamp);

	// Natural respiration. Tidal Volume must be set prior inhale
	void	  SetTidalVolume(double tidal_volume);
	void		inhale(double timestamp);
	void		exhale(double timestamp);
	
	double	GetPressure();
	double 	GetVolume();
	double	GetFlow();

private:
	
	const double ml_to_l = 1000;
	
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