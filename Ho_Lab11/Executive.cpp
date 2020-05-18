/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab11
 * Date: 04/28/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
  std::ifstream read;
  read.open("data.txt");
  int value;
  BST b;
  Minheap m1;
  Maxheap m2;
  while (read>>value)
  {
    b.Insert(value);
    m1.insert1(value);
    m2.insert1(value);
  }
  m1.buildheap1();
  m2.buildheap1();
  int choice = 0;
  while(choice!=3)
  {
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"Please choose one of the following commands:\n";
    std::cout<<"1- Test BST/Heaps\n";
    std::cout<<"2- Performance Comparison\n";
    std::cout<<"3- Exit\n";
    std::cout<<">";
    std::cin>>choice;
    if(choice == 1)
    {
      std::cout<<"\nBST:\n";
      b.Levelorder();
      std::cout<<"\n\nMin-5 Heap:\n";
      m1.levelorder();
      std::cout<<"\n\nMax-5 Heap:\n";
      m2.levelorder();
    }
    else if(choice == 2)
    {
      b.Performance();
      m1.Performance();
      m2.Performance();
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
