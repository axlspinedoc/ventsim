//------------------------------------------------------------------------------
// @file: psv.cpp
// @created on: April 8th, 2020
// @author: Axel Sandoval 
// @email: axel.sandoval@protexa.com.mx
//
// @brief: Pressure Control Ventilation Test
// 
// This file is subject to the terms and conditions defined in the file 'LICENSE'
// found at: 
//------------------------------------------------------------------------------

// Includes
#include "../include/ventsim/matplotlibcpp.h"
#include "lung.h"
#include <iostream>

namespace plt = matplotlibcpp;

// Plotter settings
const double resolution = 50;         // milliseconds

// Ventilator settings
const double inspiration_time = 800;  // milliseconds
const double frecuency = 15;          // breaths per minute
const double esp_ins_ratio = 1.5;
const double vol_min = 7.0;           // 

// Lung parameters definition
const double compliance     = 80;   // mL/cmH2O-----Ranges (80-120)
const double resistance     = 2;    // cmH2O/(L/s)--Ranges (1-3)
const double tidal_volume   = 800;  // mL ----------Ranges (400-1600)



int main()
{
	
	return 0;
}