/* -----------------------------------------------------------------------------
 * File Name: Doublehash.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/14/2019
 ---------------------------------------------------------------------------- */
 #include "Doublehash.h"
 #include <iostream>
 using namespace std;
 Doublehash::Doublehash(int size)
 {
  m_size = size;
 	countofnum = 0;
 	m_arr =  new std::string[m_size];
 	for(int i =0; i<m_size; i++)
 	{
 		m_arr[i] = "";
 	}
 }

 Doublehash::~Doublehash()
 {
 	delete[] m_arr;
 }

 int Doublehash::Prime(int entry)
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

 bool Doublehash::IsDuplicate(std::string word)
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

 void Doublehash::Find(std::string word)
 {
   for(int i =0; i<m_size; i++)
   {
  	 if(m_arr[i] == word)
  	 {
  		 std::cout<<"Double hashing: "<<word<<" is found at location "<<i<<"\n";
  		 break;
  	 }
  	 else if(m_arr[i] == CheckReversed(word))
  	 {
  		 std::cout<<"Double hashing: "<<"'"<<word<<"'"<<" is present in reverse order at location "<<i<<"\n";
       break;
  	 }
   }
 }

 bool Doublehash::Check(std::string word)
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

 void Doublehash::ReverseString(int position)
 {
   std::string reversed = m_arr[position];
 	if(reversed =="")
 	{
 		std::cout<<"There is no string at location "<<position<<" with Double hashing.\n";
 	}
 	else
 	{
 		int last = m_arr[position].length();
 		std::cout<<"Double hashing: String '"<<reversed;
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

 void Doublehash::Print()
 {
   std::cout<<"Double hashing: \n\n";
 	 for(int i =0; i<m_size; i++)
 	 {
 	   if(m_arr[i] != "")
     {
 		    std::cout<<i<<": "<<m_arr[i]<<"\n";
     }
 	  }
  }

  std::string Doublehash::CheckReversed(std::string word)
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

  void Doublehash::FindPalindrome()
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

  bool Doublehash::isEmpty(int position)
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

  void Doublehash::Rehash()
  {
    int index = 0;
  	int rehashsize = Prime(m_size*2);
  	std::string* templist = new std::string[countofnum];
  	for(int i=0; i<m_size; i++)
  	{
  		if(m_arr[i]!="")
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
   	}
  }

  void Doublehash::Delete(std::string word)
  {
    bool stop = true;
     for(int i =0; i<m_size; i++)
     {
       if(m_arr[i]==word)
       {
         stop = false;
         m_arr[i] = "";
         countofnum--;
         std::cout<<"Double hashing: "<<word<<" is deleted from the hash table.\n";
       }
     }
   if(stop==true)
   {
       std::cout<<"Double hashing: "<<word<<" is not found in the hashtable.\n";
   }
  }

 void Doublehash::Insert(std::string word)
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
      std::cout<<"Double hashing: "<<word<<" is inserted into the hash table\n";
      m_arr[position] = word;
    }
  }
 	else
 	{
    std::cout<<"Double hashing: "<<word<<" is duplicated, can’t be added to the hash table\n";
 	}
 }

 void Doublehash::Insert1(std::string word)
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

 int Doublehash::Hash(std::string word)
 {
 	int total =0;
 	int acc =0;
  int position = 0;
 	int m_length = word.length();
  int hplus;
  int m1_length = word.length();
 	int total1 =0;
  int acc1 =0;
 	if(m1_length > 8)
  {
 		m1_length = 8;
 	}
 	char *templist1 = new char [m1_length];
 	for(int i = 0; i <m1_length; i++)
   	{
   		templist1[i] = word[i];
   	}
   	for(int i =0; i<m1_length; i++)
   	{
   		int start1 =1;
   		for(int j=0; j<i; j++)
   		{
   			start1 = start1*10;
   		}
   		acc1 = int(templist1[i])*start1;
   		total1 = total1+acc1;
   	}
  hplus = 5-(total1%5);
 	if(m_length > 8)
  {
 		m_length = 8;
 	}
 	char *templist = new char[m_length];
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
   		total = total + acc;
   	}
    for(int i=0; i<=countofnum; i++)
    {
      if(isEmpty((total+i*hplus)%m_size) == true)
      {
        m_arr[(total+i*hplus)%m_size] = word;
        position = (total+i*hplus)%m_size;
        break;
      }
    }
   	return (position);
 }
