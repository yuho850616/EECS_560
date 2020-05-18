#ifndef MAXLEFTIST_H
#define MAXLEFTIST_H
#include "Node.h"


class Maxleftist{
    public:
      Maxleftist();
      //~Maxleftist();
      void Buildheap(int value);
      void Insert(int value);
      void DeleteMax();
      void Findmax();
      Node* Merge2(Node*H1, Node*H2);
      void Preorder();
      void preorder(Node*root);
      void Inorder();
      void inorder(Node*root);
      void Postorder();
      void postorder(Node*root);
      void Levelorder();
      void addrank(Node*root);

    private:

    Node * m_root;
};
#endif
