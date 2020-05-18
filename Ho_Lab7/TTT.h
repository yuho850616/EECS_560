/* -----------------------------------------------------------------------------
 * File Name: TTT.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab07
 * Date: 03/31/2019
 ---------------------------------------------------------------------------- */
#ifndef TTT_H
#define TTT_H
#include "Node.h"

class TTT{
	public:

    TTT();

    ~TTT();

		void destroy(Node*root);

    bool IsEmpty();

    void Insert(char value);

		void recInsert1(Node*root,char value);

		Node* kickup(Node*root, char value);

  	void Delete(char value);

		void recdelete(Node*root,char vaule);

  	void DeleteMin();

		void deletemin(Node*root);

  	void DeleteMax();

		void deletemax(Node*root);

    void FindMin();

		void findmin(Node*root);

		void FindMax();

		void findmax(Node*root);

  	void Find(char value); //this one is void for print out

		void find(Node*root,char value);

		bool Find1(char value); //this one is bool for insert and delete

		bool find1(Node*root,char value);

    void Levelorder();

		void levelorder(Node* root, int level);

		int height(Node* root);

		// void inorder(Node*root);
		//
		// void Inorder();

  private:
		Node * m_root;

};
#endif
