/* -----------------------------------------------------------------------------
 * File Name: BST.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab06
 * Date: 03/19/2019
 ---------------------------------------------------------------------------- */
#ifndef BST_H
#define BST_H
#include <string>
#include "Node.cpp"

class BST
{

private:
    Node* m_root;//ptr for node

public:
    //@pre none
    //@post set m_root equal to nullptr
    //@return none
    BST();
    //@pre none
    //@post delete to avoid memory leaks
    //@return none
    ~BST();
    //@pre none
    //@post fucntion to go through bst and delete everything
    //@return none
    void destroy(Node* root);
    //@pre none
    //@post to check wheter bst is empty
    //@return true if empty else false
    bool IsEmpty();
    //@pre none
    //@post to insert word to build the tree
    //@return none
		void Insert(std::string word, int value);
    //@pre none
    //@post to insert word to build the tree (helper function)
    //@return none
    void recInsert(Node* root, int value, std::string word);
    //@pre none
    //@post to print out the optiaml bst
    //@return none
    void Print();
    //@pre none
    //@post to print out the optiaml bst (helper function)
    //@return none
    void recPrint(Node* root, int width);
};
#endif
