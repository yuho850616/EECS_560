/* -----------------------------------------------------------------------------
 * File Name: BST.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab05
 * Date: 02/28/2019
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

		void Insert1(int value);

		void recInsert1(Node*root,int value);

  	void Delete(int value);

		void recdelete(Node*root,int vaule);

  	void FindMin();

		void findMin(Node*root);

  	void FindMax();

		void findMax(Node*root);

    void Find(int value);

		void find(Node*root, int value);

		bool Find1(int value);

		bool find1(Node*root, int value);

  	void Preorder();

		void preorder(Node*root);

  	void Postorder();

		void postorder(Node*root);

  	void Inorder();

		void inorder(Node*root);

    void Levelorder();

		void levelorder(Node* root, int level);

		int height(Node* root);

		int findmin(Node* root);

		void deletemin();

		void deletemax();


  private:

		Node*m_root;

};
#endif
