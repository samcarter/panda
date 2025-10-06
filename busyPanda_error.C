// root -l BusyPanda_error.C+

#include <iostream>
#include <sstream>
#include <fstream>

#include "TASImage.h"
#include "TSystem.h"

void BusyPanda_error(){
  
  int i, size, w, h;
  double fraction[19];
  TASImage* im;
  double cm_fraction = 0.1424935;
  double average = 0.0;
  double error = 0.0;
  
  for (int i = 1; i < 19; i++) { 
    
    std::cout << i;
    std::ostringstream cmd;
    cmd << "pdflatex --interaction=batchmode --jobname=\"BusyPanda_fonttest\" '\\documentclass{standalone}\\usepackage{lipsum}\\begin{document}\\lipsum[1][" << i << "]\\end{document}' > /dev/null";
    int ret = gSystem->Exec(cmd.str().c_str());
    
    if ( ret == 0 ){

      gSystem->Exec("pdftocairo -png -r 2000 -singlefile BusyPanda_fonttest.pdf BusyPanda_fonttest");
      
      // open image
      im = (TASImage*) TASImage::Open("BusyPanda_fonttest.png");
      w = im->GetWidth();
      h = im->GetHeight();
      UInt_t* arr = im->GetArgbArray();
      std::vector<double> A(w*h), r(w*h), g(w*h), b(w*h);
      fraction[i] = 0.0;
      
      // read rgb values of each pixel
      for (int j=0;j<w*h;j++){
        UInt_t val = arr[j];
        A[j] = (UInt_t)((val >> 24) & 0xFF);
        r[j] = (UInt_t)((val >> 16) & 0xFF);
        g[j] = (UInt_t)((val >>  8) & 0xFF);
        b[j] = (UInt_t)((val      ) & 0xFF);
        fraction[i] = fraction[i] + (255.0-r[j])/255.0;
      }
      
      // normalise to image size and computer modern
      fraction[i] = fraction[i]/(w*h)/cm_fraction;
      average = average + fraction[i];
      
      std::cout << ": "  << fraction[i] << std::endl;
      
    }else{
      std::cout << std::endl;
    }
  
  }
  
  average = average/18.0;
  
  // calculate error
  for (int i = 1; i < 19; i++) { 
    error = error + (fraction[i]-average)*(fraction[i]-average);    
  }
  
  error = sqrt(error/18.0);
  
  std::cout << average << " +- " << error << std::endl;

}