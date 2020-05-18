#include <iostream>
#include "Adjacency.h"
#include"UnionFind.h"
#include"MaxHeap.h"


Adjacency::Adjacency()
{

}

Adjacency::~Adjacency()
{

}

void Adjacency::Buildgraph(int** costs,int n)
{
  this->graph=costs;
  this->n=n;
}

void Adjacency::BFS()
{
  //treeedge
  Edge *treeedge=new Edge;
  Edge *pt=treeedge;

  //visit record
  int visitEdge[100][100];
  memset(visitEdge,0,sizeof(visitEdge));
  visit=new int[n];
  for(int i=0;i<n;i++)
  {
    visit[i]=0;
  }
  Node* q=new Node;
  Node* end;
  q->node=0;
  q->next=nullptr;
  visit[0]=1;
  end=q;
  while(q)
  {
    for(int i=0;i<n;i++)
    {
      if(graph[q->node][i]!=-1&&visit[i]==0)
      {
        Edge *te=new Edge;
        te->a=q->node;
        te->b=i;
        te->next=nullptr;
        pt->next=te;
        pt=pt->next;
        Node* tem=new Node;
        tem->node=i;
        tem->next=nullptr;
        visit[i]=1;
        end->next=tem;
        end=end->next;
      }
    }
    Node *b=q;
    q=q->next;
    delete (b);
  }
  pt=treeedge->next;
  delete (treeedge);
  std::cout<<"TreeEdge:";
  while(pt)
  {
    std::cout<<"("<<pt->a<<","<<pt->b<<")"<<" ";
	  visitEdge[pt->a][pt->b] = 1;
	  visitEdge[pt->b][pt->a] = 1;
	  Edge *tem=pt;
    pt=pt->next;
    delete (tem);
  }
  std::cout<<"\n";
  std::cout<<"CrossEdge:";
  for (int i = 0; i < n; i++)
  {
	  for (int j = 0; j < n; j++)
	  {
		  if (i<j&&graph[i][j]>0 && visitEdge[i][j] == 0)
		  {
			  std::cout << "(" << i << "," << j << ")" << " ";
		  }
	  }
  }
  std::cout << "\n";
}

void Adjacency::DFS()
{
  Edge *treeedge=new Edge;
  Edge *pt=treeedge;
  visit=new int[n];
  for(int i=0;i<n;i++)
  {
    visit[i]=0;
  }
  //visit record
  int visitEdge[100][100];
  memset(visitEdge, 0, sizeof(visitEdge));
  _DFS(-1,0,pt);
  pt=treeedge->next;
  delete (treeedge);
  std::cout<<"TreeEdge:";
  while(pt)
  {
    std::cout<<"("<<pt->a<<","<<pt->b<<")"<<" ";
	  visitEdge[pt->a][pt->b] = 1;
	  visitEdge[pt->b][pt->a] = 1;
    Edge *tem=pt;
    pt=pt->next;
    delete (tem);
  }
  std::cout<<"\n";
  std::cout<<"BackEdge:";
  for (int i = 0; i < n; i++)
  {
	  for (int j = 0; j < n; j++)
	  {
		  if (i<j&&graph[i][j]>0&&visitEdge[i][j] == 0)
		  {
			  std::cout << "(" << i << "," << j << ")" << " ";
		  }
	  }
  }
  std::cout << "\n";
}

void Adjacency::Kruskal()
{
  int totalCost=0;
  Edge *mst=new Edge;
  mst->next=nullptr;
  Edge *p=mst;
  //priority_queue<Edge> pq;
  UnionFind uf(n);
  MaxHeap<Edge> pq(500);
  //std::cout << n << "\n";
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(graph[i][j]>0&&i<j)
      {
        Edge tem;
        tem.a=i;
        tem.b=j;
        tem.cost=graph[i][j];
        pq.push(tem);
      }
    }
  }
  while(!pq.empty())
  {
    Edge e=pq.top();
    //pq.pop();
    if(uf.isConnected(e.a,e.b))
    {
      continue;
    }
    Edge *tem=new Edge;
    tem->a=e.a;
    tem->b=e.b;
    tem->cost=e.cost;
    tem->next=nullptr;
    p->next=tem;
    p=p->next;
    uf.unionElements(e.a,e.b);
  }
  p=mst->next;
  delete (mst);
  while(p)
  {
	  if (p->a < p->b)
    {
		  std::cout << "(" << p->a << "," << p->b << ")" << "{" << p->cost << "}" << " ";
    }
	  else
    {
		  std::cout << "(" << p->b << "," << p->a << ")" << "{" << p->cost << "}" << " ";
    }
    totalCost = totalCost + p->cost;
    Edge *tem=p;
    p=p->next;
    delete (tem);
  }
  std::cout<<"\n";
  std::cout<<"Total cost="<<totalCost<<"\n";
}

void Adjacency::Prim()
{
  int totalCost=0;
  Edge *mst=new Edge;
  mst->next=nullptr;
  Edge *p=mst;
  MaxHeap<Edge> pq(500);
  int marked[100];
  memset(marked,0,sizeof(marked));
  marked[0]=1;
  for(int i=0;i<n;i++)
  {
    if(graph[0][i]>0&&marked[i]==0)
    {
        Edge te;
        te.a=0;
        te.b=i;
        te.cost=graph[0][i];
        pq.push(te);
    }
  }
  while(!pq.empty())
  {
    Edge e=pq.top();
    if(marked[e.a]==marked[e.b])
    {
      continue;
    }
    Edge *tem=new Edge;
    tem->a=e.a;
    tem->b=e.b;
    tem->cost=e.cost;
    tem->next=nullptr;
    p->next=tem;
    p=p->next;
    if(!marked[e.a])
    {
      marked[e.a]=1;
      for(int i=0;i<n;i++)
      {
        if(graph[e.a][i]>0&&marked[i]==0)
        {
            Edge te;
            te.a=e.a;
            te.b=i;
            te.cost=graph[e.a][i];
            pq.push(te);
        }
      }
    }
    else
    {
      marked[e.b]=1;
      for(int i=0;i<n;i++)
      {
        if(graph[e.b][i]>0&&marked[i]==0)
        {
            Edge te;
            te.a=e.b;
            te.b=i;
            te.cost=graph[e.b][i];
            pq.push(te);
        }
      }
    }
  }
  p=mst->next;
  delete (mst);
  while(p)
  {
	 if (p->a<p->b)
   {
		std::cout<<"("<<p->a<<","<<p->b<<")"<<"{"<<p->cost<<"}"<<" ";
   }
	 else
   {
		std::cout << "(" << p->b << "," << p->a << ")" << "{" << p->cost << "}" << " ";
   }
	 totalCost = totalCost + p->cost;
     Edge *tem=p;
     p=p->next;
     delete (tem);
  }
  std::cout<<"\n";
  std::cout<<"Total cost="<<totalCost<<"\n";
}

void Adjacency::_DFS(int parent,int node,Edge *pt)
{
  if(parent!=-1)
  {
    Edge* t=new Edge;
    t->a=parent;
    t->b=node;
    t->next=nullptr;
    pt->next=t;
    pt=pt->next;
  }
  visit[node]=1;
  for(int i=0;i<n;i++)
  {
    if(graph[node][i]!=-1&&visit[i]==0)
    {
      _DFS(node,i,pt);
      break;
    }
  }
}
