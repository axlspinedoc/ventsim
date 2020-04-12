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

int main()
{
    const int resolution = 100;           // milliseconds
    const int inspiration_time = 1500;    // milliseconds
    std::vector<double> x, volume, flow, pressure;

    for(double timestamp=0.0; timestamp<inspiration_time; timestamp+=resolution) {
        x.push_back(timestamp);
        volume.push_back(patient.InspirationVolume(timestamp));
        flow.push_back(patient.InspirationFlow());
        pressure.push_back(patient.InspirationPressure());

            // Clear previous plot
            plt::clf();
            // Plot line from given x and y data. Color is selected automatically.
            plt::plot(x, volume);
            // Plot a line whose name will show up as "log(x)" in the legend.
            //plt::named_plot("log(x)", x, z);

            // Set x-axis to interval [0,1000000]
            plt::xlim(0, inspiration_time*2);

            // Add graph title
            plt::title("Sample figure");
            // Enable legend.
            plt::legend();
            // Display plot continuously
            plt::pause(0.01);        
    }
}