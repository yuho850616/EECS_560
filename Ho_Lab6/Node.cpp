#include "Node.h"

Node::Node()
{
	m_leftchild = nullptr;
	m_rightchild = nullptr;
	m_value = 0;
}

Node::~Node()
{
	delete [] m_leftchild;
  delete [] m_rightchild;
}

int Node::getValue()
{
	return (m_value);
}

void Node::setValue(int value)
{
  m_value = value;
}

Node* Node::getLeft()
{
	return (m_leftchild);
}

Node* Node::getRight()
{
	return (m_rightchild);
}

void Node::setLeft(Node* left)
{
  m_leftchild = left;
}

void Node::setRight(Node* right)
{
  m_rightchild = right;
}

void Node::setWord(std::string word)
{
    m_word = word;
}

std::string Node:: getWord()
{
  return (m_word);
}
