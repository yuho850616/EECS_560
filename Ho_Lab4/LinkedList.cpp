/* -----------------------------------------------------------------------------
 * File Name: LinkedList.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab04
 * Date: 02/21/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <sstream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_length = 0;
    m_front = nullptr;
}

LinkedList::~LinkedList()
{
  clear();
}

bool LinkedList::isEmpty() const
{
  if(m_length==0)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}

void LinkedList::insert(int x)
{
    Node* front = new Node(x);
    front->setValue(x);
    front->setNext(m_front);
    if(isEmpty())
    {
         m_front = front;
         m_length++;
    }
    else
    {
         Node* temp = m_front;
         front->setNext(temp);
         m_front = front;
         m_length++;
    }
}

void LinkedList::clear()
{
  for(int i=0; i<m_length; i++)
  {
      Node* ptr = m_front;
      m_front = ptr->getNext();
      delete ptr;
  }
}

void LinkedList::print()
{
  if(m_length != 0)
  {

    Node* ptr = m_front;
    int value;
    while(ptr!=nullptr)
    {
      value = ptr->getValue();
      std::cout<<"->";
      std::cout<< value<<" ";
      ptr = ptr -> getNext();
    }
  }
  else
  {
    std::cout<<"\t";
  }
  std::cout<<"\n";
}

bool LinkedList::check(int x)
{
	Node* ptr = m_front;
	while(ptr != nullptr)
	{
    if(ptr->getValue() == x)
		{
        return true;
        ptr = nullptr;
		}
		else
		{
			ptr = ptr->getNext();
		}
	}
	return false;
}
