// A.cpp : Defines the entry point for the console application.
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

ifstream in("A-large.in");
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

map<string,int> sortedDev;
vector<string> devices;
vector<string> outlets;
vector<string> tmpOutlets;
vector<bool> a;
int N,L;

bool Check()
{
	map<string,int> disponibles;
	REP(i,N)
		disponibles[tmpOutlets[i]]++;
	return disponibles == sortedDev;
}
void Solve()
{
	///Matcheo el device 0 con todos los outlets
	string dev0 = devices[0];
	int bestCount = 100000;
	REP(i,N)
	{
		tmpOutlets = outlets;
		//0 con i
		vector<bool> changes(L);
		int scount = 0;
		REP(j,L)
		{
			changes[j] = (dev0[j] != outlets[i][j]);
			if(changes[j])
				++scount;
		}
		if(scount < bestCount)
		{
			REP(k,N)
			{
				REP(j,L)
				{
					if(changes[j])
					{
						if(tmpOutlets[k][j] == '0')
							tmpOutlets[k][j] = '1';
						else
							tmpOutlets[k][j] = '0';
					}

				}
			}
			if(Check())
				bestCount = scount;
		}
	}
	if(bestCount == 100000)
		out << "NOT POSSIBLE";
	else
		out << bestCount;
	//	out << n;
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
		in >> N >> L;
		devices.resize(N);
		outlets.resize(N);
		REP(i,N)
		{
			in >> outlets[i];
		}
		sortedDev.clear();
		REP(i,N)
		{
			in >> devices[i];
			sortedDev[devices[i]]++;
		}

		Solve();
		out << endl;
	}	return 0;
}

