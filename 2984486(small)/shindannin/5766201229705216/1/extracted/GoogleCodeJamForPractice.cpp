// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG (-1)
#define BIG (987654321)

#if 1 // B

#if 1

vector <bool> sVisited;

// used, deleted;
pair <ll, ll> dfs(const vector <vector <int> >& graph, int N, int now)
{
	sVisited[now]=true;

	const int C = SZ(graph[now]);
	vector <ll> used(N);
	vector <ll> deleted(N);

	bool lastLeaf = true;
	for(int i=0;i<C;++i)
	{
		const int next = graph[now][i];
		if(!sVisited[next])
		{
			pair <ll, ll> p = dfs(graph,N,next);
			used[next]=p.first;
			deleted[next]=p.second;
			lastLeaf = false;
		}
	}

	pair <ll, ll> ret;
	if(lastLeaf)
	{
		ret = make_pair(0,1);
	}
	else
	{
		ll totalDeleted = 0;
		for (int i = 0; i < N; ++i)
		{
			totalDeleted += deleted[i];
		}

		ret.first = totalDeleted;
		ret.second = totalDeleted+1;

		for(int i=0;i<C;++i)
		{
			for(int k=i+1;k<C;++k)
			{
				const int nexti = graph[now][i];
				const int nextk = graph[now][k];
				if(!sVisited[nexti] && !sVisited[nextk])
				{
					amin(ret.first, used[nexti]+used[nextk]+totalDeleted-deleted[nexti]-deleted[nextk]);
				}
			}
		}

	}


	sVisited[now]=false;

//	fprintf(stderr,"** now=%d use=%d del=%d\n",now,ret.first,ret.second);

	return ret;
}

#else

vector <bool> sVisited;
bool sDame;

void dfs(const vector <vector <int> >& graph, int N, int now)
{
	if(sDame) return;

	sVisited[now]=true;

	int numIttenai = 0;


	for (int i = 0; i < SZ(graph[now]); ++i)
	{
		int next = graph[now][i];
		if(sVisited[next]==false)
		{
			dfs(graph, N, next);
			numIttenai++;
		}
	}

	if(numIttenai==0 || numIttenai==2)
	{
	}
	else
	{
		sDame = true;
	}
}

bool isBinaryTree(const vector <vector <int> >& graph, int N, int root, ll deleted)
{
	sVisited.clear();
	sVisited.resize(N);
	sDame = false;

	dfs(graph,N,root);

	if(sDame)
	{
		return false;
	}

	for (int i = 0; i < N; ++i)
	{
		if(!sVisited[i] && !(deleted & (1LL<<i)))
		{
			return false;
		}
	}

	return true;
}
#endif

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);


	int T;
	scanf("%d",&T);

	for (int testcase = 1; testcase<=T; ++testcase)
	{
		int N;
		scanf("%d " ,&N);

		vector <vector <int> > baseGraph(N);

		for (int i = 0; i < N-1; ++i)
		{
			int from,to;
			scanf("%d %d" ,&from,&to);
			
			from--;
			to--;

			baseGraph[from].push_back(to);
			baseGraph[to].push_back(from);
		}

		ll best = (ll)BIG*BIG;

		for (int i = 0; i < N; ++i)
		{
			sVisited.clear();
			sVisited.resize(N);
			pair <ll, ll> ret = dfs(baseGraph, N, i);
//			fprintf(stderr,"** root=%d use=%lld del=%lld\n",i,ret.first,ret.second);
			amin(best,ret.first);
			amin(best,ret.second);
		}

		

#if 0
		for (ll i = 0; i < (1LL<<(N)); ++i)
		{
			vector <vector <int> > graph(baseGraph);

			int numDelete = 0;
			for (ll k = 0; k < N; ++k)
			{
				if(i&(1LL<<(k)))
				{
					numDelete++;

					graph[k].clear();

					for (int a = 0; a < N; ++a)
					{
						for (int b = 0; b < SZ(graph[a]); ++b)
						{
							if(graph[a][b]==k)
							{
								graph[a].erase(graph[a].begin()+b);
								break;
							}
						}
					}
				}
			}

			for (int k = 0; k < N; ++k)
			{
				if(isBinaryTree(graph, N, k, i))
				{
					amin(best,numDelete);
				}
			}
		}
#endif

		{
			fprintf(stderr,"Case #%d: %lld\n",testcase,best);
			printf("Case #%d: %lld\n",testcase,best);
		}

	}

	return 0;
}


#else

void readData(vector <ll>& container, int N, int L)
{
	for (int i = 0; i < N; ++i)
	{
		char str[10000];
		scanf("%s",str);
		for (int k = 0; k < L; ++k)
		{
			if(str[k]=='1')
			{
				container[i] |= 1LL << k;
			}
		}
	}
}

void MyMethodSmall( int L, vector<ll> outletBase, vector<ll> shotaBase, int N, int& best )
{
	for (int i = 0; i < (1LL<<(L)); ++i)
	{
		vector <ll> outlet(outletBase);
		vector <ll> shota(shotaBase);

		int numPush = 0;
		for (int k = 0; k < L; ++k)
		{
			if(i&(1LL<<(k)))
			{
				numPush++;
				for (int x = 0; x < N; ++x)
				{
					outlet[x] ^= (1LL<<(k));
				}
			}
		}

		set <ll> outletset, shotaset;

		for (int x = 0; x < N; ++x)
		{
			outletset.insert(outlet[x]);
			shotaset.insert(shota[x]);
		}

		if(outletset==shotaset)
		{
			amin(best, numPush);
		}
	}
}



int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);


	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 int N,L;
		 scanf("%d %d" ,&N, &L);

		 vector <ll> outletBase(N);
		 vector <ll> shotaBase(N);
		
		 readData(outletBase, N, L);
		 readData(shotaBase, N, L);

		 {
//			 int bestSmall = BIG;
//			 MyMethodSmall(L, outletBase, shotaBase, N, bestSmall);
		 }


		 int best = BIG;
		 for (int shotaID = 0; shotaID < N; ++shotaID)
		 {
			 vector <ll> outlet(outletBase);
			 vector <ll> shota(shotaBase);

			 ll push = outlet[0] ^ shota[shotaID];
			 int numPush = 0;
			 {
				 ll tmp = push;
				 while(tmp) {
					 tmp = tmp & (tmp-1);
					 numPush++;
				 }
			 }

			 for (int x = 0; x < N; ++x)
			 {
				 outlet[x] ^= push;
			 }


			 set <ll> outletset, shotaset;

			 for (int x = 0; x < N; ++x)
			 {
				 outletset.insert(outlet[x]);
				 shotaset.insert(shota[x]);
			 }

			 if(outletset==shotaset)
			 {
				 amin(best, numPush);
			 }
		 }




		 if(best==BIG)
		 {
			 fprintf(stderr,"Case #%d: NOT POSSIBLE\n",testcase);
			 printf("Case #%d: NOT POSSIBLE\n",testcase);
		 }
		 else
		 {
			 fprintf(stderr,"Case #%d: %d\n",testcase,best);
			 printf("Case #%d: %d\n",testcase,best);
		 }

	 }

	 return 0;
}

#endif