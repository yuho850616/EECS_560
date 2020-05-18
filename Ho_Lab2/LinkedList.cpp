/* -----------------------------------------------------------------------------
 * File Name: LinkedList.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab02
 * Date: 01/31/2019
 ---------------------------------------------------------------------------- */
#include <iostream>
#include <sstream>
#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_length = 0;
    m_front = nullptr;
}


LinkedList::LinkedList(const LinkedList & original)
{
  // m_length = original.getLength();
  // Node* temp = m_front;
  // for(int i=0; i<m_length; i++)
  // {
  //   m_front = new Node (original.getEntry(i));
  //   temp -> setNext(new Node(original.getEntry(i)));
  //   temp = temp -> getNext();
  // }
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


int LinkedList::getLength() const
{
  return(m_length);
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


void LinkedList::Delete()
{
  Node* ptr = m_front->getNext();
  delete m_front;
  m_front = ptr;
  m_length--;
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


int LinkedList::getEntry() const
{
   return(m_front->getValue());
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

void LinkedList::Smallest()
{
  Node* ptr = m_front;
  int smallest = 0;
  smallest = ptr ->getValue();
  while(ptr!=nullptr)
  {
    if(smallest>ptr->getValue())
    {
      smallest = ptr->getValue();
    }
    ptr = ptr -> getNext();

  }
  std::cout<<"Smallest number:"<<smallest<<"\n";
}

void LinkedList::Largest()
{
  Node* ptr = m_front;
  int largest = 0;
  largest = ptr ->getValue();
  while(ptr!=nullptr)
  {
    if(largest<ptr->getValue())
    {
      largest = ptr->getValue();
    }
    ptr = ptr -> getNext();

  }
  std::cout<<"Largest number:"<<largest<<"\n";

}

void LinkedList::Average()
{
  Node* ptr = m_front;
  double total = 0;
  while(ptr != nullptr)
  {
    total = total + ptr->getValue();
    ptr = ptr -> getNext();
  }
  double average = total/m_length;
  std::cout<<"Average: "<<average<<"\n";
}

void LinkedList::Merge2Lists()
{
  std::string newlist;
  std::cout<<"Enter new list to be merged \n";
  std::cin.ignore(1,EOF);
	getline(std::cin, newlist);
	std::stringstream ss(newlist);
  while(true)
	{
			int value;
			ss >> value;
			if(!ss)
			{
				break;
			}
			insert(value);
	}
	bubblesort();
	std::cout << "Merged List: ";
	print();
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

void LinkedList::bubblesort()
{
  Node* ptr = m_front;
  int entry = 0;
	for (int i = 0; i < m_length; i++)
	{
		while (ptr->getNext() != nullptr)
		{
      int front = ptr->getValue();
      int back = ptr->getNext()->getValue();
			if (front > back)
			{
				entry = front;
        ptr->setValue(back);
        ptr->getNext()->setValue(entry);
        ptr = ptr->getNext();
				}
			else
			{
				ptr = ptr->getNext();
			}
		}
	  ptr = m_front;
	}
}
