/* Model output written to file */

#ifndef CARDIAC_WRITE_H
#define CARDIAC_WRITE_H

#include <fstream>
#include <string>
#include "Types.h"


class Output
{
  public:
   void open_file(std::string format);
   void write_file(ARRAY2D& Vm, int tstep, int output_freq);
   void close_file();
  private:
   bool isAscii;
   std::ofstream outputFile;

    
};

#endif
