/* -----------------------------------------------------------------------------
 * File Name: Node.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab06
 * Date: 03/19/2019
 ---------------------------------------------------------------------------- */
#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
private:
  int m_value;
  std::string m_word;
  Node* m_leftchild;
  Node* m_rightchild;

public:
  //@pre none
  //@post make the contructor to set m_leftchild and m_rightchild to nullptr and m_value to 0
  //@return none
  Node();
  //@pre none
  //@post to delete pointer
  //@return none
  ~Node();
  //@pre none
  //@post none
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
  //@pre to pass in a string
  //@post m_word will equal to the string pass in
  //@return none
  void setWord(std::string word);
  //@pre none
  //@post none
  //@return string that in the node
  std::string getWord();

};
#endif
