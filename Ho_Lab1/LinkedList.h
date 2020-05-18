/* -----------------------------------------------------------------------------
 * File Name: LinkedList.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab01
 * Date: 01/24/2019
 ---------------------------------------------------------------------------- */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

class LinkedList
{
     private:
     Node* m_front;
     int m_length;

     public:
     LinkedList();
     //@pre none
     //@post create constructor and set m_length equal to 0 and m_next equal to no pointer
     //@return none
     LinkedList(const LinkedList& original);
     //@pre to make a deep copy
     //@post make new a copy
     //@return none
     ~LinkedList();
     //@pre to avoid memonry leaks
     //@post delete node in LinkedList
     //@return none
     bool isEmpty() const;
     //@pre none
     //@post to check whether the list is empty or not
     //@return true if is empty, fasle there is something
     int getLength() const;
     //@pre none
     //@post pass length into LinkedList
     //@return return length
     void Insert(int x);
     //@pre let the user to pick value and addback to insert into list
     //@post insert a new node into LinkedList
     //@return none
     void Delete(int x);
     //@pre let the user pick value to remove node in LinkedList
     //@post remove a element in LinkedList
     //@return none
     void Smallest();
     //@pre none
     //@post find the smallest element
     //@return smallest element
     void Largest();
     //@pre none
     //@post find the smallest element
     //@return Largest element
     void Average();
     //@pre  Merges the new list with the old list.
     //@post New merged list should be sorted in ascending order.
     //@return the Average element of the list.
     void Merge2Lists();
     //@pre none
     //@post  New merged list should be sorted in ascending order.
     //@return the Average element of the list.
     void clear();
     //@pre to avoid memonry leaks
     //@post delete all the nodes in LinkedList
     //@return none
     int getEntry(int position) const; //throw (std::runtime_error);
     //@pre input a position to find that value
     //@post to get the value from the selected position
     //@return to return an int
     void Print();
     //@pre none
     //@post print out the element in the LinkedList
     //@return none
     bool check(int x);
     //@pre none
     //@post to check wheter the value is in the list
     //@return true or false
     void bubblesort();
     //@pre none
     //@post sort the number from small the large
     //@return none
};
#endif
