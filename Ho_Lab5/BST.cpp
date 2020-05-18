#include "BST.h"
#include<iostream>

BST::BST(){
  m_root = nullptr;
}

BST::~BST(){
    destroy(m_root);
}

void BST::destroy(Node*root){
  // if(root==nullptr)
  //   {
  //        return;
  //   }
  //    destroy(root->getLeft());
  //    destroy(root->getRight());
  //    delete root;
}

bool BST::IsEmpty(){
  if(m_root==nullptr){
    return(true);
  }
  else{
    return(false);
  }
}

void BST::Insert(int value){
  recInsert(m_root,value);
}

void BST::recInsert(Node*root, int value){
  if(IsEmpty()==true){
    Node*ptr = new Node(value);
    m_root = ptr;
    ptr->setValue(value);
  }
  else if(root->getValue()>value){
      if(root->getLeft()==nullptr){
        Node*ptr = new Node(value);
        root->setLeft(ptr);
        ptr->setValue(value);
      }
      else{
        return recInsert(root->getLeft(),value);
      }
    }
    else if(root->getValue()<=value){
      if(root->getRight()==nullptr){
        Node*ptr = new Node(value);
        root->setRight(ptr);
        ptr->setValue(value);
      }
      else{
        return recInsert(root->getRight(),value);
      }
    }
}

void BST::Insert1(int value){
  recInsert1(m_root,value);
}

void BST::recInsert1(Node*root, int value){
  if(IsEmpty()==true){
    Node*ptr = new Node(value);
    m_root = ptr;
    ptr->setValue(value);
    std::cout<<"Insert was successful.\n";
  }
  else if(root->getValue()>value){
      if(root->getLeft()==nullptr){
        Node*ptr = new Node(value);
        root->setLeft(ptr);
        ptr->setValue(value);
        std::cout<<"Insert was successful.\n";
      }
      else{
        return recInsert1(root->getLeft(),value);
      }
    }
    else if(root->getValue()<=value){
      if(root->getRight()==nullptr){
        Node*ptr = new Node(value);
        root->setRight(ptr);
        ptr->setValue(value);
        std::cout<<"Insert was successful.\n";
      }
      else{
        return recInsert1(root->getRight(),value);
      }
    }
}

void BST::FindMin(){
  findMin(m_root);
}

void BST::findMin(Node* root){
  while(root->getLeft() != nullptr){
		root = root->getLeft() ;
	}
	std::cout<<"Minimum number:"<<root->getValue()<<"\n";
}

void BST::FindMax()
{
  findMax(m_root);
}

void BST::findMax(Node* root){
  while(root->getRight() != nullptr){
		root = root->getRight() ;
	}
	std::cout<<"Maximum number:"<<root->getValue()<<"\n";
}

void BST::Find(int value){
  if(IsEmpty()){
    std::cout<<"The Binary tree is empty\n";
  }
  else{
    return find(m_root,value);
  }
}

void BST::find(Node*root, int value){
  if(root==nullptr){
    std::cout<<"Number is not present in tree.\n";
  }
  else if(root->getValue()==value){
    std::cout<<"Number is present in tree.\n";
  }
  else if(root->getValue()>value){
    return find(root->getLeft(),value);
  }
  else if(root->getValue()<value){
    return find(root->getRight(),value);
  }
}

void BST:: Preorder()
{
   if(IsEmpty()==true){
     std::cout<<"The Binary Tree is empty\n";
   }
   else{
     preorder(m_root);
   }
}

void BST::preorder(Node*root){
  if(root==nullptr){
    return;
  }
  std::cout<<root->getValue()<<" ";
  preorder(root->getLeft());
  preorder(root->getRight());
}

void BST::Postorder()
{
  if(IsEmpty()==true){
    std::cout<<"The Binary Tree is empty\n";
  }
  else{
    postorder(m_root);
  }
}

void BST::postorder(Node*root){
  if(root==nullptr){
    return;
  }
  postorder(root->getLeft());
  postorder(root->getRight());
  std::cout<<root->getValue()<<" ";
}

void BST::Inorder(){
  if(IsEmpty()==true){
    std::cout<<"The Binary Tree is empty\n";
  }
  else{
    inorder(m_root);
  }
}

void BST::inorder(Node*root){
  if(root==nullptr){
    return;
  }
  inorder(root->getLeft());
  std::cout<<root->getValue()<<" ";
  inorder(root->getRight());
}

void BST::Levelorder(){
  int h = height(m_root);
  for (int i=1; i<=h; i++){
    levelorder(m_root, i);
    std::cout<<"\n";
  }
}

void BST::levelorder(Node* root, int level){
  if (root == nullptr){
    return;
  }
  if(level == 1){
    std::cout<<root->getValue()<<" ";
  }
   else if (level > 1){
     levelorder(root->getLeft(), level-1);
     levelorder(root->getRight(), level-1);
   }
}

int BST::height(Node* root){
  if(root==nullptr){
    return 0;
  }
  else{
    int left = height(root->getLeft());
    int right = height(root->getRight());
    if (left > right){
      return(left+1);
    }
    else{
      return(right+1);
    }
  }
}

void BST::deletemin()
{
    if(IsEmpty()==true)
    {
      std::cout<<"Binary search tree is empty" << "\n";
    }
    else
    {
      Node* ptr = m_root;
      if(ptr->getLeft() != nullptr)
      {
        Node* next = ptr->getLeft();
        while(next->getLeft() != nullptr)
        {
            ptr = ptr->getLeft();
            next = next->getLeft();
        }
        if(next->getRight() == nullptr)
        {
            //next = nullptr;
            delete next;
            ptr->setLeft(nullptr);
        }
        else
        {
            Node*temp = next->getRight();
            ptr->setLeft(temp);
            next = nullptr;
            delete next;
        }
      }
      else
      {
        m_root = ptr->getRight();
        ptr=nullptr;
        delete ptr;
      }
   }
}

void BST::deletemax()
{
  if(IsEmpty()==true)
  {
    std::cout<<"Binray search tree is empty" << "\n";
  }
  else
  {
    Node* ptr = m_root;
    if(ptr->getRight() != nullptr)
    {
      Node* next = ptr->getRight();
      while(next->getRight() != nullptr)
      {
          ptr = ptr->getRight();
          next = next->getRight();
      }
      if(next->getLeft() != nullptr)
      {
        ptr->setRight(next->getLeft());
        next = nullptr;
        delete next;
      }
      else
      {
        next = nullptr;
        delete next;
        ptr->setRight(nullptr);
      }
    }
    else
    {
      m_root = ptr->getLeft();
      ptr = nullptr;
      delete ptr;
    }
  }
}
