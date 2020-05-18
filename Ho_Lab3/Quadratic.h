/* -----------------------------------------------------------------------------
 * File Name: Quadratic.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <string>
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
		//@post to find the number after size times 2
		//@return prime number int
		int Prime(int entry);
		//@pre none
		//@post to check whether the first 8 characters are in the hashtable
		//@return true or false
		bool IsDuplicate(std::string word);
		//@pre none
		//@post to check the word in hashtable in reversed or not
		//@return none
		void Find(std::string word);
		//@pre none
		//@post to check whether the word is in the hashtable
		//@return none
		bool Check(std::string word);
		//@pre none
		//@post to reverse the string
		//@return none
		void ReverseString(int position);
		//@pre none
		//@post to print out everything in the Quadratic probing hashtable
		//@post none
		void Print();
		//@pre none
		//@post helper function to check the word is reversed in the hashtable or not
		//@return string
		std::string CheckReversed(std::string word);
		//@pre none
		//@post to find all the Palindrome string in the hashtable
		//return none
		void FindPalindrome();
		//@pre none
		//@post to check the position in hashtable is empty or not
		//@return true or false
		bool isEmpty(int position);
		//@pre none
		//@post when the elements over the load factor rehash the size
		//@return none
		void Rehash();
		//@pre none
		//@post delete the word user inputs or tell them not found
		//return none
		void Delete(std::string word);
		//@pre none
		//@post to insert value to hashtable
		//@return none
		void Insert(std::string word);
		//@pre none
		//@post this one is for read file so it won't print out anything
		//@return none
		void Insert1(std::string word);
		//@pre none
		//@post to retunr the position
		//@return the index in array to insert
		int Hash(std::string word);

	private:
		std::string* m_arr;
		int m_size;
		int countofnum;
};
#endif
