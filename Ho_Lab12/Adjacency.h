/* -----------------------------------------------------------------------------
 * File Name: Adjacency.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab12
 * Date: 05/03/2019
 ---------------------------------------------------------------------------- */
 #ifndef ADJACENCY_H
 #define ADJACENCY_H
 #include "iostream"

 class Adjacency
 {

  public:
    typedef struct Node{
    int node;
    struct Node *next;
    }Node;

    typedef struct Edge{
		int a;
		int b;
		int cost;
		struct Edge *next;
		bool operator <(const struct Edge &t) const
		{
		  return cost>t.cost;
		};
		bool operator >(const struct Edge &t) const
		{
		  return cost<t.cost;
		};
    }Edge;

  Adjacency();
  ~Adjacency();
  void Buildgraph(int** costs,int n);
  void BFS();
  void DFS();
  void Kruskal();
  void Prim();

private:
  int **graph;
  int n;
  int *visit;
  void _DFS(int parent,int node,Edge* pt);
};
#endif
