#include "Hashtable.h"
#include <iostream>

Hashtable::Hashtable(int size)
{
  m_size = size;
  list = new LinkedList [size];
  for(int i=0; i<m_size; i++)
	{
		list[i] = LinkedList();
	}
  m_size1 = 1000003;
  r = 100003;
  k = 20;
   list1 = new LinkedList [m_size1];
   for(int i=0; i<m_size1;i++)
   {
     list1[i] = LinkedList();
   }
}

Hashtable::~Hashtable()
{
    delete[] list;
    delete[] list1;
}

void Hashtable::Insert(int entry) // this one for read file so it won't print out anything for read.
{
  if(list[Hash(entry)].check(entry) == true)
	{

	}
	 else
	{
      list[Hash(entry)].insert(entry);
  }
}

void Hashtable::Insert1(int entry) // this one for read file so it won't print out anything for read.
{
  if(list1[Hash1(entry)].check(entry) == false)
	{
    list1[Hash1(entry)].insert(entry);
	}
	 else
	{
        //do nothing
  }
}

bool Hashtable::IsDuplicate(int entry)
{
  if(list[Hash(entry)].check(entry) == true)
  {
    return(true);
  }
   else
  {
    return(false);
  }
}

void Hashtable::Print()
{
  std::cout<<"\n";
  std::cout<<"Open Hahsing\n";
  for(int i=0; i<m_size; i++)
	{
		std::cout<<i<<":";
		list[i].print();
	}
	std::cout<<"\n";
}

void Hashtable::Print1()
{
  std::cout<<"Performance (Open Hashing):\n";
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
			 bool isfound = Find(num);
			 if(isfound==true)
			 {
				 tf = tf +clock()-t1;
			 }
			 else
			 {
				 tn = tn +clock()-t1;
			 }
		 }
     std::cout<<(((double)t)/double(CLOCKS_PER_SEC))*1000 << " ms\t";
     std::cout<<(((double)tf)/double(CLOCKS_PER_SEC))*1000<<" ms\t";
     std::cout<<(((double)tn)/double(CLOCKS_PER_SEC))*1000<<" ms\n\n";
  }
}

int Hashtable::Hash(int entry)
{
  int bucket = entry % m_size;
  return(bucket);
}

int Hashtable::Hash1(int entry)
{
  int bucket = entry % m_size1;
  return(bucket);
}

bool Hashtable::Find(int entry)
{
  int position = Hash1(entry);
  if(list1[position].check(entry)==true)
  {
    return(true);
  }
  else
  {
    return(false);
  }
}
