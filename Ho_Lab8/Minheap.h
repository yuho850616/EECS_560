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
  //~Minheap();
 	void insert(int value);//for read file, heapify later
  void insert1(int value);// for user insert, immediate heapify;
 	void findmin();
 	void findmax();
 	void deletemin();
 	void deletemax();
 	void bottomupheapify(int index);
 	void buildheap();
  void levelorder();
  void topdownheapify(int index);

 	private:

 	int *m_minarray;
 	int m_size;
};
#endif
