/* -----------------------------------------------------------------------------
 * File Name: main.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
 #include "Quadratic.h"
 #include "Doublehash.h"
 #include "Executive.h"
 #include <iostream>
 #include <fstream>
 #include <string>
 int main(int argc, char** argv)
 {
  if(argc==2)
  {
    std::string fileName = argv[1];
    std::ifstream read;
    read.open(fileName);
    Executive exe(fileName);
  }
  else
  {
    std::cout<<"Incorrect number of parameters or wrong text name.\n";
  }
return(0);
}
