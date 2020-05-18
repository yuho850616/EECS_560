/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab10
 * Date: 04/21/2019
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
    Maxleftist mobject;
    while(read>>value) // read the string until the end of file
    {
      mobject.Insert(value);
    }
    std::cout<<"\n\nThis one is Max-leftist Heap\n\n";
    while(choice!=8)
    {
      int value; // for the value input
      std::cout<<"\n-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- Insert\n";
      std::cout<<"2- DeleteMax\n";
      std::cout<<"3- FindMax\n";
      std::cout<<"4- Preorder\n";
      std::cout<<"5- Inorder\n";
      std::cout<<"6- Postorder\n";
      std::cout<<"7- Levelordr\n";
      std::cout<<"8- Exit(Goes to Max-skew Heap)\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        std::cout<<"Enter a value to be inserted: ";
        std::cin>>value;
        mobject.Insert(value);
      }
      else if(choice == 2)
      {

      }
      else if(choice == 3)
      {

      }
      else if(choice == 4)
      {
        mobject.Preorder();
      }
      else if(choice == 5)
      {

      }
      else if(choice==6)
      {

      }
      else if(choice==7)
      {

      }
      else if(choice<1||choice>8)
      {
        std::cout<<"Please enter choice between 1 to 8\n";
      }
      else
      {
        int choice=0;
        std::cout<<"\n\nThis one is Max-skew Heap\n\n";
        while(choice!=8)
        {
          int value; // for the value input
          std::cout<<"\n-------------------------------------------------\n";
          std::cout<<"Please choose one of the following commands: \n";
          std::cout<<"1- Insert\n";
          std::cout<<"2- DeleteMax\n";
          std::cout<<"3- FindMax\n";
          std::cout<<"4- Preorder\n";
          std::cout<<"5- Inorder\n";
          std::cout<<"6- Postorder\n";
          std::cout<<"7- Levelordr\n";
          std::cout<<"8- Exit(Goes to Max-skew Heap)\n";
          std::cout<<">";
          std::cin>>choice;
          if(choice == 1)
          {

          }
          else if(choice == 2)
          {

          }
          else if(choice == 3)
          {

          }
          else if(choice == 4)
          {

          }
          else if(choice == 5)
          {

          }
          else if(choice==6)
          {

          }
          else if(choice==7)
          {

          }
          else if(choice<1||choice>8)
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
