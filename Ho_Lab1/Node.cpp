/* -----------------------------------------------------------------------------
 * File Name: Node.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab01
 * Date: 01/24/2019
 ---------------------------------------------------------------------------- */
#include "Node.h"
Node::Node(int value)
{
    m_value = value;
    m_next = nullptr;
}


int Node::getValue()const
{
  return(m_value);
}


void Node::setValue(int value)
{
  m_value = value;
}


Node* Node::getNext()const
{
  return(m_next);
}


void Node::setNext(Node* next)
{
  m_next = next;
}
