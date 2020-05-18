/* -----------------------------------------------------------------------------
 * File Name: Quadratic.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
#ifndef QUADRATIC_H
#define QUADRATIC_H
class Quadratic
{
	public:
		//@pre none
    //@post to read the size and initialize everything
    //@return none
		Quadratic(int size);
		//@pre none
		//@post to delete all pointers
		//@return none
		~Quadratic();
		//@pre none
		//@post to check whether the first 8 characters are in the hashtable
		//@return true or false
		bool IsDuplicate(int entry);
		//@pre none
		//@post to check whether the first 8 characters are in the hashtable
		//@return true or false
		bool IsDuplicate1(int entry);
		//@pre none
		//@post to print out everything in the Quadratic probing hashtable
		//@post none
		void Print();
		//@pre none
		//@post to print out everything in the Quadratic probing hashtable
		//@post none
		void Print1();
		//@pre none
		//@post to check the position in hashtable is empty or not
		//@return true or false
		bool isEmpty(int position);
		//@pre none
		//@post to check the position in hashtable is empty or not
		//@return true or false
		bool isEmpty1(int position);
		//@pre none
		//@post this one is for read file so it won't print out anything
		//@return none
		void Insert(int entry);
		//@pre none
		//@post this one is for read file so it won't print out anything
		//@return none
		void Insert1(int entry);
		//@pre none
		//@post to retunr the position
		//@return the index in array to insert
		int Hash(int entry);
		//@pre none
		//@post to retunr the position
		//@return the index in array to insert
		int Hash1(int entry);
		bool Find(int entry);

	private:
		int* m_arr;
		int* m_arr1;
		int m_size;
		int m_size1;
		int r;
		int k;
		int ms;
};
#endif
