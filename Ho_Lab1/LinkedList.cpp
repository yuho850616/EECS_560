/* -----------------------------------------------------------------------------
 * File Name: LinkedList.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab01
 * Date: 01/24/2019
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
  m_length = original.getLength();
  Node* temp = m_front;
  for(int i=0; i<m_length; i++)
  {
    m_front = new Node (original.getEntry(i));
    temp -> setNext(new Node(original.getEntry(i)));
    temp = temp -> getNext();
  }
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


void LinkedList::Insert(int x)
{
    Node* back = new Node(x);
    back->setValue(x);
    back->setNext(nullptr);
    if(isEmpty())
    {
         m_front = back;
         m_length++;
    }
    else
    {
         Node* temp = m_front;
         while(temp->getNext() != nullptr)
         {
                 temp = temp->getNext();
         }
         temp->setNext(back);
         m_length++;
    }
}


void LinkedList::Delete(int x)
{
    Node* ptr = m_front;
    if(ptr->getValue()==x) //first value
    {
      ptr = ptr->getNext();
      delete m_front;
      m_front = ptr;
      std::cout<<"Delete was successful. \n";
      m_length--;
    }
    else if(m_length==0) // enptry list
    {
      std::cout<<"Delete failed! Nothing is in the list\n";
    }
    else // goes to next node until find the value or till the last node
    {
      Node* prevptr = m_front;
      ptr = ptr->getNext();
      while (ptr!=nullptr)
      {
        if(ptr->getValue() == x)
        {
          Node *temp = ptr -> getNext();
          prevptr->setNext(temp);
          delete ptr;
          std::cout<<"Delete was successful.\n";
          m_length--;
          break;
        }
        else
        {
          prevptr = ptr;
          ptr = ptr->getNext();
        }
      }
      if(ptr == nullptr)
      {
        std::cout<<"Delete failed. Number was not found in the list.\n";
      }
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


int LinkedList::getEntry(int position) const// throw (std::runtime_error)
{
  if(position>0 && position<=m_length)
  {
    Node* ptr = m_front;
    for(int i=1; i<position; i++)
    {
      ptr = ptr -> getNext();
    }
    int value = 0;
    value = ptr -> getValue();
    return(value);
  }
  else
  {
    //throw(std::runtime_error("Position is not valid. It should be bigger than zero and smaller than length+1"));
  }
}




void LinkedList::Print()
{
  if(m_length == 0)
  {
    std::cout<<"Nothing is in the list.\n";
  }
  else
  {
    Node* ptr = m_front;
    int value;
    std::cout<<"List:";
    while(ptr!=nullptr)
    {
      value = ptr->getValue();
       std::cout<< value<<" ";
      ptr = ptr -> getNext();
    }
    std::cout<<"\n";
  }
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
			Insert(value);
	}
	bubblesort();
	std::cout << "Merged List: ";
	Print();
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
