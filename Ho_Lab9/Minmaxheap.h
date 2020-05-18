/* -----------------------------------------------------------------------------
 * File Name: Minmaxheap.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab09
 * Date: 04/17/2019
 ---------------------------------------------------------------------------- */
 #ifndef MINMAXHEAP_H
 #define MINMAXHEAP_H
 #include "iostream"
 #include "Node.h"

class Minmaxheap
{
public:

    Node m_arr[500];
    int an;
    Minmaxheap();
    int is_min_level(int index);
    int is_max_level(int index);
    int get_parent(int index);
    int get_grand_parent(int index);
    void swap(int i, int j);
    void push_down_min(int index);
    void push_down_max(int index);
    void push_down(int index);
    void push_up_max(int index);
    void push_up_min(int index);
    void push_up(int index);
    void insert(int priority, int time);
    void buildheap();
    void print();
    void remove_min();
    int find_min_index();
    int find_max_index();
    void remove_max();
    void runschedule();
};
#endif
