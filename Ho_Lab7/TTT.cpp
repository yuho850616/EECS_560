#include "TTT.h"
#include<iostream>

TTT::TTT()
{
  m_root = nullptr;
}

TTT::~TTT()
{
  delete m_root;
}

Node*TTT::kickup(Node*root, char item)
{
  Node*first = new Node;
  Node*second = new Node;
  if(item>root->m_bigger) //new value bigger than both of two nodes
  {
    first->m_smaller=root->m_smaller; //roots first value become its left childs first value
    second->m_smaller = item; //new value becomes root's right child first value
    root->m_smaller=root->m_bigger; //roots second value become its first value(the one get kicked up)
    root->m_bigger=' ';
    root->m_first = first;
    root->m_second= second;
    first->m_parent= root;
    second->m_parent=root;
  }
  else if(item<root->m_smaller)// new value smaller than both of two nodes
  {
    first->m_smaller = item; //new value becomes root's left child first value
    root->m_smaller = root->m_smaller; //roots first value become the parent of two nodes(the one get kicked up)
    second->m_smaller = root->m_bigger; //roots second value become first value of right child
    root->m_bigger = ' '; //clear the second value in root
    root->m_first = first;
    root->m_second = second;
    first->m_parent = root;
    second->m_parent = root;
  }
  else // the insert values between two values get kicked up
  {
    first->m_smaller=root->m_smaller; //root's smaller become left child's smaller
    second->m_smaller = root-> m_bigger; //root's larger become rights childs smaller
    root->m_smaller=item; // new insert value is partent of nodes(get kick up)
    root->m_bigger=' ';
    root->m_first=first;
    root->m_second=second;
    first->m_parent=root;
    second->m_parent=root;
  }
  root->m_tag=false;
  return(root);
}

void TTT::Insert(char item)
{
  Node * ptr = m_root;
  if(m_root == nullptr)//first node
  {
    m_root = new Node;
    m_root->m_smaller = item;
	}
  else if(m_root->m_first==nullptr&&m_root->m_second==nullptr&&m_root->m_third==nullptr)//second or third
  {
    if(m_root->m_bigger==' ')//root's node seond value
    {
      if(m_root->m_smaller<item)//just insert to original nodes right side
      {
        m_root->m_bigger = item;
      }
      else //swap first two nodes
      {
        char val = m_root->m_smaller;
        m_root->m_smaller = item;
        m_root->m_bigger = val;
      }
    }
    else //need to kick up middle value for third one
    {
      m_root=kickup(m_root,item);
    }
  }
  else
  {
    while(ptr->m_tag!=true) //need to get leaf nodes
    {
      if(ptr->m_smaller!=' ' && ptr->m_bigger!=' ')//node have two value, 2-3 have three pointers
      {
        if(item > ptr->m_bigger)
        {
          ptr = ptr-> m_third; // go right more to find the spot
        }
        else if(item<ptr->m_smaller)
        {
          ptr = ptr-> m_first; //go left more to find the spot
        }
        else //right between two values
        {
          ptr =ptr->m_second;
        }
      }
      else//node has only one value
      {
        if(item > ptr->m_smaller)
        {
          ptr = ptr->m_second; // need to go find larger value spot to insert
        }
        else
        {
          ptr= ptr->m_first; //need to go find smaller value spot to insert
        }
      }
    }
    if(ptr->m_bigger!=' ') //node is leaf and have two value
    {
      Node* root= kickup(ptr,item);
      Node* m_parent = ptr->m_parent;
      if(m_parent->m_third==nullptr&&m_parent!=nullptr)
      {
        if(m_parent->m_second == ptr)
        {
          m_parent->m_second=nullptr;
        }
        else if(m_parent->m_first == ptr)
        {
          m_parent->m_first = nullptr;
        }
      }
      if(m_parent->m_third==nullptr)
      {
        if(m_parent->m_second==nullptr)
          {
            m_parent->m_tag=false;
            m_parent->m_second=root->m_first;
            m_parent->m_third=root->m_second;
            m_parent->m_second->m_tag=true;
            m_parent->m_third->m_tag=true;
            m_parent->m_bigger=root->m_smaller;
          }
          else if(m_parent->m_first==nullptr)
          {
            m_parent->m_tag=false;
            m_parent->m_first=root->m_first;
            m_parent->m_bigger=m_parent->m_smaller;
            m_parent->m_smaller=root->m_smaller;
            m_parent->m_third=m_parent->m_second;
            m_parent->m_second=root->m_second;
            m_parent->m_first->m_tag=true;
            m_parent->m_second->m_tag=true;
            m_parent->m_third->m_tag=true;
          }
      }
      else
      {
        Node* w=m_parent->m_parent;
          Node* m1=new Node;
          Node* m2=new Node;
          if(m_parent->m_smaller>root->m_smaller)
          {
            m1->m_tag=false;
            m2->m_tag=false;
            m1->m_first=m_parent;
            m2->m_first=m_parent->m_second;
            m1->m_second=m2;
            m2->m_second=m_parent->m_third;
            m1->m_smaller=m_parent->m_smaller;
            m2->m_smaller=m_parent->m_bigger;
            m2->m_parent=m1;
            m2->m_first->m_parent = m2;
            m2->m_second->m_parent = m2;
            m_parent->m_first=root->m_first;
            m_parent->m_second=root->m_second;
            m_parent->m_third=nullptr;
            m_parent->m_parent=m1;
            m_parent->m_smaller=root->m_smaller;
            m_parent->m_bigger=' ';
          }
          m_root = m1;
          delete root;
      }
    }
    else//node is leaf but only have one value
    {
      if(ptr->m_smaller<item)
      {
        ptr->m_bigger= item; //inset right of the value in biggervalue spot
      }
      else //swap two values in the same node
      {
        char val = ptr->m_smaller;
        ptr->m_smaller = item;
        ptr->m_bigger = val;
      }
    }
  }
}


bool TTT::IsEmpty()
{
  if(m_root==nullptr)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

void TTT::FindMin()
{
  if(IsEmpty()==true)
  {
    std::cout<<"Nothing in the tree.\n";
  }
  else
  {
    findmin(m_root);
  }
}


void TTT::findmin(Node*root)
{
    while(root->m_tag!=true)
    {
      if(root->m_first!=nullptr)
      {
        root = root->m_first;
      }
    }
    std::cout<<root->m_smaller;
}

void TTT::DeleteMin()
{
  if(IsEmpty()==true)
  {
    std::cout<<"Delete was unsuccessful\n";
  }
  else
  {
    std::cout<<"Delete was successful\n";
    deletemin(m_root);
  }
}

void TTT::deletemin(Node*root)
{
  while(root->m_tag!=true)
  {
    if(root->m_first!=nullptr)
    {
      root = root->m_first;
    }
  }
  if(root->m_bigger !=' ')
  {
    root->m_smaller = root->m_bigger;
    root->m_bigger = ' ';
  }
  else
  {
    root->m_smaller = ' ';
    delete root;
  }
}

void TTT::FindMax()
{
  if(IsEmpty()==true)
  {
    std::cout<<"Nothing in the tree\n";
  }
  else
  {
    findmax(m_root);
  }
}

void TTT::findmax(Node* root)
{
  while(root->m_tag!=true)
  {
    if(root->m_third!=nullptr)
    {
      root = root->m_third;
    }
    else if(root->m_second!=nullptr)
    {
      root = root->m_second;
    }
    else
    {
      root = root->m_first;
    }
  }
  if(root->m_bigger==' ')
  {
    std::cout<<root->m_smaller;
  }
  else
  {
   std::cout<<root->m_bigger;
  }
}

void TTT::DeleteMax()
{
  if(IsEmpty()==true)
  {
    std::cout<<"Delete was unsuccessful\n";
  }
  else
  {
    std::cout<<"Delete was successful\n";
    deletemax(m_root);
  }
}

void TTT::deletemax(Node*root)
{
  while(root->m_tag!=true)
  {
    if(root->m_third!=nullptr)
    {
      root = root->m_third;
    }
    else if(root->m_second!=nullptr)
    {
      root = root->m_second;
    }
    else
    {
      root = root->m_first;
    }
  }
  if(root->m_bigger==' ')
  {
    root->m_smaller=' ';
    delete root;
  }
  else
  {
    root->m_bigger=' ';
  }
}

void TTT::Levelorder()
{
  int h = height(m_root);
  for (int i=1; i<=h; i++)
  {
    levelorder(m_root, i);
  }
}

void TTT::levelorder(Node* root, int level){
  if (root == nullptr)
  {
    return;
  }
  if(level == 1)
  {
    if(root->m_bigger!=' ')
    {
      std::cout<<root->m_smaller<<" ";
      std::cout<<root->m_bigger<<" ";
    }
    else
    {
      std::cout<<root->m_smaller<<" ";
    }
  }
   else if (level > 1)
   {
     levelorder(root->m_first, level-1);
     levelorder(root->m_second, level-1);
     levelorder(root->m_third, level-1);
   }
}

int TTT::height(Node* root){
  if(root==nullptr)
  {
    return 0;
  }
  else
  {
    int h = height(root->m_first);
    return(h+1);
  }
}

void TTT::Find(char value)
{
  if(IsEmpty()==true)
  {
    std::cout<<"The tree is empty\n";
  }
  else
  {
    find(m_root,value);
  }
}

void TTT::find(Node*root,char value)
{
  if(root==nullptr)
  {
    std::cout<<"Character not found in tree\n";
  }
  else if(root->m_third!=nullptr)
  {
    if(root->m_smaller==value)
    {
      std::cout<<"Character found in tree\n";
    }
    else if(root->m_bigger==value)
    {
      std::cout<<"Character found in tree\n";
    }
    else if(value>root->m_bigger)
    {
      find(root->m_third,value);
    }
    else if(value<root->m_smaller)
    {
      find(root->m_first,value);
    }
    else
    {
      find(root->m_second,value);
    }
  }
  else
  {
    if(root->m_smaller==value)
    {
      std::cout<<"Character found in tree\n";
    }
    else if(root->m_bigger==value)
    {
      std::cout<<"Character found in tree\n";
    }
    else if(value < root->m_smaller)
    {
      find(root->m_first,value);
    }
    else if(value > root->m_bigger)
    {
      find(root->m_second,value);
    }
    else
    {
      std::cout<<"Character not found in tree\n";
    }
  }
}

bool TTT::Find1(char value)
{
  if(IsEmpty()==true)
  {
    return(false);
  }
  else
  {
    return find1(m_root,value);
  }
}

bool TTT::find1(Node*root,char value)
{
  if(root==nullptr)
  {
    return (false);
  }
  else if(root->m_third!=nullptr)
  {
    if(root->m_smaller==value)
    {
      return(true);
    }
    else if(root->m_bigger==value)
    {
      return(true);
    }
    else if(value>root->m_bigger)
    {
      return find1(root->m_third,value);
    }
    else if(value<root->m_smaller)
    {
      return find1(root->m_first,value);
    }
    else
    {
      return find1(root->m_second,value);
    }
  }
  else
  {
    if(root->m_smaller==value)
    {
      return(true);
    }
    else if(root->m_bigger==value)
    {
      return(true);
    }
    else if(value < root->m_smaller)
    {
      return find1(root->m_first,value);
    }
    else if(value > root->m_bigger)
    {
      return find1(root->m_second,value);
    }
  }
}

void TTT::Delete(char value)
{
  if(IsEmpty()==true)
  {
    std::cout<<"Delete was unsuccessful\n";
  }
  else if(Find1(value)==false)
  {
    std::cout<<"Delete was unsuccessful\n";
  }
  else
  {
    std::cout<<"Delete was successful\n";
    recdelete(m_root, value);
  }
}

void TTT::recdelete(Node*root,char value)
{
  // if(root->m_third!=nullptr)
  // {
  //   if(root->m_smaller==value)
  //   {
  //     Node*target = root;
  //   }
  //   else if(root->m_bigger==value)
  //   {
  //     Node*target = root;
  //   }
  //   else if(value>root->m_bigger)
  //   {
  //     return recdelete(root->m_third,value);
  //   }
  //   else if(value<root->m_smaller)
  //   {
  //     return recdelete(root->m_first,value);
  //   }
  //   else
  //   {
  //     return recdelete(root->m_second,value);
  //   }
  // }
  // else
  // {
  //   if(root->m_smaller==value)
  //   {
  //     Node*target = root;
  //   }
  //   else if(root->m_bigger==value)
  //   {
  //     Node*target = root;
  //   }
  //   else if(value < root->m_smaller)
  //   {
  //     return recdelete(root->m_first,value);
  //   }
  //   else if(value > root->m_bigger)
  //   {
  //     return recdelete(root->m_second,value);
  //   }
  // }
  // if(root->m_tag==true)
  // {
  //   if(root==m_root)
  //   {
  //     if(root->m_bigger==' ')
  //     {
  //       delete root;
  //       root = nullptr;
  //       m_root = nullptr;
  //       root->m_smaller = ' ';
  //     }
  //     else
  //     {
  //       char val = root->m_bigger;
  //       root->m_bigger = ' ';
  //       root->m_smaller = val;
  //     }
  //   }
  //   else if(root)
  //   {
  //
  //   }
  // }
}



// void TTT::Inorder()
// {
//   if(IsEmpty()==true){
//     std::cout<<"Tree is empty\n";
//   }
//   else{
//     inorder(m_root);
//   }
// }
//
// void TTT::inorder(Node*m_root){
//   if(m_root==nullptr){
//     return;
//   }
//   inorder(m_root->getfirst());
//   std::cout<<m_root->getitem()<<" ";
//   inorder(m_root->getthird());
// }
