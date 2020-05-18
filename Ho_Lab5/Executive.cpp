/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
    int temp; // int in the file
    std::ifstream read;
    int choice = 0; //for the user input
    read.open(fileName);
    BST b;
    while(!read.eof())
    {
      read >> temp; // read the string until the end of file
      b.Insert(temp);
    }
    while(choice!=10)
    {
      int value; // for the value input
      int position = 0; // for the position to found
      std::cout<<"\n-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- Insert\n";
      std::cout<<"2- Delete\n";
      std::cout<<"3- Find\n";
      std::cout<<"4- DeleteMin\n";
      std::cout<<"5- DeleteMax\n";
      std::cout<<"6- Preorder\n";
      std::cout<<"7- Inorder\n";
      std::cout<<"8- Postorder\n";
      std::cout<<"9- Levelorder\n";
      std::cout<<"10- Exit\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        std::cout<<"Enter a number to be inserted: \n";
        std::cout<<">";
        std::cin>>value;
        b.Insert1(value);
        std::cout<<"\n";
      }
      else if(choice == 2)
      {
        // std::cout<<"Enter a number to be deleted: \n";
        // std::cout<<">";
        // std::cin>>value;
        // b.Delete(value);
      }
      else if(choice == 3)
      {
        std::cout<<"Enter number to be found: \n";
        std::cout<<">";
        std::cin>>value;
        b.Find(value);
      }
      else if(choice == 4)
      {
        b.deletemin();
      }
      else if(choice == 5)
      {
        b.deletemax();
      }
      else if(choice == 6)
      {
        b.Preorder();
      }
      else if(choice == 7)
      {
        b.Inorder();
      }
      else if(choice==8)
      {
        b.Postorder();
      }
      else if(choice==9)
      {
        b.Levelorder();
      }
      else if(choice<1||choice>10)
      {
        std::cout<<"Please enter choice between 1 to 10\n";
      }
      else
      {
        std::cout<<"Done!\n";
      }
    }
}

Executive::~Executive()
{

}
