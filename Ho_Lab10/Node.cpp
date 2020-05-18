#include"Node.h"

Node::Node(int value){
	m_leftchild = nullptr;
	m_rightchild = nullptr;
	m_value = value;
  m_rank = 1;
}

Node::~Node(){
  // delete [] m_leftchild;
  // delete [] m_rightchild;
}

int Node::getValue(){
	return (m_value);
}

int Node::getRank(){
  return (m_rank);
}

Node* Node::getLeft(){
	return (m_leftchild);
}

Node* Node::getRight(){
	return (m_rightchild);
}

void Node::setValue(int value){
  m_value = value;
}

void Node::setLeft(Node* left){
  m_leftchild = left;
}

void Node::setRight(Node* right){
  m_rightchild = right;
}

void Node::setRank(int rank){
  m_rank = rank;
}
