#ifndef Hash_table_H
#define Hash_table_H
#include "LinkedList.h"

 class Hashtable
 {
    private:
      LinkedList * list;
      LinkedList * list1;
      int m_size; // the array size
      int m_size1;
      int r;
      int k;
      int ms;
    public:
        //@pre none
        //@post contructor
        //@return none
        Hashtable(int size);
        //@pre none
        //@post destructor
        //@return none
        ~Hashtable();
        //@pre none
        //@post print out the Hashtable
        //@return none
        void Print();
        //@pre none
        //@post print out the Hashtable
        //@return none
        void Print1();
        //@pre none
        //@post to find the index
        //@return none
        int Hash(int entry);
        //@pre none
        //@post to find the index
        //@return none
        int Hash1(int entry);
        //@pre none
        //@post to read for insert. this won't print out anything
        //@return none
        void Insert(int entry);
        //@pre none
        //@post to read for insert. this won't print out anything
        //@return none
        void Insert1(int entry);
        //@pre none
        //@post to check whether the entry is IsDuplicate in the Hashtable
        //@return true of false
        bool IsDuplicate(int entry);
        bool Find(int entry);


  };
  #endif
