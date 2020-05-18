/* -----------------------------------------------------------------------------
 * File Name: Hashtable.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab02
 * Date: 01/31/2019
 ---------------------------------------------------------------------------- */
 #ifndef Hashtable_H
 #define Hashtable_H
 #include "LinkedList.h"

 class Hashtable
 {
    private:
      LinkedList * list;
      LinkedList * templist;
      int m_size; // the array size
      int countofnum; //how many numbers
      int temp_m_size;
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
        //@post insert the value into Hashtable
        //@return none
        void Insert(int entry);
        //@pre none
        //@post remove the value from Hashtable
        //@return none
        void Delete(int entry);
        //@pre none
        //@post print out the Hashtable
        //@return none
        void Print();
        //@pre none
        //@post to check whether the value is in the Hashtable
        //@return none
        void Find(int entry);
        //@pre none
        //@post to find the index
        //@return none
        int Hash(int entry);
        //@pre none
        //@post rehash the size
        //@return none
        void Rehash(int newprime);
        //@pre none
        //@post to find the next prime number
        //@return the prime number
        int Prime(int entry);
        //@pre none
        //@post to check is there other factor or not
        //@return true of false
        bool checkprime(int entry);
        //@pre none
        //@post to read for insert. this won't print out anything
        //@return none
        void Insert1(int entry);
  };
  #endif
