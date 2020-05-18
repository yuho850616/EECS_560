/* -----------------------------------------------------------------------------
 * File Name: Doublehash.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab03
 * Date: 02/21/2019
 ---------------------------------------------------------------------------- */
 #include "Doublehash.h"
 #include <iostream>
 #include <stdlib.h>
 #include <time.h>
 Doublehash::Doublehash(int size)
 {
   m_size = size;
 	 m_arr =  new int[m_size];
   for(int i=0; i<m_size;i++)
   {
     m_arr[i]=0;
   }
   m_size1 = 1000003;
   r = 100003;
   k = 20;
   m_arr1 = new int [m_size1];
   for(int i=0; i<m_size1;i++)
   {
     m_arr1[i]=0;
   }
 }

 Doublehash::~Doublehash()
 {
 	delete[] m_arr;
  delete[] m_arr1;
 }

 bool Doublehash::IsDuplicate(int entry)
 {
     bool stop = false;
     for(int i =0; i<m_size; i++)
     {
       if(m_arr[i]==entry)
       {
         stop = true;
         break;
       }
     }
   return (stop);
 }

 bool Doublehash::IsDuplicate1(int entry) // to find the number can it can check for duplicate too
 {
   bool stop = false;
   int position = 0;
   for(int i=0;i<=k;i++) // check 20 times
   {
     position = (Hash1(entry)+i*(r-(entry%r)))%m_size1;
     if(m_arr1[position]==entry)
     {
       stop = true;
     }
   }
  return(stop);
 }


 void Doublehash::Print()
 {
   std::cout<<"Hash Table with Double Hashing:\n";
 	 for(int i =0; i<m_size; i++)
 	 {
 	   if(m_arr[i]!=0)
     {
 		    std::cout<<i<<": "<<m_arr[i]<<"\n";
     }
 	  }
  }

  bool Doublehash::isEmpty(int position)
  {
  	if(m_arr[position]==0)
  	{
  		return(true);
  	}
  	else
  	{
  		return(false);
  	}
  }

  bool Doublehash::isEmpty1(int position)
  {
  	if(m_arr1[position]==0)
  	{
  		return(true);
  	}
  	else
  	{
  		return(false);
  	}
  }

 void Doublehash::Insert(int entry)
 {
   if(IsDuplicate(entry) == false)
 	 {
 			int position = Hash(entry);
      m_arr[position] = entry;
 	 }
 	 else
 	 {
     //
 	 }
 }

 void Doublehash::Insert1(int entry)
 {
   if(IsDuplicate1(entry)==false)
   {
     if(m_arr1[Hash1(entry)]==true)
    {
      m_arr1[Hash1(entry)]=entry;
    }
    else
    {
      for(int i=1; i<=k; i++)
      {
        int hxplus = r - (entry%r);
        int bucket1 = ((Hash1(entry)+i*hxplus)%m_size1);
        if(isEmpty1(bucket1)==true)
        {
          m_arr1[bucket1]= entry;
          break;
        }
      }
    }
   }
 }

 int Doublehash::Hash(int entry)
 {
   int bucket = entry % m_size;
   if(m_arr[bucket]==0)
   {
     return(bucket);
   }
   else
   {
     for(int i=1; i<10; i++)
     {
       int hxplus = 5 - (entry%5);
       int bucket1 = ((bucket+i*hxplus)%m_size);
       if(isEmpty(bucket1)==true)
       {
         return(bucket1);
         break;
       }
     }
   }
 }

 int Doublehash::Hash1(int entry)
 {
   int bucket = entry % m_size1;
   return(bucket);
 }

 void Doublehash::Print1()
 {
   std::cout<<"Performance (Double Hashing):\n";
   std::cout<<"\t\tBuild\t\tFound\t\tNot Found\n";
   ms = 0;
   for(int i=0; i<5; i++)
   {
      clock_t t;
      clock_t t1;
      double found;
      double notfound;
     ms = ms + 100000;
     srand(time(NULL));
     std::cout<<ms<<"\t\t";
     int j=0;
     double acc;
     while(j<5)
     {
       t = clock();
       for(int i=0;i<ms;i++)
       {
         int num;
         num = rand() % 5000000 + 1;
         Insert1(num);
       }
      t= clock()-t;
      acc = acc + t;
      j++;
    }
      double average = acc/5;
      double build = (((double)average)/double(CLOCKS_PER_SEC))*1000;
      for(int i=0; i<ms/10; i++)
      {
        int num;
        num = rand()%5000000+1;
        t1= clock();
        bool isfound = IsDuplicate1(num);
        if(isfound==true)
        {
          found = found +clock()-t1;
        }
        else
        {
          notfound = notfound +clock()-t1;
        }
       }
      std::cout<< build<< " ms\t";
      std::cout<<(((double)found)/double(CLOCKS_PER_SEC))*1000<<" ms\t";
      std::cout<<(((double)notfound)/double(CLOCKS_PER_SEC))*1000<<" ms\n\n";
    }
  }
