#include <algorithm>
#include <numeric>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(a-1); k >= (b); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

int popcount(LL a)
{
	int res= 0;
	while(a)
	{
		a&=(a-1);
		++res;
	}
	return res;
}

int N;
vector<vector<int> > neigh;
map<pair<int,int>, int > bina; 
map<pair<int,int>, int > full; 


pair<int,int> calc(int node, int from)
{
	if(!bina.count(make_pair(node,from)))
	{
		if(neigh[node].size()==1)
		{
			bina[make_pair(node,from)]=0;
			full[make_pair(node,from)]=1;
			return make_pair(0,1);
		}
		if (neigh[node].size()==2)
		{
			int other;
			REP(i,neigh[node].size())
			{
				if(neigh[node][i]!=from)
					other = neigh[node][i];
			}
			pair<int,int> tmp = calc(other,node);
			bina[make_pair(node,from)]=tmp.second;
			full[make_pair(node,from)]=tmp.second+1;
			return make_pair(tmp.second,tmp.second+1);
		}
		//>2
		int mx1=0,mx2=0, fu=0,bi=0;
		int u1=0,u2=0;
		REP(i,neigh[node].size())
		{
			if(neigh[node][i]!=from)
			{
				int other = neigh[node][i];
				pair<int,int> tmp = calc(other,node);
				int dif = tmp.second-tmp.first;
				fu += tmp.second;
				if(mx2<dif)
				{
					bi += mx2;
					bi += tmp.first;
					mx2 = dif;
					u2 = dif;
					if(mx1<mx2)
					{
						swap(mx1,mx2);
						swap(u1,u2);
					}
				}
				else
				{
					bi += tmp.second;
				}
			}
		}
		bina[make_pair(node,from)]=bi;
		full[make_pair(node,from)]=fu+1;
		return make_pair(bi,fu+1);
	}
	return make_pair(bina[make_pair(node,from)],full[make_pair(node,from)]);
}



int main()
{
#ifdef HOME 
	freopen("B-large.in","rb",stdin);
	freopen("B-large.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	FOR(tc,1,T+1)
	{
		scanf("%d",&N);
		neigh.clear();
		bina.clear();
		full.clear();
		neigh.resize(N);
		vector<int> cc(N);
		REP(i,N-1)
		{
			int A, B;
			scanf("%d %d",&A,&B);
			--A;--B;
			neigh[A].push_back(B);
			neigh[B].push_back(A);
		}
		int ans = N-1;
		REP(i,N)
		{//if root == i
			int t;
			if(neigh[i].size()==1)
			{
				t=N-1;
			}
			else if(neigh[i].size()==2)
			{
				t = calc(neigh[i][0],i).first+calc(neigh[i][1],i).first;
			}
			else
			{
				t = calc(i,-1).first;
			}
			ans = min(ans,t);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}