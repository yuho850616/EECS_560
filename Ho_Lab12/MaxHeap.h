/* -----------------------------------------------------------------------------
 * File Name: MaxHeap.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab12
 * Date: 05/03/2019
 ---------------------------------------------------------------------------- */
#ifndef MAXHEAP_H
#define MAXHEAP_H


template <typename T>
class MaxHeap
{
	public:

		MaxHeap(int capacity)
		{
			data=new T[capacity+1];
			count=0;
		}

		~MaxHeap()
		{
			delete[] data;
		}

		int size()
		{
			return (count);
		}

		bool empty()
		{
			return (count==0);
		}

		void push(T val)
		{
			data[count+1]=val;
			ShiftUp(count+1);
			count++;
		}

		T top()
		{
			T res=data[1];
			std::swap(data[1],data[count]);
			count--;
			ShiftDown(1);
			return (res);
		}

	private:

		T* data;
		int count;
		void ShiftUp(int p)
		{
			if(p>1&&data[p/2]<data[p])
			{
				std::swap(data[p],data[p/2]);
				ShiftUp(p/2);
			}
		}
		void ShiftDown(int p)
		{
			if(p*2<=count)
			{
				int j=p*2;
				if(j+1<=count&&data[j+1]>data[j])
				{
					j=j+1;
				}
				if(data[p]<data[j])
				{
					std::swap(data[p],data[j]);
					ShiftDown(j);
				}
			}
		}
};
#endif
