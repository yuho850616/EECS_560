/* -----------------------------------------------------------------------------
 * File Name: Minheap.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab08
 * Date: 04/04/2019
 ---------------------------------------------------------------------------- */
 #ifndef MINHEAP_H
 #define MINHEAP_H
 #include "iostream"

 class Minheap
 {
  public:

  Minheap();
  ~Minheap();
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
  int *m_minarray;
  int *test;
  int m_testsize;
 	int m_size;
  int ms;
};
#endif
