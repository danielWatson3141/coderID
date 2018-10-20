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

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>tt;
	for(int w=1;w<=tt;w++)
	{
		cin>>n;
		for(int i = 0;i<n;i++)
		{
			cin>>A[i];
			X[A[i]]=i;
			q[i] = i;
		}
		printf("Case #%d: ",w);
		bool ok;
		bool mm = 0;
		for(int i = 0; i < n-1;i++)
		{
			bool ok = false;
			for(int j = i+1;j<n;j++)
				if(A[i] == q[j])
				{
					swap(q[i],q[j]);
					ok = true;
				}
			if(!ok)
			{
				printf("BAD\n");
				mm = 1;
				break;
			}
		}
		if(mm == 0) printf("GOOD\n");
	}
	return 0;
}

