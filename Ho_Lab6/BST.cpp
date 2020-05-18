#include "BST.h"
#include <string>
#include <iomanip>

BST::BST()
{
	m_root = nullptr;
}

BST::~BST()
{
	destroy(m_root);
}

void BST::destroy(Node* root)
{
	if(root==nullptr)
	{
		destroy(root->getLeft());
	  destroy(root->getRight());
	  delete root;
	}
}

bool BST::IsEmpty()
{
	if (m_root!=nullptr)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

void BST::Insert(std::string word, int value)
{
	recInsert(m_root,value, word);
}

void BST::recInsert(Node* root, int value, std::string word)
{
	if(IsEmpty() == true)
	{
		Node* ptr = new Node();
		ptr -> setWord(word);
		ptr -> setValue(value);
		m_root = ptr;
	}
	else if(root->getValue()>value)
	{
		if(root->getLeft() == nullptr)
		{
			Node* ptr = new Node();
			root->setLeft(ptr);
			ptr->setWord(word);
			ptr->setValue(value);
		}
		else
		{
			return (recInsert(root->getLeft(),value, word));
		}
	}
	else if (root->getValue()<=value)
	{
		if(root->getRight() == nullptr)
		{
			Node* ptr = new Node();
			root->setRight(ptr);
			ptr->setWord(word);
			ptr->setValue(value);
		}
		else
		{
			return(recInsert(root->getRight(),value, word));
		}
	}
}

void BST::Print()
{
	std::cout<<std::setw(11)<<m_root->getWord()<<"\n";
  recPrint(m_root,10);
}

void BST::recPrint(Node* root, int width)
{
	if(root != nullptr)
	{
		if(root->getRight() != nullptr&&root->getLeft()!=nullptr)
		{
				std::cout<<std::setw(width-1)<<"/";
				std::cout<<std::setw(4)<<"\\\n";
				std::cout<<std::setw(width-2)<<root->getLeft()->getWord();
				std::cout<<std::setw(6)<<root->getRight()->getWord()<<"\n";
				recPrint(root->getLeft(), width-4);
				recPrint(root->getRight(), width+4);
		}
		else if(root->getLeft() != nullptr&&root->getRight()==nullptr)
		{
			std::cout<<std::setw(width-4)<<"/"<<"\n";
			std::cout<<std::setw(width-8)<<root->getLeft()->getWord();
			recPrint(root->getLeft(), width-4);
			recPrint(root->getRight(), width+4);
		}
		else if(root->getRight() != nullptr&&root->getLeft()==nullptr)
		{
			std::cout<<std::setw(width+2)<<"\\"<<"\n";
			std::cout<<std::setw(width+4)<<root->getRight()->getWord();
			recPrint(root->getLeft(), width-4);
			recPrint(root->getRight(), width+4);
		}
	}
}
