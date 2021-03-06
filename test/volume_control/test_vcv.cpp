//------------------------------------------------------------------------------
// @file: vcv.cpp
// @created on: April 8th, 2020
// @author: Axel Sandoval 
// @email: axel.sandoval@protexa.com.mx
//
// @brief: Volume Control Ventilation Test, using volume per minute as control 
// 		   variable. Flow per breath is injected linearly. Pressure is not
//         observed on each cycle, but not limited.
// 
// This file is subject to the terms and conditions defined in the file 'LICENSE'
// found at: 
//------------------------------------------------------------------------------

// Includes
#include "../../inc/matplotlibcpp.h"
#include "../../lung/lung.h"
//#include <iostream>

namespace plt = matplotlibcpp;

// Plotter settings
const double resolution = 50;         // milliseconds
const double s_to_ms = 0.001;

// Ventilator settings
const double vol_min = 7000;					// mL/min
const double frequency = 12;					// Breaths/minute
const double inspiration_time = 800;  // milliseconds
const double flow_inject = vol_min/(frequency*(inspiration_time/resolution));
const double esp_ins_ratio = 1.5;

// Lung parameters definition
const double compliance = 80;   			// mL/cmH2O-----Ranges (80-120)
const double resistance = 2;		    	// cmH2O/(L/s)--Ranges (1-3)

// Object instantiation 
Lung patient(compliance,resistance);

// Function declarations
void plotter(std::vector<double> &time,std::vector<double> &volume,std::vector<double> &flow,std::vector<double> &pressure);

int main()
{
	
    std::vector<double> time, volume, flow, pressure;

    for(double timestamp=0; timestamp<inspiration_time; timestamp+=resolution) {
        
        time.push_back(timestamp);
        patient.InjectFlow(flow_inject,timestamp*s_to_ms);
        
        volume.push_back(patient.GetVolume());
        flow.push_back(patient.GetFlow());
        pressure.push_back(patient.GetPressure());
    }

    double espiration_time = inspiration_time * esp_ins_ratio;

    for(double timestamp=0; timestamp<espiration_time; timestamp+=resolution) {
        
        time.push_back(timestamp+inspiration_time);
        patient.Exhale(timestamp * s_to_ms);
        
        volume.push_back(patient.GetVolume());
        flow.push_back(patient.GetFlow());
        pressure.push_back(patient.GetPressure());
    }

    plotter(time, volume, flow, pressure);

}

void plotter(std::vector<double> &t,std::vector<double> &v,std::vector<double> &f,std::vector<double> &p)
{
    std::vector<double> time, volume, flow, pressure;
    int simulation_time=t.back();

    for (int index = 0; index < t.size(); index++)
    {

        time.push_back(t[index]);
        volume.push_back(v[index]);
        flow.push_back(f[index]);
        pressure.push_back(p[index]);

        // Clear previous plot
        plt::clf();

        plt::figure(1);
    
        // Volume graph
        plt::subplot(3,1,1);
        plt::title("Respiration cycle");
        plt::plot(time, volume);
        plt::xlim(0, simulation_time);
        //plt::set_ylabel("egs");
        plt::ylim(-100, 1200);
        plt::named_plot("Volume(mL)", time, volume);
        plt::legend();
        
        // Flow graph
        plt::subplot(3,1,2);
        plt::plot(time, flow);
        plt::xlim(0, simulation_time);
        plt::ylim(-500, 500);
        plt::named_plot("flow(mL/s)", time, flow);
        plt::legend();
        
        // Pressure graph
        plt::subplot(3,1,3);
        plt::plot(time, pressure);
        plt::xlim(0, simulation_time);
        plt::ylim(0, 20);
        plt::named_plot("Pressure(cmH2O)", time, pressure);
        plt::legend();
    
        // Display plot continuously
        plt::pause(0.001);        
    }
}
