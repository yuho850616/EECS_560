/* -----------------------------------------------------------------------------
 * File Name: BST.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab11
 * Date: 04/28/2019
 ---------------------------------------------------------------------------- */
#ifndef BST_H
#define BST_H
#include "Node.h"

class BST{
	public:

    BST();

    ~BST();

		void destroy(Node*root);

    bool IsEmpty();

    void Insert(int value);

		void recInsert(Node*root,int value);

    void Levelorder();

		void levelorder(Node* root, int level);

		int height(Node* root);

		void deletemin();

		void deletemax();

		void Performance();


  private:

		Node*m_root;
		int ms;
};
#endif
