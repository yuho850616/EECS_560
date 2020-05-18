#include "Hashtable.h"
#include <iostream>

Hashtable::Hashtable(int size)
{
  m_size = size;
  countofnum = 0;
  list = new LinkedList [size];
  for(int i=0; i<m_size; i++)
	{
		list[i] = LinkedList();
	}
}

Hashtable::~Hashtable()
{
    delete[] list;
}

void Hashtable::Insert(int entry)
{
  if(list[Hash(entry)].check(entry) == true)
	{
    std::cout<<entry<<"  is a duplicate of "<<entry<<", can’t be added to the hash table\n";
	}
	 else
	{
    double factor;
    factor = countofnum / m_size;
		if(factor >= 1)
		{
      temp_m_size = m_size;
      Rehash(Prime(m_size*2));
      list[Hash(entry)].insert(entry);
		}
		else
		{
      list[Hash(entry)].insert(entry);
      std::cout<<entry<<" is added to the hash table\n";
      countofnum++;
		}
	}
}

void Hashtable::Insert1(int entry) // this one for read file so it won't print out anything for read.
{
  if(list[Hash(entry)].check(entry) == true)
	{

	}
	 else
	{
    double factor;
    factor = countofnum / m_size;
		if(factor >= 1)
		{
      Rehash(Prime(m_size*2));
      list[Hash(entry)].insert(entry);
		}
		else
		{
      list[Hash(entry)].insert(entry);
      countofnum++;
		}
	}
}


void Hashtable::Delete(int entry)
{
  int bucket = Hash(entry);
  if(list[bucket].check(entry) == true)
	{
		list[bucket].Delete();
		std::cout<<entry<<" is removed from the hash table\n";
		countofnum--;
	}
	else
	{
		std::cout<<entry<<"  was not found\n";
	}
}

void Hashtable::Print()
{
  for(int i=0; i<m_size; i++)
	{
		std::cout<<i<<":";
		list[i].print();
	}
	std::cout<<"\n";

}

int Hashtable::Hash(int entry)
{
  int bucket = entry % m_size;
  return(bucket);
}

void Hashtable::Rehash(int newprime)
{
  temp_m_size = m_size;
  templist = new LinkedList[m_size];
  for(int i=0; i<temp_m_size; i++)
  {
    while(list[i].isEmpty()!=true)
    {
      int value = list[i].getEntry();
      templist[i].insert(value);
      list[i].Delete();
    }
  }
  m_size = newprime;
  list = new LinkedList[m_size];
  for(int i=0; i<m_size; i++)
  {
    list[i] = LinkedList();
  }

  for(int i=0; i<temp_m_size; i++)
  {
    while(templist[i].isEmpty()!=true)
    {
      int value = templist[i].getEntry();
      list[Hash(value)].insert(value);
      templist[i].Delete();
    }
  }
  std::cout<<"Hash table is rehashed.\n";
}


int Hashtable::Prime(int entry)
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

// bool Hashtable::checkprime(int entry)
// {
//   for (int i = 2; i <= entry/2; i++)
//   {
//     if (entry % i == 0)
//     {
//       return false;
//     }
//       return true;
//   }
// }

void Hashtable::Find(int entry)
{
  int bucket = Hash(entry);
  if(list[bucket].check(entry) == false)
  {
    std::cout<<entry<<"  can’t be found in the hash table.\n";
  }
  else
  {
    std::cout<<entry<<" is found at location "<<bucket<<".\n";
  }
}
