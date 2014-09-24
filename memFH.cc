/* FitzHugh-Nagumo membrane model
   Solves the two ODEs explicitly
*/

#include <stdlib.h>
#include "memFH.h"
#include "types.h"
#include "constants.h"

void memFH::explicitTS(ARRAY2D& Vm, ARRAY2D& iion, ARRAY2D& w, double dt, int rows, int cols, double FH_Vt, double FH_Vp, double C1, double C2, double C3, double C4)
{
     for (size_t i=0; i<Vm.size(); ++i)
     {
         for (size_t j=0; j<Vm[i].size(); ++j)
         {
             iion[i][j] = (C1*Vm[i][j]*(Vm[i][j]/FH_Vt-1.0)*(1.0-Vm[i][j]/FH_Vp) - C2*Vm[i][j]*w[i][j]);
             w[i][j] = w[i][j] + dt*C3*(Vm[i][j] - C4*w[i][j]);
         }
     }
}
