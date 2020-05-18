/* -----------------------------------------------------------------------------
 * File Name: Node.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab10
 * Date: 04/21/2019
 ---------------------------------------------------------------------------- */
#ifndef NODE_H
#define NODE_H

class Node
{
  private:
    int m_value;
    int m_rank;
    Node * m_leftchild;
    Node * m_rightchild;

  public:
    //@pre none
    //@post make the contructor to set m_leftchild and m_rightchild to nullptr and m_value to 0
    //@return none
    Node(int value);
    //@pre none
    //@post to delete pointer
    //@return none
    ~Node();
    //@pre none
    //@post pass value into the node
    //@return value that in the node
    int getValue();
    //@pre to pass in a int
    //@post m_value will equal to the value pass in
    //@return none
    void setValue(int value);
    //@pre none
    //@post return the left pointer to the next node in list
    //@return the right next pointer
    Node * getLeft();
    //@pre none
    //@post return the left pointer to the next node in list
    //@return the right next pointer
    Node * getRight();
    //@pre to pass in a node pointer
    //@post set the node pass in equal to m_leftchild in list;
    //@return none
    void setLeft(Node*left);
    //@pre to pass in a node pointer
    //@post set the node pass in equal to m_rightchild in list;
    //@return none
    void setRight(Node*right);
    int getRank();
    void setRank(int rank);
};
#endif
