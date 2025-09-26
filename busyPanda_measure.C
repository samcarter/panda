// root -l busyPanda_measure.C+

#include <iostream>
#include <sstream>
#include <fstream>

#include "TASImage.h"
#include "TSystem.h"

void busyPanda_measure(){
  
  bool lualatex = false;
  bool bold = false;
  
  string compiler, fontsfilename, line;
  string font[10000] = {};
  int i, size, w, h;
  double fraction;
  TASImage* im;
  double cm_fraction = 0.1424935;
  
  // switching compiler
  if( lualatex ){
    compiler = "lualatex";
    fontsfilename = "busyPanda_fonts_lualatex.dat";
  }else{
    compiler = "pdflatex";
    fontsfilename = "busyPanda_fonts_pdflatex.dat";
  }
  
  // reading in fonts from file
  std::ifstream infile(fontsfilename);
  i = 0;
  while (std::getline(infile, line)){
    line.pop_back();
    font[i] =  line;
    i=i+1;
  }
  size = i;
  
  std::ofstream ofile("tmp.tex");
  
  for (int i = 0; i < size; i++) { 
    
    std::cout << i << " " << font[i];
    
    // generating sample png
    std::ostringstream cmd;
    if( bold ){
      cmd << compiler << " --interaction=batchmode '\\def\\quack{" << font[i] << "}\\AtBeginDocument{\\bfseries}\\input{busyPanda_fonttest.tex}' > /dev/null";
    }else{
      cmd << compiler << " --interaction=batchmode '\\def\\quack{" << font[i] << "}\\input{busyPanda_fonttest.tex}' > /dev/null";
    }
    int ret = gSystem->Exec(cmd.str().c_str());
    
    if ( ret == 0 ){

      gSystem->Exec("pdftocairo -png -r 2000 -singlefile busyPanda_fonttest.pdf busyPanda_fonttest");
      
      // open image
      im = (TASImage*) TASImage::Open("busyPanda_fonttest.png");
      w = im->GetWidth();
      h = im->GetHeight();
      UInt_t* arr = im->GetArgbArray();
      std::vector<double> A(w*h), r(w*h), g(w*h), b(w*h);
      fraction = 0.0;
      
      // read rgb values of each pixel
      for (int j=0;j<w*h;j++){
        UInt_t val = arr[j];
        A[j] = (UInt_t)((val >> 24) & 0xFF);
        r[j] = (UInt_t)((val >> 16) & 0xFF);
        g[j] = (UInt_t)((val >>  8) & 0xFF);
        b[j] = (UInt_t)((val      ) & 0xFF);
        fraction = fraction + (255.0-r[j])/255.0;
      }
      
      // normalise to image size and computer modern
      fraction = fraction/(w*h)/cm_fraction;
      
      std::cout << ": "  << fraction << std::endl;
      if (fraction > 0.0) {
        if( lualatex ){
          ofile << "      {" << font[i] << "(0)}{"  << fraction << "}" << std::endl;
        }else{
          ofile << "      {" << font[i] << "}{"  << fraction << "}" << std::endl;
        }
      }
      
    }else{
      std::cout << std::endl;
    }
  
  }
  
  ofile.close();
  
}