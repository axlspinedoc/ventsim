#define _USE_MATH_DEFINES
//#include <cmath> 
#include "../include/ventsim/matplotlibcpp.h"
#include "lung.h"

namespace plt = matplotlibcpp;

// Lung object definition
const double compliance     = 80;   // mL/cmH2O-----Ranges (80-120)
const double resistance     = 2;    // cmH2O/(L/s)--Ranges (1-3)
const double tidal_volume   = 800;  // mL ----------Ranges (400-1600)

Lung patient(compliance,resistance,tidal_volume);

// Ventilator settings
const int resolution = 100;           // milliseconds
const int inspiration_time = 1500;    // milliseconds
const float ins_esp_ratio = 2.0;

void plotter()
{

}

int main()
{    
    std::vector<double> time, volume, flow, pressure;
    int simulation_time = inspiration_time*ins_esp_ratio;

    for(double timestamp=0.0; timestamp<simulation_time; timestamp+=resolution) {
        
        time.push_back(timestamp);
        patient.Inspiration(timestamp/1000);
        
        volume.push_back(patient.GetVolume());
        flow.push_back(patient.GetFlow());
        pressure.push_back(patient.GetPressure());

        // Clear previous plot
        plt::clf();

        plt::figure(1);
    
        // Plot line from given x and y data. Color is selected automatically.
        plt::subplot(3,1,1);
        plt::title("Inspiration cycle");
        plt::plot(time, volume);
        plt::xlim(0, simulation_time);
        //plt::set_ylabel("egs");
        //plt::ylim(0, tidal_volume+500);
        plt::named_plot("Volume(t)", time, volume);
        plt::legend();
        
        plt::subplot(3,1,2);
        plt::plot(time, flow);
        plt::xlim(0, simulation_time);
        //plt::ylim(0, tidal_volume);
        plt::named_plot("flow(t)", time, flow);
        plt::legend();
        
        plt::subplot(3,1,3);
        plt::plot(time, pressure);
        plt::xlim(0, simulation_time);
        //plt::ylim(0, 40);
        plt::named_plot("Pressure(t)", time, pressure);
        plt::legend();
    
        // Display plot continuously
        plt::pause(0.01);        
    }
}