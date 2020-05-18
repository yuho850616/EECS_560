#include "Minmaxheap.h"
#include<cmath>
#include<iostream>

Minmaxheap::Minmaxheap()
{
	 an = 1;
}

int Minmaxheap::is_min_level(int index)
{
	 int level = log2(index);
	 if(level % 2 == 0)
	 {
			 return (1);
	 }
	 return (0);
}
int Minmaxheap::is_max_level(int index)
{
	 int level = log2(index);
	 if(level % 2 == 1)
	 {
			 return (1);
	 }
	 return (0);
}
int Minmaxheap::get_parent(int index)
{
	 return (index / 2);
}
int Minmaxheap::get_grand_parent(int index)
{
	 return (index / 4);
}

void Minmaxheap::swap(int i, int j)
{
	 Node tem;
	 tem.priority = m_arr[i].priority;
	 m_arr[i].priority = m_arr[j].priority;
	 m_arr[j].priority = tem.priority;
	 tem.time = m_arr[i].time;
	 m_arr[i].time = m_arr[j].time;
	 m_arr[j].time = tem.time;
	 tem.process = m_arr[i].process;
	 m_arr[i].process = m_arr[j].process;
	 m_arr[j].process = tem.process;
	 tem.index = m_arr[i].index;
	 m_arr[i].index = m_arr[j].index;
	 m_arr[j].index = tem.index;
}

void Minmaxheap::push_down_min(int index)
{
	 if(index * 2 < an)
	 {
			 int smallest_index = index * 2;
			 int smallest_value = m_arr[smallest_index].priority;
			 for(int i=index * 2;i<an && i <(index + 1) * 2;i++)
			 {
					 if(m_arr[i].priority < smallest_value)
					 {
							 smallest_index = i;
							 smallest_value = m_arr[i].priority;
					 }
			 }
			 for(int i=index * 4;i<an && i <(index + 1) * 4;i++)
			 {
					 if(m_arr[i].priority < smallest_value)
					 {
							 smallest_index = i;
							 smallest_value = m_arr[i].priority;
					 }
			 }
			 if(smallest_index >= index * 4 && smallest_index < (index + 1) * 4)
			 {
					 if(m_arr[smallest_index].priority < m_arr[index].priority)
					 {
							 swap(smallest_index, index);
							 if(m_arr[smallest_index].priority > m_arr[get_parent(smallest_index)].priority)
							 {
									 swap(smallest_index, get_parent(smallest_index));
							 }
							 push_down_min(smallest_index);
					 }
			 }
			 else if(m_arr[smallest_index].priority < m_arr[index].priority)
			 {
					 swap(smallest_index, index);
			 }
	 }
}

void Minmaxheap::push_down_max(int index)
{
	 if(index * 2 < an)
	 {
			 int smallest_index = index * 2;
			 int smallest_value = m_arr[smallest_index].priority;
			 for(int i=index * 2;i<an && i <(index + 1) * 2;i++)
			 {
					 if(m_arr[i].priority > smallest_value)
					 {
							 smallest_index = i;
							 smallest_value = m_arr[i].priority;
					 }
			 }
			 for(int i=index * 4;i<an && i <(index + 1) * 4;i++)
			 {
					 if(m_arr[i].priority > smallest_value)
					 {
							 smallest_index = i;
							 smallest_value = m_arr[i].priority;
					 }
			 }
			 if(smallest_index >= index * 4 && smallest_index < (index + 1) * 4)
			 {
					 if(m_arr[smallest_index].priority > m_arr[index].priority)
					 {
							 swap(smallest_index, index);
							 if(m_arr[smallest_index].priority < m_arr[get_parent(smallest_index)].priority)
							 {
									 swap(smallest_index, get_parent(smallest_index));
							 }
							 push_down_max(smallest_index);
					 }
			 }
			 else if(m_arr[smallest_index].priority > m_arr[index].priority)
			 {
					 swap(smallest_index, index);
			 }
	 }
}

void Minmaxheap::push_down(int index)
{
	 if(is_min_level(index))
	 {
			 push_down_min(index);
	 }
	 else
	 {
			 push_down_max(index);
		}
}

void Minmaxheap::push_up_max(int index)
{
	 if(index >= 4 && m_arr[index].priority > m_arr[get_grand_parent(index)].priority)
	 {
			 swap(index, get_grand_parent(index));
			 push_up_max(get_grand_parent(index));
	 }
}

void Minmaxheap::push_up_min(int index)
{
	 if(index >= 4 && m_arr[index].priority < m_arr[get_grand_parent(index)].priority)
	 {
			 swap(index, get_grand_parent(index));
			 push_up_min(get_grand_parent(index));
	 }
}

void Minmaxheap::push_up(int index)
{
	 if(index != 1)
	 {
			 if(is_min_level(index))
			 {
					 if(m_arr[index].priority > m_arr[get_parent(index)].priority)
					 {
							 swap(index, get_parent(index));
							 push_up_max(index);
					 }
			 }
			 else
			 {
					 if(m_arr[index].priority < m_arr[get_parent(index)].priority)
					 {
							 swap(index, get_parent(index));
							 push_up_min(get_parent(index));
					 }
					 else
					 {
							 push_up_max(index);
					 }
			 }
	 }
}

void Minmaxheap::insert(int priority, int time)
{
	 m_arr[an].priority = priority;
	 m_arr[an].time = time;
	 m_arr[an].process = 0;
	 m_arr[an].index = an;
	 an++;
	 int index = an - 1;
	 int parant_index = get_parent(index);
	 push_up(index);
}

void Minmaxheap::buildheap()
{
	 FILE * fp = fopen("data.txt", "r");
	 int priority = 0;
	 int time = 0;
	 int index = 1;
	 fscanf(fp, "(%d,%d)", &priority, &time);
	 m_arr[an].priority = priority;
	 m_arr[an].time = time;
	 m_arr[an].process = 0;
	 m_arr[an].index = index++;
	 an++;

	 while(fscanf(fp, ", (%d,%d)", &priority, &time) != EOF)
	 {
			 m_arr[an].priority = priority;
			 m_arr[an].time = time;
			 m_arr[an].process = 0;
			 m_arr[an].index = index++;
			 an++;
	 }

	 for(int i=an - 1;i>=1;i--)
	 {
			 push_down(i);
	 }
}

void Minmaxheap::print()
{
	 int index = 1;
	 for(int i=1;;i*=2)
	 {
			 for(int j=0;j<i;j++)
			 {
					 if(index >= an)
					 {
							 std::cout<<"\n";
							 return;
					 }
					 printf("\tP%d(%d,%d)", m_arr[index].index, m_arr[index].priority, m_arr[index].time);
					 index++;
			 }
				std::cout<<"\n";
	 }
}

void Minmaxheap::remove_min()
{
	 if(an == 1)
	 {
			 return;
	 }
	 swap(1, an - 1);
	 an--;
	 push_down(1);
}

int Minmaxheap::find_min_index()
{
	 if(an == 1)
	 {
			 return (-1);
	 }
	 return (1);
}
int Minmaxheap::find_max_index()
{
	 if(an == 1)
	 {
			 return (-1);
	 }
	 if(an == 2)
	 {
			 return (1);
	 }
	 if(m_arr[2].priority >= m_arr[3].priority)
	 {
			 return (2);
	 }
	 return (3);
}

void Minmaxheap::remove_max()
{
	 if(an == 1)
	 {
			 return;
	 }
	 if(an == 2)
	 {
			 an--;
			 return;
	 }
	 if(an == 3)
	 {
			 an--;
			 return;
	 }
	 int index = find_max_index();
	 if(index >= 1)
	 {
			 swap(index, an - 1);
			 an--;
			 push_down(index);
	 }
}

void Minmaxheap::runschedule()
{
    Node b[500];
    int bn = 0;

    for(int i=0;i<an;i++)
    {
        b[i].priority = m_arr[i].priority;
        b[i].time = m_arr[i].time;
        b[i].process = m_arr[i].process;
        b[i].index = m_arr[i].index;
    }
    bn = an;



    std::string res[500];
    int resn = 0;
    std::cout<<"\nInitial Minmax heap:\n";
    print();
    std::cout<<"\nScheduling output:\n";
    int t = 1;
    while(an > 1)
    {
        int total_time = 0;
        if(t % 2 == 1)
        {
            printf("\nT%d: 20ms\n", t);
            total_time = 20;
            while(total_time > 0 && an > 1)
            {
                int index = find_min_index();
                printf("P%d(%d,%d), is executed.\n", m_arr[index].index, m_arr[index].priority, m_arr[index].time);
                if(m_arr[index].time > 0)
                {
                    if(total_time >= m_arr[index].time)
                    {
                        total_time -= m_arr[index].time;
                        m_arr[index].time = 0;
                        printf("P%d, is removed from heap.\n", m_arr[index].index);
                        res[resn++] = "P" + std::to_string(m_arr[index].index);
                        remove_min();
                    }
                    else
                    {
                        m_arr[index].time -= total_time;
                        total_time = 0;
                    }
                }
            }
        }
        else
        {
            printf("\nT%d: 10ms\n", t);
            total_time = 10;
            while(total_time > 0 && an > 1)
            {
                int index = find_max_index();
                printf("P%d(%d,%d), is executed.\n", m_arr[index].index, m_arr[index].priority, m_arr[index].time);
                if(m_arr[index].time > 0)
                {
                    if(total_time >= m_arr[index].time)
                    {
                        total_time -= m_arr[index].time;
                        m_arr[index].time = 0;
                        printf("P%d, is removed from heap.\n", m_arr[index].index);
                        res[resn++] = "P" + std::to_string(m_arr[index].index);
                        remove_max();
                    }
                    else
                    {
                        m_arr[index].time -= total_time;
                        total_time = 0;
                    }
                }
            }
        }

        std::cout<<"\nUpdated Minmax heap:\n";
        print();
				if(an==1)
				{
					std::cout<<"Heap is empty\n";
				}

        t++;
    }
    std::cout<<"\nScheduling order:\n";
    for(int i=0;i<resn;i++)
		{
        printf("%s ", res[i].c_str());
		}
    std::cout<<"\n";

    // recover
    for(int i=0;i<bn;i++)
    {
        m_arr[i].priority = b[i].priority;
        m_arr[i].time = b[i].time;
        m_arr[i].process = b[i].process;
        m_arr[i].index = b[i].index;
    }
    an = bn;
}
