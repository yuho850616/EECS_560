/* -----------------------------------------------------------------------------
 * File Name: LinkedList.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab04
 * Date: 02/21/2019
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
     ~LinkedList();
     //@pre to avoid memonry leaks
     //@post delete node in LinkedList
     //@return none
     bool isEmpty() const;
     //@pre none
     //@post to check whether the list is empty or not
     //@return true if is empty, fasle there is something
     void insert(int x);
     //@pre let the user pick position to remove node in LinkedList
     //@post remove a element in LinkedList
     //@return none
     void clear();
     //@pre to avoid memonry leaks
     //@post delete all the nodes in LinkedList
     //@return none
     void print();
     //@pre none
     //@post print out the element in the LinkedList
     //@return none
     bool check(int x);
     //@pre none
     //@post to check wheter the value is in the list
     //@return true or false
};
#endif
