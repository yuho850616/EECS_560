/* -----------------------------------------------------------------------------
 * File Name: Node.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab07
 * Date: 03/31/2019
 ---------------------------------------------------------------------------- */
#ifndef Node_H
#define Node_H

class Node
{
	public:
	Node();
	// char getitem();
  // void setitem(char item);
	// bool gettag();
  // void settag(bool tag);
  // Node* getparent();
  // void setparent(Node* parent);
  // Node* getfirst();
  // void setfirst(Node* first);
  // Node* getsecond();
  // void setsecond(Node* second);
  // Node* getthird();
  // void setthird(Node* third);
	// char getminsecond();
  // void setminsecond(char minsecond);
	// char getminthird();
	// void setminthird(char minthird);
	Node* m_parent; //parent pointer
	Node* m_first; // left pointer
	Node* m_second; //middle pointer
	Node* m_third; //third pointer
	char m_smaller; //node first value
	char m_bigger; //node second value(optional)
	bool m_tag;// set to true if it's leaf node

	private:
		// Node* m_parent;
		// Node* m_first;
		// Node* m_second;
		// Node* m_third;
		// char m_smaller;
		// char m_bigger;
		// bool m_tag;
		
};
#endif
