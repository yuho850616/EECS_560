/* -----------------------------------------------------------------------------
 * File Name: Maxheap.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab08
 * Date: 04/04/2019
 ---------------------------------------------------------------------------- */
 #ifndef MAXHEAP_H
 #define MAXHEAP_H
 #include "iostream"

 class Maxheap
 {
  public:

  Maxheap();
  //~Minheap();
 	void insert(int value);//for read file, heapify later
  void insert1(int value);
 	void findmin();
 	void findmax();
 	void deletemin();
 	void deletemax();
 	void bottomupheapify(int index);
  void bottomupheapify1(int index);
 	void buildheap();
  void buildheap1();
  void levelorder();
  void topdownheapify(int index);
  void Performance();
  void clear();

 	private:
  int ms;
 	int *m_maxarray;
  int *test;
 	int m_size;
  int m_testsize;
};
#endif
