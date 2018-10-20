/*
 * B.cpp
 *
 *  Created on: 2014-4-26
 *      Author: bjfudq
 */
#include <functional>
#include <algorithm>
#include <iostream>
//#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define MEM(a) (memset((a),0,sizeof(a)))
#define LEN(a) (int)strlen((a))
#define fr(a) for(int i=0;i<(a);i++)
#define sf(a) scanf("%d",&(a))
#define sf64(a) scanf("%I64d",&(a))
#define sff(a) scanf("%lf",&(a))
#define sfs(a) scanf("%s",(a))
#define sf2(a,b) scanf("%d%d",&(a),&(b))
#define sf2s(a,b) scanf("%s%s",(a),(b));
#define sf2f(a,b) scanf("%lf%lf",&(a),&(b))
#define sf264(a,b) scanf("%I64d%I64d",&(a),&(b))
#define pf(a) printf("%d\n",(a))
#define pfc(a) printf("%c",(a));
#define pf64(a) printf("%I64d\n",(a))
#define pff(a) printf("%lf\n",(a))
#define pfs(a) printf("%s\n",(a))
#define pf2(a,b) printf("%d %d\n",(a),(b))
#define pf2s(a,b) printf("%s%s\n",(a),(b));
#define pf2f(a,b) printf("%lf %lf\n",(a),(b))
#define pf264(a,b) printf("%I64d %I64d\n",(a),(b))
#define pfn printf("\n")
#define LL unsigned long long

const int N=2010;
const int M=1000010;
const int MOD=1000000007;
const int INF=0x7fffffff;
const int dir4[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int dir8[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{1,-1},{-1,-1},{1,1}};
const double eps=1e-16;
const double PI=acos(-1.0);

inline int sign(double x){return (x>eps)-(x<-eps);}
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
/*************************/

struct edge
{
	int u,v;
	int next;
}e[N*2];
int used[N], en, head[N];
int num[N];
int degree[N];
int dp[N];
int n,cas;
void addedge(int u, int v)
{
	e[en].u = u;
	e[en].v = v;
	e[en].next = head[u];
	head[u] = en++;
	e[en].u = v;
	e[en].v = u;
	e[en].next = head[v];
	head[v] = en++;
}

int dfs(int s)
{
	used[s]=1;
	int dpt=0;
	vector<int> tsort;
	for(int i=head[s];i!=-1;i=e[i].next)
	{
		int v=e[i].v;
		if(used[v]==1)continue;
		dfs(v);
		num[s]+=num[v]+1;
		tsort.push_back((num[v]+1)-dp[v]);
		degree[s]++;
		dpt+=dp[v];
	}
	if(degree[s]==0)
	{
		dp[s]=0;
		num[s]=0;
		return 0;
	}
	if(degree[s]==2)
	{
		dp[s]=dpt;
		return 0;
	}
	if(degree[s]==1)
	{
		dp[s]=num[s];
		return 0;
	}
	sort(tsort.begin(),tsort.end());
	dp[s]=num[s]-tsort[tsort.size()-1]-tsort[tsort.size()-2];
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
#endif
	int T;
    sf(T);
	while (T--)
	{
		sf(n);
		MEM(degree);
		en=0;
		memset(head,-1,sizeof(head));
		for(int i=0;i<n-1;i++)
		{
			int x,y;
			sf2(x,y);
			addedge(x,y);
		}
		int ans=INF;
		for(int i=1;i<=n;i++)
		{
			MEM(used);MEM(degree);MEM(dp);MEM(num);
			dfs(i);
			int temp=dp[i];
			if(ans>temp)ans=temp;
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
    return 0;
}

