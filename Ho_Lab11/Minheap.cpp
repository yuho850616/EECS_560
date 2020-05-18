#include "Minheap.h"
#include<cmath>
#include<ctime>

Minheap::Minheap()
{
	m_minarray = new int [10000000];
	m_size = 0;
	for(int i=0; i<10000000;i++)
	{
		m_minarray[i] = -1;
	}
	test = new int [500];
	m_testsize = 0;
	for(int i=0; i<500;i++)
	{
		test[i] = -1;
	}
}

Minheap::~Minheap()
{

}

void Minheap::clear()
{
	delete [] m_minarray;
	m_minarray = nullptr;
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
	if(m_testsize>500)
  {
    std::cout<<"Min 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_testsize++;
      test[m_testsize-1] = value;
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

void Minheap::buildheap1()
{
	for(int i= floor((m_testsize-2)/5); i>=0; i--)
  {
		bottomupheapify1(i);
	}
}

void Minheap::findmax()
{
	int max;
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
	int firstleaf=floor((m_size-2)/5)+1;
	for(int i=firstleaf; i<m_size;i++)
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
 int minvalue=0;
 int jindex;
 for(int j=1; j<=5; j++)
 {
	 int childpos = (5*index)+j;
	 if(childpos <= 10000000 && m_minarray[childpos] !=-1)
	 {
			 if(j==1)
			 {
				 minvalue = m_minarray[childpos];
				 jindex = childpos;
			 }
			 else if(m_minarray[childpos] < minvalue)
			 {
				 minvalue = m_minarray[childpos];
				 jindex = childpos;
			 }
	 }
 }
 if(minvalue!= 0 && m_minarray[index] > minvalue)
 {
	  m_minarray[jindex] = m_minarray[index];
		m_minarray[index] = minvalue;
		bottomupheapify(jindex);
 }
}

void Minheap::bottomupheapify1(int index)
{
	int j = 1;
	int smallestindex=1;
	int smallest = test[5*index+j];
	if(smallest!=-1)
	{
		while(j<6)//try five different child
		{
			if(test[5*index+j]<smallest)
			{
				if(test[5*index+j]!=(-1)) //becasue -1 will be smallter than all postiive number
				{
					smallestindex = j;
					smallest = test[5*index+j];
				}
			}
			j++;
		}
	}
	if(test[index]>smallest && smallest!= -1)
	{
		test[smallestindex+5*index] = test[index];
		test[index] = smallest;
		bottomupheapify1(5*index+smallestindex);
	}
}

void Minheap::levelorder()
{
	int node = 1;
	for(int i=0;i<500;i++)
	{
		if(test[i]!=-1)
		{
			std::cout<<test[i]<<" ";
			if(i>5)
			{
				if(i%5==0&&test[i+1]!=-1)
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

void Minheap::Performance()
{
	std::cout<<"Performance (Min-5 Heap):\n";
	std::cout<<"\t\tBuild\t\tdeleteMin\tdeleteMax\n";
	ms = 0;
	for(int i=0; i<5; i++)
	{
		if(m_minarray==nullptr)
		{
			m_minarray = new int [10000000];
			m_size = 0;
			for(int i=0; i<10000000;i++)
			{
				m_minarray[i] = -1;
			}
		}
		clock_t t;
		ms = ms + 1000000;
		srand(time(NULL));
		std::cout<<ms<<"\t\t";
		t = clock();
		for(int i=0;i<ms;i++)
		{
			int num;
			num = rand() % 5000000 + 1;
			insert(num);
		}
		buildheap();
		t= clock()-t;
		std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000 << " ms\t";
		t = clock();
     for(int i=0; i<ms/1000; i++)
		 {
       deletemin();
		 }
		 t = clock()-t;
		 std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000<<" ms\t";
     t = clock();
     for(int i=0; i<ms/1000; i++)
     {
       deletemax();
    	}
     t = clock()-t;
    std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000<<" ms\n\n";
		clear();
  }
}
