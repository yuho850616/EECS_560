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
    int value; //hashtable size
    std::string temp; // string in the file
    std::ifstream read;
    int choice = 0; //for the user input
    read.open(fileName);
    read >> value; // read the size first
    Quadratic q(value);
    Doublehash d(value);
    while(!read.eof())
    {
      read >> temp; // read the string until the end of file
       q.Insert1(temp);
       d.Insert1(temp);
    }
    while(choice!=7)
    {
      std::string word; // for the string input
      int position = 0; // for the position to found
      std::cout<<"\n";
      std::cout<<"-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- Insert\n";
      std::cout<<"2- Delete\n";
      std::cout<<"3- Find\n";
      std::cout<<"4- FindPalindrome\n";
      std::cout<<"5- ReverseString\n";
      std::cout<<"6- Print\n";
      std::cout<<"7- Exit\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        std::cout<<"Enter a string to be inserted: \n";
        std::cout<<">";
        std::cin>>word;
        q.Insert(word);
        d.Insert(word);
        std::cout<<"\n";
      }
      else if(choice == 2)
      {
        std::cout<<"Enter a string to be deleted: \n";
        std::cout<<">";
        std::cin>>word;
        q.Delete(word);
        d.Delete(word);
      }
      else if(choice == 3)
      {
        std::cout<<"Enter a string to be found: \n";
        std::cout<<">";
        std::cin>>word;
        if(q.Check(word)==false&&d.Check(word)==false)
        {
          std::cout<<word<<" is not found in the hash table.\n";
        }
        else
        {
          q.Find(word);
          d.Find(word);
        }
      }
      else if(choice == 4)
      {
        q.FindPalindrome();
      }
      else if(choice == 5)
      {
        std::cout<<"Enter location of string you want to reverse: \n";
        std::cin>>position;
        q.ReverseString(position);
        d.ReverseString(position);
        std::cout<<"\n";
      }
      else if(choice == 6)
      {
        q.Print();
        d.Print();
      }
      else if(choice == 7)
      {
        std::cout<<"Done!\n";
      }
      else if(choice<1||choice>7)
      {
        std::cout<<"Please enter a choice between 1 to 7 \n";
      }
    }
}

Executive::~Executive()
{

}
