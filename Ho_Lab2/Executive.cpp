#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
  std::ifstream read;
  read.open(fileName);
  int buckets;
  read >> buckets;
  Hashtable h(buckets);
  while (!read.eof())
  {
    read>>buckets;
    h.Insert1(buckets);
  }
  int choice = 0;
  while(choice!=5)
  {
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"Please choose one of the following commands:\n";
    std::cout<<"1- Insert \n";
    std::cout<<"2- Delete  \n";
    std::cout<<"3- Find\n";
    std::cout<<"4- Print \n";
    std::cout<<"5- Exit\n";
    std::cout<<">";
    std::cin>>choice;
    if(choice == 1)
    {
      int entry;
      std::cout<<"Enter a number to be inserted:\n";
      std::cout<<">";
      std::cin>>entry;
      h.Insert(entry);
      //std::cout<<entry<<" is added to the hash table\n";
    }
    else if(choice == 2)
    {
      int entry;
      std::cout<<"Enter a number to be removed:\n";
      std::cout<<">";
      std::cin>>entry;
      h.Delete(entry);
    }
    else if(choice == 3)
    {
      int entry;
      std::cout<<"Enter a number to be found:\n";
      std::cout<<">";
      std::cin>>entry;
      h.Find(entry);
    }
    else if(choice == 4)
    {
      std::cout<<"\n";
      h.Print();
    }
    else if(choice<1 || choice>5)
    {
      std::cout<<"Please enter the valid choice between 1 to 5\n";
    }
    else
    {
      std::cout<<"Bye bye!\n";
    }
 }

}
