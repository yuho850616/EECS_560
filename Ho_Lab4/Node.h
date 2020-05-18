/* -----------------------------------------------------------------------------
 * File Name: Node.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab04
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
#ifndef NODE_H
#define NODE_H

class Node
{
  private:
    int m_value;
    Node * m_next;

  public:
    Node(int value);
    //@pre none
    //@post make the contructor to set m_sext to nullptr and m_value to 0
    //@return none
    int getValue()const;
    //@pre none
    //@post pass value into the node
    //@return value that in the node
    void setValue(int value);
    //@pre to pass in a int
    //@post m_value will equal to the value pass in
    //@return none
    Node * getNext()const;
    //@pre none
    //@post turn the pointer to the next node in list
    //@return next pointer
    void setNext(Node*next);
    //@pre to pass in a node pointer
    //@post set the node pass in equal to m_next in list;
    //@return none
};
#endif
