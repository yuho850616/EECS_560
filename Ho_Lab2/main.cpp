/* -----------------------------------------------------------------------------
 * File Name: main.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab02
 * Date: 01/31/2019
 ---------------------------------------------------------------------------- */
#include<iostream>
#include<fstream>
#include<string>
#include"LinkedList.h"
#include"Node.h"
#include"Hashtable.h"
#include"Executive.h"



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
