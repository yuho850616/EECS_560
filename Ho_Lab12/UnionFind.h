/* -----------------------------------------------------------------------------
 * File Name: UnionFind.h
 * Author:  Tsung Yu Ho
 * Assignment:  [EECS_560] Lab12
 * Date: 05/03/2019
 ---------------------------------------------------------------------------- */
#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind
{

private:
	int *parent;
	int *sz;
	int count;

public:
	UnionFind(int n);
	~UnionFind();
	int find(int p);
	bool isConnected(int p,int q);
	void unionElements(int p,int q);
};
#endif
