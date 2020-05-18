/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab7
 * Date: 03/31/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
    char temp; // int in the file
    std::ifstream read;
    int choice = 0; //for the user input
    read.open(fileName);
    TTT tobject;
    // while(!read.eof()) // read the string until the end of file
    // {
    //   read>>temp;
    //   tobject.Insert(temp);
    // }
    while(read>>temp)
    {
      tobject.Insert(temp);
    }
    while(choice!=9)
    {
      char character; // for the character input
      //int position = 0; // for the position to found
      std::cout<<"\n-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- Insert\n";
      std::cout<<"2- Delete\n";
      std::cout<<"3- DeleteMin\n";
      std::cout<<"4- DeleteMax\n";
      std::cout<<"5- Find\n";
      std::cout<<"6- FindMin\n";
      std::cout<<"7- FindMax\n";
      std::cout<<"8- LevelOrder\n";
      std::cout<<"9- Exit\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        std::cout<<"Enter characeter to be inserted: \n";
        std::cout<<">";
        std::cin>>character;
        if(tobject.Find1(character)==true)
        {
          std::cout<<"Insert was unsuccessful\n";
        }
        else
        {
          tobject.Insert(character);
          std::cout<<"Insert was successful\n";
        }

      }
      else if(choice == 2)
      {
        std::cout<<"Enter characeter to be deleted: \n";
        std::cout<<">";
        std::cin>>character;
        tobject.Delete(character);
      }
      else if(choice == 3)
      {
        tobject.DeleteMin();
      }
      else if(choice == 4)
      {
        tobject.DeleteMax();
      }
      else if(choice == 5)
      {
        std::cout<<"Enter character to be found\n";
        std::cin>>character;
        tobject.Find(character);
      }
      else if(choice == 6)
      {
        tobject.FindMin();
      }
      else if(choice == 7)
      {
        tobject.FindMax();
      }
      else if(choice==8)
      {
        tobject.Levelorder();
      }
      else if(choice<1||choice>9)
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
