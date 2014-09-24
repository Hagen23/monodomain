/* Physiological constants used in the model,
   computational mesh and file output         */

#ifndef CARDIAC_CONSTANTS_H
#define CARDIAC_CONSTANTS_H

#include <string>

//output
const int output_freq=100;
const std::string file_name="Vm.out.txt"; 

//conductivity
const double sigma_x=2.0;
const double sigma_y=0.25;

//grid dimensions and spacing
const double dx=0.01;
const double dy=0.01;
const double xlength=1.0;
const double ylength=1.0;

//radius of stimulus
const double radius=0.001;

//membrane model parameters
const double FH_Vt=5.0;
const double FH_Vp=100.0;
const double C1 = 0.5;
const double C2 = 0.02;
const double C3 = 0.015;
const double C4 = 0.005;

//membrane capacitance and surface to volume ratio 
const double Cm=1.0;
const double Beta=2000;

#endif

