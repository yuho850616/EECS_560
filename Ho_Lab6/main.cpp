#include <iostream>
#include <string>
#include <fstream>
#include "OBST.cpp"
#include "BST.cpp"

int main(int argc, char** argv)
{
  if(argc==2)
  {
    int size = 0;
    std::string word;
    std::string fileName = argv[1];
    std::ifstream read(fileName);
    while(!read.eof())
    {
      read>>word;
      size++;
    }
    read.clear();
    read.seekg(0, std::ios::beg);
    OBST oobject(size);
    while(!read.eof())
    {
      read>>word;
      oobject.Insert1(word);
    }
    oobject.Executive();
    std::cout<<"Here is the optimal BST:\n";
    oobject.buildTree(1, oobject.newArraysize());
    oobject.PrintOBST();
    std::cout<<"\nThe minimal cost is:  "<<oobject.Mincost()<<"\n";
    std::cout<<"The file we read:  ";
    oobject.printarray2();
    std::cout<<"\nThe array sorted by ASCII value:  ";
    oobject.printarray();
    std::cout<<"\n";
    //oobject.printsize();
  }
  else
  {
    std::cout<<"Incorrect number of parameters or wrong text name.\n";
  }
  return (0);
}
