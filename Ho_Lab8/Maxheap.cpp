#include "Maxheap.h"
#include<cmath>

Maxheap::Maxheap()
{
	m_size = 0;
	for(int i=0; i<500;i++)
	{
		m_maxarray[i] = -1;
	}
}

void Maxheap::insert(int value)
{
	if(m_size>500)
  {
    std::cout<<"Max 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_size++;
      m_maxarray[m_size-1] = value;
  }
}

void Maxheap::insert1(int value)
{
	if(m_size>500)
  {
    std::cout<<"Min 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_size++;
      m_maxarray[m_size-1] = value;
			topdownheapify(m_size-1);
  }
}

void Maxheap::topdownheapify(int index)
{
	int parent = floor((index-1)/5);
	while(parent>=0)
	{
		if(m_maxarray[index]>m_maxarray[parent])
		{
			int value = m_maxarray[index];
			m_maxarray[index]=m_maxarray[parent];
			m_maxarray[parent]=value;
			index = parent;
			parent = floor((index-1)/5);
		}
		else
		{
			break;
		}
	}
}

void Maxheap::buildheap()
{
	for(int i= floor((m_size-2)/5); i>=0; i--)
  {
		bottomupheapify(i);
	}
}

void Maxheap::findmax()
{
  std::cout<<"Max value is: "<<m_maxarray[0]<<"\n";
}

void Maxheap::deletemax()
{
  m_maxarray[0] = m_maxarray[m_size-1];
  m_maxarray[m_size-1] = -1;
  m_size--;
  bottomupheapify(0);
}

void Maxheap::findmin()
{
  int min = m_maxarray[0];
	for(int i=0; i<m_size;i++)
  {
		if(m_maxarray[i]<min)
    {
			min = m_maxarray[i];
		}
	}
	std::cout<<"Min value is: "<<min<<"\n";
}

void Maxheap::deletemin()
{
  int index;
  int min = m_maxarray[0];
  for(int i=0; i<m_size;i++)
  {
    if(m_maxarray[i]<min)
    {
      min = m_maxarray[i];
      index = i;
    }
  }
	m_maxarray[index]=m_maxarray[m_size-1];
	m_maxarray[m_size-1]=-1;
	m_size--;
	if(m_maxarray[index]!=-1)
	{
		topdownheapify(index);
	}
}

void Maxheap::bottomupheapify(int index)
{
	int j = 1;
	int largestindex=1;
	int largest = m_maxarray[5*index+j];
	if(largest!=-1)
	{
		while(j<6)//try five different child
		{
			if(m_maxarray[5*index+j]>largest)
			{
				if(m_maxarray[5*index+j]!=(-1)) //becasue -1 will be smallter than all postiive number
				{
					largestindex = j;
					largest = m_maxarray[5*index+j];
				}
			}
			j++;
		}
	}
	if(m_maxarray[index]<largest && largest!= -1)
	{
		m_maxarray[largestindex+5*index] = m_maxarray[index];
		m_maxarray[index] = largest;
		bottomupheapify(5*index+largestindex);
	}
}

void Maxheap::levelorder()
{
	int node = 1;
	for(int i=0;i<500;i++)
	{
		if(m_maxarray[i]!=-1)
		{
			std::cout<<m_maxarray[i]<<" ";
			if(i>5)
			{
				if(i%5==0&&m_maxarray[i+1]!=-1)
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
