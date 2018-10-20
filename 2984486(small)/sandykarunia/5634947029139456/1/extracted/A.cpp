#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <bitset>
#include <list>

#define EPS 1e-11
#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define swap(a,b) a=a^b, b=a^b, a=a^b;
#define OPENR(a) freopen(a,"r",stdin)
#define OPENW(a) freopen(a,"w",stdout)

int x4[4] = { 0, 0,-1, 1};
int y4[4] = {-1, 1, 0, 0};
int x8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
int xhorse[8] = {1,2,1,2,-1,-2,-1,-2};
int yhorse[8] = {2,1,-2,-1,2,1,-2,-1};

using namespace std;

#define MAXN 155

int t,n,l;
vector<string> device;
vector<string> outlet;
set<int> ans[MAXN];
int minim;

void dfs(int curChar,int val,bool balik)
{
	if (val>=minim) return;
	
	if (curChar>=l) minim = min(minim,val);
	else
	{/*
		printf("curChar:%d, val:%d, balik:%d\n",curChar,val,balik);
		for (int i=0;i<n;i++)
		{
			printf("ans[%d] (%s):",i,outlet[i].c_str());
			for (set<int>::iterator it=ans[i].begin();it!=ans[i].end();it++)
			{
				printf(" %d",*it);
			}
			printf("\n");
		}*/
		
		bool valid = true;
		set<int> e[n];
		int cur;
		for (int i=0;i<n;i++)
		{
			for (set<int>::iterator j=ans[i].begin();j!=ans[i].end();j++)
			{
				cur = *j;
				
				//balik = false
				if (!balik)
				{
					if (device[cur][curChar]!=outlet[i][curChar]) e[i].insert(cur);
				}
				else //balik = true
				{
					if (device[cur][curChar]==outlet[i][curChar]) e[i].insert(cur);
				}
			}
		}
		
		//hapus
		for (int i=0;i<n;i++)
		{
			//hapus
	//		printf("e[%d]:",i);
			for (set<int>::iterator it=e[i].begin();it!=e[i].end();it++)
			{
	//			printf(" %d",*it);
				ans[i].erase(*it);
				if (ans[i].empty()) valid = false;
			}
	//		printf("\n");
		}
		
	//	system("pause");
		
		if (valid)
		{
			dfs(curChar+1,val,false);
			dfs(curChar+1,val+1,true);
		}
		
		for (int i=0;i<n;i++)
		{
			//balikin
			for (set<int>::iterator it=e[i].begin();it!=e[i].end();it++)
			{
				ans[i].insert(*it);
			}
		}
	}
}

int main()
{
	OPENR("A-large.in");
	OPENW("A-large.out");
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		minim = INF;
		outlet.clear();
		device.clear();
		for (int i=0;i<MAXN;i++) ans[i].clear();
		scanf("%d %d",&n,&l);
		for (int i=0;i<n;i++)
		{
			string s;
			cin >> s;
			outlet.PB(s);
		}
		
		for (int i=0;i<n;i++)
		{
			string s;
			cin >> s;
			device.PB(s);
		}
		
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) ans[i].insert(j);
		
		dfs(0,0,false);
		dfs(0,1,true);
		
		if (minim==INF) printf("Case #%d: NOT POSSIBLE\n",tc);
		else printf("Case #%d: %d\n",tc,minim);
	}
	
 	return 0;
}



