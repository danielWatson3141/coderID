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
int n,m,k,tt,d,A[maxn],X[maxn],q[maxn];
int use[2000];
vector<int> V;
int calc(string c)
{
	int r = 0;
	int j = 0;
	for(int i = c.length()-1;i>=0;i--,j++)
	{
		if(c[i] == '1')
		{
			r |= (1<<j);
		}
	}
	return r;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>tt;
	string cad;
	for(int w=1;w<=tt;w++)
	{
		cin>>n>>m;
		mset(use,0,sz(use));
		for(int i = 0; i < n;i++)
		{
			cin>>cad;
			A[i] = calc(cad);
		}
		V.clear();
		for(int i = 0; i < n;i++)
		{
			cin>>cad;
			V.pb(calc(cad));
		}
		sort(V.begin(),V.end());
		int res = -1;
		for(int mask=0;mask<(1<<m);mask++)
		{
			vector<int> M;
			M.clear();
			for(int i = 0; i < n;i++)
				M.pb(A[i] ^ mask);
			sort(M.begin(),M.end());
			if(M == V)
			{
				if(res == -1 || res > countbits(mask))
				{
					res = countbits(mask);
				}
			}
		}
		printf("Case #%d: ",w);
		if(res == -1)
		{
			printf("NOT POSSIBLE\n");
		}else
			printf("%d\n",res);
	}
	return 0;
}

