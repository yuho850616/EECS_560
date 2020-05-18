#include"Node.h"
#include <iostream>

Node::Node()
{
	m_tag = true;
	m_parent = nullptr;
	m_first = nullptr;
	m_second = nullptr;
	m_third = nullptr;
	m_smaller=' ';
	m_bigger=' ';
}

// char Node::getitem()
// {
// 	return (m_item);
// }

// void Node::setitem(char item)
// {
// 	m_item = item;
// }

// bool Node::gettag()
// {
// 	return (m_tag);
// }
//
// void Node::settag(bool tag)
// {
// 	m_tag = tag;
// }
//
// Node* Node::getparent()
// {
// 	return (m_parent);
// }
//
// void Node::setparent(Node* parent)
// {
// 	m_parent = parent;
// }
//
// Node* Node::getfirst()
// {
// 	return (m_first);
// }
//
// void Node::setfirst(Node* first)
// {
// 	m_first = first;
// }
//
// Node* Node::getsecond()
// {
// 	return (m_second);
// }
//
// void Node::setsecond(Node* second)
// {
// 	m_second = second;
// }
//
// Node* Node::getthird()
// {
// 	return (m_third);
// }
//
// void Node::setthird(Node* third)
// {
// 	m_third = third;
// }
//
// char Node::getminsecond()
// {
// 	return (m_minsecond);
// }
//
// void Node::setminsecond(char minsecond)
// {
// 	m_minsecond = minsecond;
// }
//
// char Node::getminthird()
// {
// 	return (m_minthird);
// }
//
// void Node::setminthird(char minthird)
// {
// 	m_minthird = minthird;
// }
