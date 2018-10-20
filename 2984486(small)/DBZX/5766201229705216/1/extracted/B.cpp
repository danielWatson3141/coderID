// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cassert>
#include <math.h>
//http://www.ttmath.org/
#include "ttmath\ttmath.h"

using namespace std;

ifstream in("B-large.in");
ofstream out("out.txt");
///LLONG_MAX,INT_MA
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )
#define ramfor(Iterator, Container) for ( auto Iterator = Container.rbegin(); (Iterator) != Container.rend(); ++(Iterator) )
template<class C, class E> inline bool contains(const C& container, const E& element){	return container.find(element) != container.end() ;}

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo
///typedef ttmath::Int<10> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

///typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF LLONG_MAX
int N;
map<int,set<int>> edges;
struct Nodo;
Nodo *pArbol;
struct Nodo
{
	Nodo():parent(-1),bestNodeCount(0),totalChilds(0){}
	~Nodo(){}
	void Visit(int index)
	{
		set<int> &rel = edges[index];
		///best,childNode
		totalChilds = 0;
		amfor(it,rel)
		{
			int child = *it;
			if(child != parent)
			{
				childs.push_back(child);
				pArbol[child].parent = index;
				pArbol[child].Visit(child);
				totalChilds += pArbol[child].totalChilds+1;
			}
		}
		if(childs.empty())
			bestNodeCount = 0;
		else if(childs.size() == 1)
		{
			bestNodeCount = pArbol[childs[0]].totalChilds+1;
		}
		else
		{
			bestNodeCount  = N;
			FOR(i,0,childs.size()-2)
			{
				FOR(j,i+1,childs.size()-1)
				{
					///No desturyo esos arboles
					int destruyo = totalChilds - pArbol[childs[i]].totalChilds - pArbol[childs[j]].totalChilds-2;
					destruyo += pArbol[childs[i]].bestNodeCount + pArbol[childs[j]].bestNodeCount;
//					destruyo += childs.size()-2; 
					assert(destruyo >= 0);
					checkmin(bestNodeCount,destruyo);
				}
			}

		}

	}
	int parent;
	int bestNodeCount;
	int totalChilds;
	vector<int> childs;
};
/*
int BFS(int r)
{
	vector<bool> visited(N,false);
	queue<int> nodos;
	nodos.push(r);
	visited[r] = true;
	while(!nodos.empty())
	{
		int n = nodos.front();
		nodos.pop();
		amfor(it,rel)
		{
			int child = *it;
			if(!visited[child])
			{
				nodos.push(child);
				label[i] = l;
				++pint;

			}
		}
		REP(i,N)
		{
			if(label[i] == -1 && graph[i][n] != INF)
			{
				nodos.push(i);
				label[i] = l;
				++pint;
			}
		}
	}
	return pint;
}*/

Nodo arbol[1010];
int Test(int r)
{
	REP(i,N)
	{
		arbol[i] = Nodo();
	}
	pArbol = &arbol[0];
	pArbol[r].Visit(r);
	return pArbol[r].bestNodeCount;
}

void Solve()
{
	int best = N;
	//	out << n;
	REP(iR,N)
	{
		int t = Test(iR);
		checkmin(best,t);
	}
	assert(best < N);
	out << best;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	out << std::setprecision(15);
	out << std::fixed;

	REP(c,ccc)
	{
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		in >> N;
		edges.clear();
		REP(i,N-1)
		{
			int a,b;
			in >> a >> b;
			--a;
			--b;
			edges[a].insert(b);
			edges[b].insert(a);
		}
		//if(c == 1)
			Solve();
		out << endl;
	}	return 0;
}

