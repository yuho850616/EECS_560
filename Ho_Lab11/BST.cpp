#include "BST.h"
#include<iostream>

BST::BST(){
  m_root = nullptr;
}

BST::~BST(){
    //destroy(m_root);
}

void BST::destroy(Node*root){
  if(root==nullptr)
  {
       return;
  }
   destroy(root->getLeft());
   destroy(root->getRight());
   delete root;
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

void BST::Levelorder(){
  int h = height(m_root);
  for (int i=1; i<=h; i++){
    levelorder(m_root, i);
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
            next = nullptr;
            delete next;
            ptr->setLeft(nullptr);
        }
        else
        {
            ptr->setLeft(next->getRight());
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

void BST::Performance()
{
  std::cout<<"Performance (BST):\n";
  std::cout<<"\t\tBuild\t\tdeleteMin\tdeleteMax\n";
  ms = 0;
  for(int i=0; i<5; i++)
  {
    ms = ms + 1000000;
    srand(time(NULL));
    std::cout<<ms<<"\t\t";
    clock_t t;
    t = clock();
    for(int i=0;i<ms;i++)
    {
      int num;
      num = rand() % 5000000 + 1;
      Insert(num);
    }
    t= clock()-t;
    std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000 << " ms\t";
    t = clock();
     for(int i=0; i<ms/1000; i++)
     {
       int num;
       num = rand()%5000000+1;
       deletemin();
     }
     t = clock()-t;
     std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000<<" ms\t";
     t = clock();
     for(int i=0; i<ms/1000; i++)
     {
        int num;
        num = rand()%5000000+1;
        deletemax();
      }
     t = clock()-t;
     std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000<<" ms\n\n";
  }
}
