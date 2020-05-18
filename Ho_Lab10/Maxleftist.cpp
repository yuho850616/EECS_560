#include "Maxleftist.h"
#include "iostream"
Maxleftist::Maxleftist()
{
  m_root = nullptr;
}

void Maxleftist::Insert(int value)
{
  // Node* newnode = new Node(value);
  // if (m_root==nullptr)
  // {
  //   m_root = newnode;
  // }
  // else
  // {
  //   m_root = Merge2(m_root, newnode);
  // }
}

Node* Maxleftist::Merge2(Node*a, Node*b)
{
  // if (a==nullptr)
  // {
  //     return b;
  // }
  // else if (b==nullptr)
  // {
  //     return a;
  // }
  // else if(a->getValue() > b->getValue())
  // {
  //     Node*temp = a;
  //     a = b;
  //     b = temp;
  // }
  // a->setRight(Merge2(a->getRight(),b));
  // addrank(a);
  // if (a->getLeft()!=nullptr)
  // {
  //     if (a->getLeft()->getRank() < a->getRight()->getRank())
  //     {
  //         Node* temp=a->getLeft();
  //         a->setLeft(a->getRight());
  //         a->setRight(temp);
  //         temp=nullptr;
  //     }
  // }
  // else
  // {
  //     Node* temp=a->getLeft();
  //     a->setLeft(a->getRight());
  //     a->setRight(temp);
  //     temp=nullptr;
  // }
  // return a;
}

void Maxleftist::addrank(Node*root)
{
  if (root->getLeft()==nullptr || root->getRight()==nullptr)
{
    root->setRank(1);
}
else
{
    if (root->getLeft()->getRank()<root->getRight()->getRank())
    {
        root->setRank(root->getLeft()->getRank()+1);
    }
    else
    {
        root->setRank(root->getRight()->getRank()+1);
    }
}
}

void Maxleftist:: Preorder()
{
   if(m_root==nullptr)
   {
     std::cout<<"The Maxleftist heap is empty\n";
   }
   else
   {
     preorder(m_root);
   }
}

void Maxleftist::preorder(Node*root)
{
  if(m_root==nullptr)
  {
    return;
  }
  std::cout<<root->getValue()<<" ";
  preorder(root->getLeft());
  preorder(root->getRight());
}

void Maxleftist::Inorder()
{
  if(m_root==nullptr)
  {
    std::cout<<"The Binary Tree is empty\n";
  }
  else
  {
    inorder(m_root);
  }
}

void Maxleftist::inorder(Node*root)
{
  if(root==nullptr)
  {
    return;
  }
  inorder(root->getLeft());
  std::cout<<root->getValue()<<" ";
  inorder(root->getRight());
}

void Maxleftist::Postorder()
{
  if(m_root==nullptr)
  {
    std::cout<<"The Binary Tree is empty\n";
  }
  else
  {
    postorder(m_root);
  }
}

void Maxleftist::postorder(Node*root)
{
  if(root==nullptr)
  {
    return;
  }
  postorder(root->getLeft());
  postorder(root->getRight());
  std::cout<<root->getValue()<<" ";
}
