/* -----------------------------------------------------------------------------
 * File Name: Executive.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab12
 * Date: 05/04/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <fstream>
#include <string>
#include "Executive.h"
#include "Adjacency.h"


Executive::Executive(std::string fileName)
{
    int value; // int in the file
    std::ifstream read;
    int choice = 0; //for the user input
    read.open(fileName);
    int n;
    read>>n;
    //std::cout<<"n:"<<n<<"\n";
    int **data;
    data=new int*[n];
    for(int i=0;i<n;i++)
    {
      data[i]=new int [n];
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        read>>data[i][j];
      }
    }
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<n;j++)
    //   {
    //     std::cout<<data[i][j]<<" ";
    //   }
    //   std::cout<<"\n";
    // }
    Adjacency adjacency;
    adjacency.Buildgraph(data,n);
    // while(!read.eof()) // read the string until the end of file
    // {
    //   read>>value;
    //   mobject.insert(value);
    //   mobject1.insert(value);
    // }
    while(choice!=5)
    {
      int value; // for the value input
      std::cout<<"\n-------------------------------------------------\n";
      std::cout<<"Please choose one of the following commands: \n";
      std::cout<<"1- BFS\n";
      std::cout<<"2- DFS\n";
      std::cout<<"3- Kruskal MST\n";
      std::cout<<"4- Prim MST\n";
      std::cout<<"5- Exit\n";
      std::cout<<">";
      std::cin>>choice;
      if(choice == 1)
      {
        adjacency.BFS();
      }
      else if(choice == 2)
      {
        adjacency.DFS();
      }
      else if(choice == 3)
      {
        adjacency.Kruskal();
      }
      else if(choice == 4)
      {
        adjacency.Prim();
      }
      else if(choice<1||choice>5)
      {
        std::cout<<"Please enter choice between 1 to 5\n";
      }
      else
      {
        for(int i=0;i<n;i++)
          delete[] data[i];
          delete[] data;
        std::cout<<"Byebye!\n";
      }
    }
  }

Executive::~Executive()
{

}
