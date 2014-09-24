/*
    Monodomain: finite difference and explicit time stepping
    Leon Graham, 2014
*/

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <chrono>
#include "constants.h"
#include "types.h"
#include "memFH.h"
#include "monodomainFD.h"
#include "output.h"

using namespace std;
   
const int tend=10;
double t=0;
int tstep=1;
double stim_duration=1.0;
double stim_strength=1000.0;

double dx2=dx*dx;
double dy2=dy*dy;

//dt = dx2*dy2/(2*K*(dx2+dy2))
double dt=0.005; //0.04 for anisotropy=1=alpha

int cols=static_cast<int>(xlength/dx);
int rows=static_cast<int>(ylength/dy);


//set current stimulus
void Stim(ARRAY2D& stim, const int& rows, int cols, double radius, double stim_strength, double dx,  double dy)
{   
     for (size_t r=0; r<stim.size(); ++r)
     {
	 for (size_t c=0; c<stim[r].size(); ++c)
	 {
	     if (((c*dx-0.5)*(c*dx-0.5)+(r*dy-0.5)*(r*dy-0.5)) <= radius)
	     {
		stim[r][c] = stim_strength;
             }
	 }
     }
}

int main()
{
    ARRAY2D Vm(rows, vector<double>(cols));
    ARRAY2D iion(rows, vector<double>(cols));
    ARRAY2D w(rows, vector<double>(cols));
    ARRAY2D stim(rows, vector<double>(cols));
 
    memFH membrane_model;
    monodomainFD diffusion_model;
    Output Vm_output;
 
    bool isStimOn = true;
 
    //start timer
    std::chrono::system_clock::time_point tstart = std::chrono::system_clock::now();

    Stim(stim, rows, cols, radius, stim_strength, dx, dy);

    //Vm_output.open_file("binary");
    Vm_output.open_file("ascii");

    //finite difference calculation
    while (t<=tend)
    {
          //calculate membrane potential from membrane model
          membrane_model.explicitTS(Vm, iion, w, dt, rows, cols, FH_Vt, FH_Vp, C1, C2, C3, C4);

          /*
          Boundary Conditions:
          each boundary is set to zero.
          results from how the finite difference stencil is implemented.
          */

          //calculate membrane potential from diffusion
          diffusion_model.explicitTS(Vm, iion, stim, dt, Cm, Beta, rows, cols, dx2, dy2);
           
          //write potentials to file
          Vm_output.write_file(Vm, tstep, output_freq);
          
          //turn off stimulus
          if ((t>=stim_duration)&&(isStimOn==true))
          {
             for (size_t r=0; r<stim.size(); ++r)
             {
                 for (size_t c=0; c<stim[r].size(); ++c)
                 {
                     stim[r][c]=0;
                 }
             }
             isStimOn=false;
           }
          
          printf("tstep= %d, dt= %f, t= %f \n", tstep, dt, t);    
          t=t+dt;
          tstep=tstep+1;
    }
    Vm_output.close_file();

    //get elapsed time
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - tstart;

    printf("Total time: %.6f s\n", sec.count());
    printf("Average time per time-step: %.6f s.\n", (sec.count()/tstep));

   return 0;
}
