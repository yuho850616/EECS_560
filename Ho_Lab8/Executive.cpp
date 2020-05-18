/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab7
 * Date: 04/05/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
    int value; // int in the file
    std::ifstream read;
    int choice = 0; //for the user input
    read.open(fileName);
    Minheap mobject;
    Maxheap mobject1;
    while(!read.eof()) // read the string until the end of file
    {
      read>>value;
      mobject.insert(value);
      mobject1.insert(value);
    }
    mobject.buildheap();
    mobject1.buildheap();
    std::cout<<"\n\nThis one is Min-5 Heap\n\n";
    while(choice!=7)
    {
      int value; // for the value input
      std::cout<<"\n-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- Insert\n";
      std::cout<<"2- DeleteMin\n";
      std::cout<<"3- DeleteMax\n";
      std::cout<<"4- FindMin\n";
      std::cout<<"5- FindMax\n";
      std::cout<<"6- LevelOrder\n";
      std::cout<<"7- Exit(Goes to Max-5 Heap)\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        std::cout<<"Enter a value to be inserted: ";
        std::cin>>value;
        mobject.insert1(value);
        mobject.levelorder();
      }
      else if(choice == 2)
      {
        mobject.deletemin();
        mobject.levelorder();
      }
      else if(choice == 3)
      {
        mobject.deletemax();
        mobject.levelorder();
      }
      else if(choice == 4)
      {
        mobject.findmin();
      }
      else if(choice == 5)
      {
        mobject.findmax();
      }
      else if(choice==6)
      {
        mobject.levelorder();
      }
      else if(choice<1||choice>7)
      {
        std::cout<<"Please enter choice between 1 to 7\n";
      }
      else
      {
        int choice=0;
        std::cout<<"\n\nThis one is Max-5 Heap\n\n";
        while(choice!=7)
        {
          int value; // for the value input
          std::cout<<"\n-------------------------------------------------\n";
          std::cout<<"Please choose one of the following commands: \n";
          std::cout<<"1- Insert\n";
          std::cout<<"2- DeleteMin\n";
          std::cout<<"3- DeleteMax\n";
          std::cout<<"4- FindMin\n";
          std::cout<<"5- FindMax\n";
          std::cout<<"6- LevelOrder\n";
          std::cout<<"7- Exit(Exit the program)\n";
          std::cout<<">";
          std::cin>>choice;
          if(choice == 1)
          {
            std::cout<<"Enter a value to be inserted: ";
            std::cin>>value;
            mobject1.insert1(value);
            mobject1.levelorder();
          }
          else if(choice == 2)
          {
            mobject1.deletemin();
            mobject1.levelorder();
          }
          else if(choice == 3)
          {
            mobject1.deletemax();
            mobject1.levelorder();
          }
          else if(choice == 4)
          {
            mobject1.findmin();
          }
          else if(choice == 5)
          {
            mobject1.findmax();
          }
          else if(choice==6)
          {
            mobject1.levelorder();
          }
          else if(choice<1||choice>7)
          {
            std::cout<<"Please enter choice between 1 to 7\n";
          }
          else
          {
            std::cout<<"Byebye\n";
            break;
          }
        }
      }
    }
}

Executive::~Executive()
{

}
