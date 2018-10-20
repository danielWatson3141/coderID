/*
 * A.cpp
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

//const int N=100010;
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

struct Node{
	char str[12];
}node1[12],node2[12],node3[12];

int N,L;

bool cmp(Node a,Node b)
{
	if(strcmp(a.str,b.str) < 0)
		return true;
	return false;
}

int jud()
{
	sort(node3,node3+N,cmp);
	for(int i=0;i<N;i++)
		if(strcmp(node3[i].str,node2[i].str) != 0)
			return 0;
	return 1;
}

int deal(int a)
{
	for(int i=0;i<N;i++)
		strcpy(node3[i].str,node1[i].str);
	int t=0,s=0;
	while(a)
	{
		if(a & 1)
		{
			for(int i=0;i<N;i++)
				node3[i].str[t]=1-(node3[i].str[t]-'0')+'0';
			s++;
		}
		t++;
		a/=2;
	}
	if(jud())
		return s;
	return INF;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt", "r", stdin);
//    freopen("testout.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	sf2(N,L);
    	fr(N) sfs(node1[i].str);
    	fr(N) sfs(node2[i].str);
    	sort(node2,node2+N,cmp);
    	int tot=1<<L,ans=INF;
    	for(int i=0;i<tot;i++)
    		ans=min(ans,deal(i));
    	if(ans == INF) pfs("NOT POSSIBLE");
    	else pf(ans);
    }
    return 0;
}

