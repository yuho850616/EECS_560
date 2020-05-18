/* -----------------------------------------------------------------------------
 * File Name: Quadratic.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
#include "Quadratic.h"
#include <iostream>

Quadratic::Quadratic(int size)
{
	m_size = size;
	countofnum = 0;
	m_arr =  new std::string[m_size];
	for(int i =0; i<m_size; i++)
	{
		m_arr[i] = "";
	}
}

Quadratic::~Quadratic()
{
	delete[] m_arr;
}

int Quadratic::Prime(int entry)
{
	bool flag;
	  for(int a = entry+1; 1; a++)
	  {
	    flag = true;
	    for(int b=2; b<a; b++)
	    {
	      if(a%b == 0)
	      {
	        flag = false;
	        break;
	      }
	    }
	    if(flag == true)
	    {
	      return (a);
	      break;
	    }
	  }
}

bool Quadratic::IsDuplicate(std::string word)
{
		bool Check = false;
		int position = 0;
		while(position<m_size)
		{
			int count = 0;
			for(int i =0; i<8; i++)
			{
				if(m_arr[position].substr(0,8)==word.substr(0,8))
				{
					count++;
				}
			}
			if(count==8)
			{
				Check = true;
				break;
			}
		position++;
		}
		return (Check);
}

void Quadratic::Find(std::string word)
{
 for(int i =0; i<m_size; i++)
 {
	 if(m_arr[i] == word)
	 {
		 std::cout<<"Quadratic probing: "<<word<<" is found at location "<<i<<"\n";
		 break;
	 }
	 else if(m_arr[i] == CheckReversed(word))
	 {
		 std::cout<<"Quadratic probing: "<<"'"<<word<<"'"<<" is present in reverse order at location "<<i<<"\n";
		 break;
	 }
 }
}

bool Quadratic::Check(std::string word)
{
	for(int i =0; i<m_size; i++)
  {
 	 if((m_arr[i] == CheckReversed(word)) || m_arr[i] == word)
 	 {
		 return(true);
 	 }
  }
	return(false);
}

void Quadratic::ReverseString(int position)
{
	std::string reversed = m_arr[position];
	if(reversed =="")
	{
		std::cout<<"There is no string at location "<<position<<" with Quadratic probing.\n";
	}
	else
	{
		int last = m_arr[position].length();
		std::cout<<"Quadratic probing: String '"<<reversed;
		for(int i=0; i<last/2; i++)
		{
			char temp = reversed[last-i-1];
			reversed[last-i-1] = reversed[i];
			reversed[i] = temp;
		}
		m_arr[position] = reversed;
		std::cout<<"' is changed to '"<<reversed<<"'\n";;
	}
}

void Quadratic::Print()
{
	std::cout<<"\n";
	std::cout<<"Quadratic probing:\n\n";
	for(int i =0; i<m_size; i++)
	{
		if(m_arr[i] != "")
		{
			std::cout<<i<<": "<<m_arr[i]<<"\n";
		}
	}
	std::cout<<"\n";
}

std::string Quadratic::CheckReversed(std::string word)
{
	std::string reversed = word;
	int last = reversed.length();
	if(reversed !="")
	{
		for(int i=0; i<last/2; i++)
		{
			char temp = reversed[last-i-1];
			reversed[last-i-1] = reversed[i];
			reversed[i] = temp;
		}
	}
	return (reversed);
}

void Quadratic::FindPalindrome()
{
	int printout = 0;
	std::cout<<"Palindrome strings: ";
	for(int i =0; i<m_size; i++)
	{
		std::string reversed = m_arr[i];
		bool stop = true;
		int front =0;
		int back = m_arr[i].length()-1;
		if(reversed!="")
		{
			while (front < back)
			{
				if(reversed[front] != reversed[back])
				{
					stop = false;
				}
				front++;
				back--;
			}
			if(stop == true)
			{
				printout++;
				std::cout<<reversed<<" ";
			}
		}
	}
	if(printout==0)
	{
		std::cout<<"It is empty in Palindrome list right now.";
	}
	std::cout<<"\n";
}

bool Quadratic::isEmpty(int position)
{
	if(m_arr[position]=="")
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void Quadratic::Delete(std::string word)
{
	 bool stop = true;
		for(int i =0; i<m_size; i++)
		{
			if(m_arr[i]==word)
			{
				stop = false;
				m_arr[i] = "";
				countofnum--;
				std::cout<<"Quadratic probing: "<<word<<" is deleted from the hash table.\n";
			}
		}
	if(stop==true)
	{
			std::cout<<"Quadratic probing: "<<word<<" is not found in the hashtable.\n";
	}
}

void Quadratic::Insert(std::string word)
{
	if(IsDuplicate(word) == false)
	{
		float factor;
		countofnum++;
		factor = float(countofnum)/float(m_size);
		if(factor >0.5)
		{
			Rehash();
			int position = Hash(word);
			m_arr[position] = word;
			Print();
		}
		else
		{
			int position = Hash(word);
			std::cout<<"Quadratic probing: "<<word<<" is inserted into the hash table\n";
			m_arr[position] = word;
		}
	}
	else
	{
		std::cout<<"Quadratic probing: "<<word<<" is duplicated, can’t be added to the hash table\n";
	}
}

void Quadratic::Insert1(std::string word)
{
	if(IsDuplicate(word) == false)
	{
		float factor;
		countofnum++;
		factor = float(countofnum)/float(m_size);
		if(factor >0.5)
		{
			Rehash();
			int position = Hash(word);
			m_arr[position] = word;
			Print();
		}
		else
		{
			int position = Hash(word);
			m_arr[position] = word;
		}
	}
	else
	{
		//
	}
}

void Quadratic::Rehash()
{
	int index = 0;
	int rehashsize = Prime(m_size*2);
	std::string* templist = new std::string[countofnum];
	for(int i=0; i<m_size; i++)
	{
		if(m_arr[i] != "")
		{
			templist[index] = m_arr[i];
			index++;
		}
	}
	m_size = rehashsize;
	m_arr = new std::string[m_size];
	for(int i=0; i<m_size; i++)
	{
		m_arr[i]="";
	}
	for(int i=0; i<countofnum; i++)
	{
		std::string word = templist[i];
		int position = Hash(word);
		m_arr[position] = word;
	}
	std::cout<<"Rehashing....\n\n";
}

int Quadratic::Hash(std::string word)
{
	int m_length = word.length();
	int total =0;
	int position = 0;
	int acc = 0;
	if(m_length > 8)
	{
		m_length = 8;
	}
	char * templist = new char[m_length]; // need to use char array to transfer each character to number
	for(int i = 0; i <m_length; i++)
  {
  	templist[i] = word[i];
  }
  for(int i =0; i<m_length; i++)
  {
  	int start =1;
  	for(int j=0; j<i; j++)
		{
  		start = start*10;
  	}
  	acc = int(templist[i])*start;
  	total = total+ acc;
  }
	for(int i=0; i<=countofnum; i++)
	{
		if(isEmpty((total+i*i)%m_size) == true)
		{
			m_arr[(total+i*i)%m_size] = word;
			position = (total+i*i)%m_size;
			break;
		}
	}
  	return(position);
		delete[] templist;
}
