//============================================================================
// Name        : code.cpp
// Author      : vlade087
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<sstream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#include <complex>
#include <numeric>
#include<list>
#include<deque>
#include <stdlib.h>
#define printnVector(R) cout<<R.size()<<endl;for(int i =0;i<R.size();i++) cout<<R[i]<<" ";
#define mod 1000000007
#define inf 200000000000000L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 10005
#define EPS 1e-9
#define par pair<int,int>
using namespace std;
int n,m,k,tt,d,A[maxn],X[maxn],q[maxn],x,y;
vector<int> M[1005];
void dfs(int node,int last)
{
	X[node]=1;
	for(int i = 0; i < M[node].size();i++)
		if(last!=M[node][i])
		{
			dfs(M[node][i],node);
			X[node]+=X[M[node][i]];
		}
}
int calc(int node,int fath)
{
	queue<int> q;
	int s = 0;
	q.push(node);
	q.push(fath);
	int nn , f ,ss;
	vector<pair<int,int> > V;
	while(q.size())
	{
		nn = q.front();q.pop();
		f = q.front();q.pop();
		V.clear();
		for(int i = 0; i < M[nn].size();i++)
			if(M[nn][i]!=f)
			{
				V.pb(mp(X[M[nn][i]] , M[nn][i]));
			}
		ss = V.size();
		if(ss == 0) continue;
		if(ss == 1)
		{
			s+=V[0].first;
		}else if(ss == 2)
		{
			q.push(V[0].second);
			q.push(nn);
			q.push(V[1].second);
			q.push(nn);
		}else
		{
			sort(V.begin(),V.end());
			q.push(V[ss-1].second);
			q.push(nn);
			q.push(V[ss-2].second);
			q.push(nn);
			for(int j = ss-3;j>=0;j--) s+=V[j].first;
		}
	}
	return s;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>tt;
	for(int w=1;w<=tt;w++)
	{
		for(int i = 0; i < 1005;i++) M[i].clear();
		cin>>n;
		for(int i = 1;i<n;i++)
		{
			cin>>x>>y;
			M[x].pb(y);
			M[y].pb(x);
		}
		int res = -1;int aux;
		for(int i = 1; i<= n;i++)
		{
			dfs(i,-1);
			aux = calc(i,-1);
			if(res == -1 || aux < res)
			{
				res = aux;
			}
		}
		printf("Case #%d: %d\n",w,res);
	}
	return 0;
}
