#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>

#define SQR(_x) ((_x)*(_x))
//#define REP(_i,_n) for(int _i = 0; _i < (int)(_n); _i++)
//#define FOR(_i,_a,_b) for(int _i = (int)(_a); _i <= (int)(_b); _i++)
//#define BCK(_i,_a,_b) for(int _i = (int)(_a); _i >= (int)(_b); _i--)
#define NL printf("\n")
#define LL long long
#define INF 1000000000

using namespace std;

vector<int> v[1010];
int chl[1010]={};
int del[1010]={};
int cnt = 0;
int minn = INF;

void tra(int c,int p)
{
	int sz = v[c].size();
	int cnt_c = 0;
	for(int i = 0; i < sz; i++)
	{
		if(v[c][i]!=p)
		{
			tra(v[c][i],c);
			chl[c]+=chl[v[c][i]]+1;
			cnt_c++;
		}
	}
	if(cnt_c==0)
		return ;
	else if(cnt_c==1)
	{
		for(int i = 0; i < sz; i++)
		{
			if(v[c][i]!=p)
			{
				del[c]+=chl[v[c][i]]+1;
			}
		}
	}
	else
	{
		for(int i = 0; i < sz; i++)
		{
			if(v[c][i]!=p)
			{
				del[c]+=del[v[c][i]]+1;
			}
		}
		del[c]-=2;
	}
}

int main()
{
	int n,t;
	int x,y;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		cin >> n;
		for(int i = 0; i < n-1; i++)
		{
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		minn = INF;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < n+1; j++)
			{
				del[j]=0;
				chl[j]=0;
			}
			tra(i,0);
			cnt = del[i];
			minn = min(minn,cnt);
		}
		for(int i = 0; i < n+1; i++)
		{
			v[i].clear();
		}
		cout << "Case #" << cs << ": " << minn << endl;
	}
	return 0;
}