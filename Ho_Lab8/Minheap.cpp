#include "Minheap.h"
#include<cmath>

Minheap::Minheap()
{
	m_size = 0;
	m_minarray= new int[10000000];
	for(int i=0; i<10000000;i++)
	{
		m_minarray[i] = -1;
	}
}

void Minheap::insert(int value)
{
	if(m_size>10000000)
  {
    std::cout<<"Min 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_size++;
      m_minarray[m_size-1] = value;
  }
}

void Minheap::insert1(int value)
{
	if(m_size>10000000)
  {
    std::cout<<"Min 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_size++;
      m_minarray[m_size-1] = value;
			topdownheapify(m_size-1);
  }
}

void Minheap::topdownheapify(int index)
{
	int parent = floor((index-1)/5);
	while(parent>=0)
	{
		if(m_minarray[index]<m_minarray[parent])
		{
			int value = m_minarray[index];
			m_minarray[index]=m_minarray[parent];
			m_minarray[parent]=value;
			index = parent;
			parent = floor((index-1)/5);
		}
		else
		{
			break;
		}
	}
}

void Minheap::buildheap()
{
	for(int i= floor((m_size-2)/5); i>=0; i--)
  {
		bottomupheapify(i);
	}
}

void Minheap::findmax()
{
	int max;
	// int left = 0;
	// int exp=0;
	// while(m_minarray[left]!=-1)
	// {
	// 	left = left + pow(5,exp);
	// 	exp++;
	// }
	// left = (left-1)/5;
	for(int i=0; i<m_size;i++)
  {
		if(m_minarray[i]>max)
    {
			max = m_minarray[i];
		}
	}
	std::cout<<"Max value is: "<<max<<"\n";
}

void Minheap::deletemax()
{
	int index;
	int max;
	// int left = 0;
	// int exp=0;
	// while(m_minarray[left]!=-1)
	// {
	// 	left = left + pow(5,exp);
	// 	exp++;
	// }
	// left = (left-1)/5;
	for(int i=0; i<m_size;i++)
	{
		if(m_minarray[i]>max)
		{
			max = m_minarray[i];
			index = i;
		}
	}
	m_minarray[index]=m_minarray[m_size-1];
	m_minarray[m_size-1]=-1;
	m_size--;
	if(m_minarray[index]!=-1)
	{
		topdownheapify(index);
	}
}

void Minheap::findmin()
{
	std::cout<<"Min value is: "<<m_minarray[0]<<"\n";
}

void Minheap::deletemin()
{
	m_minarray[0] = m_minarray[m_size-1];
	m_minarray[m_size-1] = -1;
	m_size--;
	bottomupheapify(0);
}

void Minheap::bottomupheapify(int index)
{
	int j = 1;
	int smallestindex=1;
	int smallest = m_minarray[5*index+j];
	if(smallest!=-1)
	{
		while(j<6)//try five different child
		{
			if(m_minarray[5*index+j]<smallest)
			{
				if(m_minarray[5*index+j]!=(-1)) //becasue -1 will be smallter than all postiive number
				{
					smallestindex = j;
					smallest = m_minarray[5*index+j];
				}
			}
			j++;
		}
	}
	if(m_minarray[index]>smallest && smallest!= -1)
	{
		m_minarray[smallestindex+5*index] = m_minarray[index];
		m_minarray[index] = smallest;
		bottomupheapify(5*index+smallestindex);
	}
}

void Minheap::levelorder()
{
	int node = 1;
	for(int i=0;i<10000000;i++)
	{
		if(m_minarray[i]!=-1)
		{
			std::cout<<m_minarray[i]<<" ";
			if(i>5)
			{
				if(i%5==0&&m_minarray[i+1]!=-1)
				{
					std::cout<<"- ";
				}
			}
		}
		else
		{
			break;
		}
		if(i%node==0)
		{
			std::cout<<"\n";
			node = node*5;
		}
	}
}
