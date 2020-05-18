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
	m_arr =  new int [m_size];
	for(int i =0; i<m_size; i++)
	{
		m_arr[i] = 0;
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

Quadratic::~Quadratic()
{
	delete[] m_arr;
	delete[] m_arr1;
}

bool Quadratic::IsDuplicate(int entry)
{
		int position = 0;
		while(position<m_size)
		{
			for(int i =0; i<m_size; i++)
			{
				if(m_arr[position]==entry)
				{
					return(true);
					break;
				}
			}
		position++;
		}
		return (false);
}
bool Quadratic::IsDuplicate1(int entry)
{
	bool stop = false;
	int position = 0;
	for(int i=0;i<=k;i++)
	{
		position = (entry+i*i)%m_size1;
		if(m_arr1[position]==entry)
		{
			stop = true;
		}
	}
 return(stop);
}

void Quadratic::Print()
{
	std::cout<<"Hash Table with Quadratic Probing:\n";
	for(int i =0; i<m_size; i++)
	{
		if(m_arr[i] != 0)
		{
			std::cout<<i<<": "<<m_arr[i]<<"\n";
		}
	}
	std::cout<<"\n";
}

bool Quadratic::isEmpty(int position)
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
bool Quadratic::isEmpty1(int position)
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

void Quadratic::Insert(int entry)
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

void Quadratic::Insert1(int entry)
{
	 if(IsDuplicate1(entry)==false)
   {
     int position= Hash1(entry);
     if(m_arr1[position]==true)
    {
      m_arr1[position]=entry;
    }
    else
    {
      for(int i=1; i<=k; i++)
      {
        int bucket1 = ((position+i*i)%m_size1);
        if(isEmpty1(bucket1)==true)
        {
          m_arr1[bucket1]= entry;
          break;
        }
      }
    }
   }
}

int Quadratic::Hash(int entry)
{
		for(int i=0; i<10; i++)
		{
			int bucket = ((entry+i*i)%m_size);
			if(isEmpty(bucket)==true)
			{
				return(bucket);
				break;
			}
		}
}

int Quadratic::Hash1(int entry)
{
	int bucket = entry % m_size1;
		return(bucket);
}

void Quadratic::Print1()
{
	std::cout<<"Performance (Quadratic Probing):\n";
	std::cout<<"\t\tBuild\t\tFound\t\tNot Found\n";
	ms = 0;
	for(int i=0; i<5; i++)
	{
		 clock_t t;
		 clock_t t1;
		 double tf;
		 double tn;
		ms = ms + 100000;
		srand(time(NULL));
		std::cout<<ms<<"\t\t";
		t = clock();
		for(int i=0;i<ms;i++)
		{
			int num;
			num = rand() % 5000000 + 1;
			Insert1(num);
		}
		 t= clock()-t;
		 for(int i=0; i<ms/10; i++)
		 {
			 int num;
			 num = rand()%5000000+1;
			 t1= clock();
			 bool isfound = IsDuplicate1(num);
			 if(isfound==true)
			 {
				 tf = tf +clock()-t1;
			 }
			 else
			 {
				 tn = tn +clock()-t1;
			 }
		 }
		 std::cout<<(((double)t)/CLOCKS_PER_SEC)*1000 << " ms\t";
		 std::cout<<(((double)tf)/CLOCKS_PER_SEC)*1000<<" ms\t";
		 std::cout<<(((double)tn)/CLOCKS_PER_SEC)*1000<<" ms\n\n";
	 }
 }
