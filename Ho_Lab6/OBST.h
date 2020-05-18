/* -----------------------------------------------------------------------------
 * File Name: OBST.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab06
 * Date: 03/19/2019
 ---------------------------------------------------------------------------- */
#ifndef OBST_H
#define OBST_H
#include <string>
#include "BST.h"

class OBST
{
public:
  //@pre none
  //@post set m_root equal to nullptr and creat array we read and array after sorted
  //@return none
  OBST(int times);
  //@pre none
  //@post delete all the pointers
  //@return none
  ~OBST();
  //@pre none
  //@post to check whether the word is duplicate in the array(no duplicate allow in new array)
  //@return true if duplicate false if not
  bool isDuplicate(std::string word);
  //@pre none
  //@post to calculate ASCII value for the string
  //@return ASCII value
  int ASCII(std::string word);
  //@pre none
  //@post tp calculate the probability for that string
  //@return the probability for that string(int)
  double Probability(std::string word);
  //@pre none
  //@post insert data.txt into arrays
  //@return none
  void Insert1(std::string word);
  //@pre none
  //@post to return sum of probability. Like p1 or p1+p2 or p1+p2+p3
  //@return the sum of probability, it's double since it's zero point something.
  double Sum(int i, int j);
  //@pre none
  //@post to pass the value after probability and ascii function, after that find the min cost.
  //@return none
  void Executive();
  //@pre none
  //@post return the Mincost fomr Executive function
  //@return double minocst
  double Mincost();
  //@pre none
  //@post return the newarray size;
  //@return int m_newsize
  int newArraysize();
  //@pre none
  //@post to print the array we infile
  //@return none
  void printarray();
  //@pre none
  //@post to print the array after sorted
  //@return none
  void printarray2();
  //@ore none
  //@post to print the size for m_arr1 and m_arr2
  //@return none
  void printsize();
  //@pre none
  //@post to build the optimal BST for print out
  //@return none
  void buildTree(int i, int j);
  //@pre none
  //@post to print out the tree from function in BST
  //@post none
  void PrintOBST();

private:
  std::string* m_arr1; //array we pass in
  int m_size; //m_arr1 size
  std::string* m_arr2; //array after sorted
  int m_newsize; //m_arr2 size
  double* diagonal; // array to store probability lile p1 p2 p3 p4
  double** cost; // 2d array to store min cost in table
  int index; // index for m_arr1 Insert
  int element; //if is not duplicate +1
  double min; //mincost
  BST m_root; // to call function in BST
  int int_max; // value for find mincost
  int** table; // int type 2d array for drawing tree
};
#endif
