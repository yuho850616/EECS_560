/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab04
 * Date: 02/21/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
  std::ifstream read;
  read.open(fileName);
  int num;
  int buckets = 7;
  //int buckets1 = 1000003;
  Hashtable h(buckets);
  Quadratic q(buckets);
  Doublehash d(buckets);
  while (!read.eof())
  {
    read>>num;
    h.Insert(num);
    q.Insert(num);
    d.Insert(num);
  }
  int choice = 0;
  while(choice!=3)
  {
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"Please choose one of the following commands:\n";
    std::cout<<"1- Test HashTables\n";
    std::cout<<"2- Performance Comparison\n";
    std::cout<<"3- Exit\n";
    std::cout<<">";
    std::cin>>choice;
    if(choice == 1)
    {
      h.Print();
      q.Print();
      d.Print();
    }
    else if(choice == 2)
    {
      h.Print1();
      q.Print1();
      d.Print1();
    }
    else if(choice<1 || choice>3)
    {
      std::cout<<"Please enter the valid choice between 1 to 3\n";
    }
    else
    {
      std::cout<<"Byebye!\n";
    }
 }

}
