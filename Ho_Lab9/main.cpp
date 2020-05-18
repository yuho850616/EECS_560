/* -----------------------------------------------------------------------------
 * File Name: main.cpp
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab09
 * Date: 04/17/2019
 ---------------------------------------------------------------------------- */
#include<iostream>
#include<fstream>
#include<string>
#include"Minmaxheap.h"

int main()
{
    setbuf(stdout, NULL);
    Minmaxheap heap;
    heap.buildheap();
    int choice = 0;
    while(choice!=7)
    {
        int value; // for the value input
        std::cout<<"\n-------------------------------------------------\n";
        std::cout<<"Please choose one of the following commands: \n";
        std::cout<<"1- Insert\n";
        std::cout<<"2- DeleteMin\n";
        std::cout<<"3- DeleteMax\n";
        std::cout<<"4- FindMin\n";
        std::cout<<"5- FindMax\n";
        std::cout<<"6- Runschedule \n";
        std::cout<<"7- Exit\n";
        std::cout<<"> ";
        scanf("%d", &choice);
        if (choice == 1)
        {
            std::cout<<"Enter the priority: ";
            int priority = 0;
            scanf("%d", &priority);
            std::cout<<"Enter the time: ";
            int time = 0;
            scanf("%d", &time);
            heap.insert(priority, time);
        }
        else if (choice == 2)
        {
            heap.remove_min();
        }
        else if (choice == 3)
        {
            heap.remove_max();
        }
        else if (choice == 4)
        {
            int index = heap.find_min_index();
            printf("P%d(%d,%d)\n", heap.m_arr[index].index, heap.m_arr[index].priority, heap.m_arr[index].time);
        }
        else if (choice == 5)
        {
            int index = heap.find_max_index();
            printf("P%d(%d,%d)\n", heap.m_arr[index].index, heap.m_arr[index].priority, heap.m_arr[index].time);
        }
        else if (choice == 6)
        {
            heap.runschedule();
        }
         else if(choice == 7)
         {
            std::cout<<"Byebye!\n";
            break;
        }
        else if(choice == 8)
        {
            heap.print();
        }
        else
        {
            std::cout<<"Invalid option input.\n";
        }
    }

}
