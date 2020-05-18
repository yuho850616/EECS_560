#include "OBST.h"
#include "iostream"

OBST::OBST(int times)
{
  int_max = 10000;
  index = 0;
  m_size = times;
  m_arr1 = new std::string[m_size];
  m_arr2 = new std::string[m_size];
}
OBST::~OBST()
{
  delete[] m_arr1;
  delete[] m_arr2;
  delete[] diagonal;
  delete[] cost;
  delete[] table;
}

int OBST::ASCII(std::string word)
{
  int accumulator=0;
  int total=0;
  for(int i=0; i<word.length(); i++)
  {
    accumulator = word.at(i);
    total = total + accumulator;
  }
  //std::cout<<total<<"\n";
  return (total);
}

double OBST::Probability(std::string word)
{
  double frequencey = 0;
  double probability = 0;
  for(int i=0; i<m_size; i++)
  {
    if(word == m_arr1[i])
    {
      frequencey++;
    }
  }
  probability = frequencey/double(m_size);
  //std::cout<<probability<<"\n";
  return (probability);
}

void OBST::Insert1(std::string word)
{
  m_arr1[index] = word;
  index++;
}

bool OBST::isDuplicate(std::string word)
{
  bool status = false;
  for(int i =0; i<=element; i++)
  {
    if(m_arr2[i] == word)
    {
      status = true;
      break;
    }
  }
  return (status);
}

double OBST::Sum(int x, int y)
{
  double sum =0;
  for(int i = x; i<= y; i++)
  {
    sum = sum + diagonal[i];
  }
  return (sum);
}

void OBST::Executive()
{
  m_arr2[0] = m_arr1[0];
  for(int i =1; i<m_size; i++)
  {
    if(!isDuplicate(m_arr1[i]))
    {
      element++;
      m_arr2[element] = m_arr1[i];
    }
  }
  m_newsize = element+1;
  for(int i=0;i<m_newsize;i++)
	{
	   for(int j=i+1;j<m_newsize;j++)
		 {
			 if(ASCII(m_arr2[i]) > ASCII(m_arr2[j]))
			 {
         std::string temp = m_arr2[i];
				 m_arr2[i]=m_arr2[j];
				 m_arr2[j]=temp;
			  }
		  }
	}
  diagonal = new double[m_newsize]; //to store probability like 1,1 2,2 3,3 4,4
  cost = new double*[m_newsize]; // this table is 2d array to calculate min cost
  table = new int*[m_newsize];
  for(int i =0; i<m_newsize; i++)
  {
    diagonal[i] = Probability(m_arr2[i]);
    cost[i] = new double[m_newsize];
    table[i] =  new int[m_newsize];
  }
  int kvalue =0;
  for(int i = 0; i<m_newsize; i++)
  {
    cost[i][i] = diagonal[i]; //store the diagonl p1 p2 p3 p4 to 4*4 table(in this example)
    table[i][i] = i+1;
  }
  for(int x = 2; x<=m_newsize; x++)
  {
    for(int i=0; i<=m_newsize-x; i++)
    {
      int j = i+x-1;
      cost[i][j] = int_max;
      for(int y=i; y<= j; y++)
      {
        double micost = ((y > i)? cost[i][y-1]:0) + ((y < j)? cost[y+1][j]:0) + Sum(i, j);
        if (micost < cost[i][j])
        {
          cost[i][j] = micost;
          kvalue = y;
        }
        table[i][j] = kvalue+1;
      }
    }
  }
  min = cost[0][m_newsize-1];
}

double OBST::Mincost()
{
  return (min);
}

int OBST::newArraysize()
{
  return (m_newsize);
}

void OBST::printarray()
{
  for(int i=0 ; i<m_newsize; i++)
  {
    std::cout<<m_arr2[i]<<" ";
  }
}

void OBST::printarray2()
{
  for(int i=0; i<m_size; i++)
  {
    std::cout<<m_arr1[i]<<" ";
  }
}

void OBST::printsize()
{
  std::cout<<"array size read from file: "<<m_size<<"\n";
  std::cout<<"array size after sorted: "<<m_newsize<<"\n";
}

void OBST::buildTree(int i, int j)
{
  if (j >= i)
  {
    element++;
    m_root.Insert(m_arr2[table[i-1][j-1]-1],table[i-1][j-1]);
    buildTree(i,table[i-1][j-1]-1);
    buildTree(table[i-1][j-1]+1,j);
  }
}

void OBST::PrintOBST()
{
  m_root.Print();
}
