#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"

Executive::Executive(std::string fileName)
{
  LinkedList l;
  int value;
  std::ifstream read;
  read.open(fileName);
  while (!read.eof())
  {
    read>>value;
    l.Insert(value);
  }
  int choice = 0;
  while(choice!=8)
  {
    std::cout<<"---------------------------------------------------\n";
    std::cout<<"Choose one operation from the options below: \n";
    std::cout<<"1. Insert\n";
    std::cout<<"2. Delete \n";
    std::cout<<"3. Find Smallest number\n";
    std::cout<<"4. Find Largest number\n";
    std::cout<<"5. Average of numbers\n";
    std::cout<<"6. Merge2Lists\n";
    std::cout<<"7. Print\n";
    std::cout<<"8. Exit\n";
    std::cout<<"<<";
    std::cin>>choice;
    if(choice == 1)
    {
      int entry;
      std::cout<<"Enter element to be inserted in list:";
      std::cin>>entry;
      l.Insert(entry);
    }
    else if(choice == 2)
    {
      int entry;
      std::cout<<"Enter the number to be deleted: ";
      std::cin>>entry;
      l.Delete(entry);
    }
    else if(choice == 3)
    {
      l.Smallest();
    }
    else if(choice == 4)
    {
      l.Largest();
    }

    else if(choice == 5)
    {
      l.Average();
    }
    else if(choice ==6)
    {
      l.Merge2Lists();
    }
    else if(choice == 7)
    {
      if(l.isEmpty()==true)
      {
        std::cout<<"It's an empty list.\n";
      }
      else
      {
        l.Print();
      }
    }
    else if(choice<1 || choice>8)
    {
      std::cout<<"Please enter the valid choice between 1 to 8\n";
    }
    else
    {
      std::cout<<"Done!\n";
    }
 }

}
