#include "Maxheap.h"
#include<cmath>

Maxheap::Maxheap()
{
	m_size = 0;
	m_maxarray = new int [10000000];
	for(int i=0; i<10000000;i++)
	{
		m_maxarray[i] = -1;
	}
	m_testsize = 0;
	test = new int [500];
	for(int i=0; i<500;i++)
	{
		test[i] = -1;
	}
}

void Maxheap::clear()
{
	delete [] m_maxarray;
	m_maxarray = nullptr;
	m_size = 0;
}

void Maxheap::insert(int value)
{
	if(m_size>10000000)
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
	if(m_testsize>500)
  {
    std::cout<<"Max 5-Heap is full, can't insert.\n";
	}
	else
  {
      m_testsize++;
      test[m_testsize-1] = value;
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

void Maxheap::buildheap1()
{
	for(int i= floor((m_testsize-2)/5); i>=0; i--)
  {
		bottomupheapify1(i);
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
	int firstleaf=floor((m_size-2)/5)+1;
  for(int i=firstleaf; i<m_size;i++)
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
	int maxvalue=0;
	int jindex;
   for(int j=1; j<=5; j++)
	 {
     int childpos = (5*index)+j;
     if(childpos <= 10000000 && m_maxarray[childpos] !=-1)
		 {
         if(j==1)
				 {
           maxvalue = m_maxarray[childpos];
           jindex = childpos;
         }
         else if(m_maxarray[childpos] > maxvalue)
				 {
           maxvalue =m_maxarray[childpos];
           jindex = childpos;
         }
     }
   }
   if(maxvalue!= 0 && m_maxarray[index] < maxvalue)
	 {
		 m_maxarray[jindex] = m_maxarray[index];
		 m_maxarray[index] = maxvalue;
     bottomupheapify(jindex);
  }
}

void Maxheap::bottomupheapify1(int index)
{
	int j = 1;
	int largestindex=1;
	int largest = test[5*index+j];
	if(largest!=-1)
	{
		while(j<6)//try five different child
		{
			if(test[5*index+j]>largest)
			{
				if(test[5*index+j]!=(-1)) //becasue -1 will be smallter than all postiive number
				{
					largestindex = j;
					largest = test[5*index+j];
				}
			}
			j++;
		}
	}
	if(test[index]<largest && largest!= -1)
	{
		test[largestindex+5*index] = test[index];
		test[index] = largest;
		bottomupheapify1(5*index+largestindex);
	}
}

void Maxheap::levelorder()
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

void Maxheap::Performance()
{
	std::cout<<"Performance (Max-5 Heap):\n";
	std::cout<<"\t\tBuild\t\tdeleteMin\tdeleteMax\n";
	ms = 0;
	for(int i=0; i<5; i++)
	{
		if(m_maxarray==nullptr)
		{
			m_maxarray = new int [10000000];
			m_size = 0;
			for(int i=0; i<10000000;i++)
			{
				m_maxarray[i] = -1;
			}
		}
		ms = ms + 1000000;
		srand(time(NULL));
		std::cout<<ms<<"\t\t";
		clock_t t;
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
