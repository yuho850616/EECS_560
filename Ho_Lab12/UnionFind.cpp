#include "UnionFind.h"

UnionFind::UnionFind(int n)
{
	count=n;
	parent=new int[n];
	sz=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		sz[i]=1;
	}
}

UnionFind::~UnionFind()
{
	delete[] sz;
	delete[] parent;
}

int UnionFind::find(int p)
{
	while(p!=parent[p])
	{
		p=parent[p];
	}
	return (p);
}

bool UnionFind::isConnected(int p,int q)
{
	return (find(p)==find(q));
}

void UnionFind::unionElements(int p,int q)
{
	int pRoot=find(p);
	int qRoot=find(q);
	if(pRoot==qRoot)
  {
		return ;
  }

	if(sz[pRoot]<sz[qRoot])
	{
		parent[pRoot]=qRoot;
		sz[qRoot]= sz[qRoot] + sz[pRoot];
	}
	else
	{
		parent[qRoot]=pRoot;
		sz[pRoot]= sz[pRoot]+sz[qRoot];
	}
}
